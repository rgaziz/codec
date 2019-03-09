// base64.h. Gaziz Razhapov 9/03/2019
/* ===================================================================== */
#pragma once
/* ===================================================================== */
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/algorithm/string.hpp>
#include "codec.h"
/* ========================================================================== */
class CBase64 {
 public:
  template <typename Result>
  static Result encode(const uint8_t *data, size_t data_size);

  template <typename Result>
  static Result decode(const uint8_t *data, size_t data_size);

  template <typename T>
  static inline size_t encode_size(const T &t) {
    return ((size(t) + 2) / 3 * 4);
  }

 private:
  using ToBase64 = boost::archive::iterators::base64_from_binary<
      boost::archive::iterators::transform_width<const char *, 6, 8>>;

  using FromBase64 = boost::archive::iterators::transform_width<
      boost::archive::iterators::binary_from_base64<const char *>, 8, 6>;

};

/* ========================================================================== */
template <typename Result>
Result CBase64::encode(const uint8_t *data, size_t data_size) {

  Result encoded_string(ToBase64(data), ToBase64(data + data_size));

  while (encoded_string.size() % 4) {
    encoded_string.push_back('=');
  }

  return encoded_string;
}

/* ========================================================================== */
template <typename Result>
Result CBase64::decode(const uint8_t *data, size_t data_size) {

  while (data_size and data[data_size - 1] == '=') {
    --data_size; 
  }

  return Result(FromBase64(encoded_string.data()),
                FromBase64(encoded_string.data() + encoded_string.size()));
}

/* ========================================================================== */
using base64 = Codec<CBase64>;
/* ========================================================================== */
