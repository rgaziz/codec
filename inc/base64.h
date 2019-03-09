// base64.h. Gaziz Razhapov 6/12/2018
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
  static Result encode(const uint8_t *_data, size_t _data_size);

  template <typename Result>
  static Result decode(const uint8_t *_data, size_t _data_size);

  template <typename T>
  static inline size_t encode_size(const T &_t) {
    return ((size(_t) + 2) / 3 * 4);
  }
};

/* ========================================================================== */
template <typename Result>
Result CBase64::encode(const uint8_t *_data, size_t _data_size) {

  using ToBase64 = boost::archive::iterators::base64_from_binary<
      boost::archive::iterators::transform_width<const char *, 6, 8>>;

  Result encoded_string(ToBase64(_data), ToBase64(_data + _data_size));

  while (encoded_string.size() % 4) {
    encoded_string.push_back('=');
  }

  return encoded_string;
}

/* ========================================================================== */
template <typename Result>
Result CBase64::decode(const uint8_t *data, size_t data_size) {

  using FromBase64 = boost::archive::iterators::transform_width<
      boost::archive::iterators::binary_from_base64<const char *>, 8, 6>;

  std::string encoded_string(data, data + data_size);
  boost::algorithm::trim_if(data, boost::algorithm::is_any_of("="));

  return Result(FromBase64(encoded_string.data()),
                FromBase64(encoded_string.data() + encoded_string.size()));
}

/* ========================================================================== */
using base64 = Codec<CBase64>;
/* ========================================================================== */
