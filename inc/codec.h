// codec.h Gaziz Razhapov 6/12/2018
/* ========================================================================== */
#pragma once
/* ========================================================================== */
#include "base64.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
/* ========================================================================== */
template <typename CodecImpl>
class Codec : public CodecImpl {
 public:
  static std::string encode(const uint8_t *_data, size_t _data_size);
  static std::string encode(const char *_data, size_t _data_size);

  static std::string decode(const uint8_t *_data, size_t _data_size);
  static std::string decode(const char *_data, size_t _data_size);

  template <typename Result = std::string, typename T = std::vector<uint8_t>>
  static Result encode(T &_data);

  template <typename Result = std::string, typename T = std::vector<uint8_t>>
  static Result decode(T &_data);
};

/* ========================================================================== */
template <typename T>
inline size_t size(const T &t) {
  return t.size();
}

/* ========================================================================== */
inline size_t size(const uint8_t *t) {
  return strlen(reinterpret_cast<const char *>(t));
}

/* ========================================================================== */
template <typename T, size_t N>
inline constexpr size_t size(const T (&t)[N]) noexcept {
  return (void)t, N * sizeof(t[0]) - 1;
}

/* ========================================================================== */
template <typename T, size_t N>
inline const char *char_data(const T (&t)[N]) noexcept {
  return reinterpret_cast<const char *>(&(t[0]));
}

/* ========================================================================== */
template <typename T>
inline const char *char_data(const T &t) {
  return reinterpret_cast<const char *>(t.data());
}

/* ========================================================================== */
template <typename T>
inline const uint8_t *uchar_data(T &t) {
  return reinterpret_cast<const uint8_t *>(char_data(t));
}

/* ========================================================================== */
template <typename CodecImpl>
std::string Codec<CodecImpl>::encode(const uint8_t *_data, size_t _data_size) {
  return CodecImpl::template encode<std::string>(_data, _data_size);
}

/* ========================================================================== */
template <typename CodecImpl>
std::string Codec<CodecImpl>::encode(const char *_data, size_t _data_size) {
  return CodecImpl::template encode<std::string>(
      reinterpret_cast<const uint8_t *>(_data), _data_size);
}

/* ========================================================================== */
template <typename CodecImpl>
std::string Codec<CodecImpl>::decode(const uint8_t *_data, size_t _data_size) {
  return CodecImpl::template decode<std::string>(_data, _data_size);
}

/* ========================================================================== */
template <typename CodecImpl>
std::string Codec<CodecImpl>::decode(const char *_data, size_t _data_size) {
  return CodecImpl::template decode<std::string>(
      reinterpret_cast<const uint8_t *>(_data), _data_size);
}

/* ========================================================================== */
template <typename CodecImpl>
template <typename Result, typename T>
inline Result Codec<CodecImpl>::encode(T &_data) {
  return CodecImpl::template encode<Result>(uchar_data(_data), size(_data));
}

/* ========================================================================== */
template <typename CodecImpl>
template <typename Result, typename T>
inline Result Codec<CodecImpl>::decode(T &_data) {
  return CodecImpl::template decode<Result>(uchar_data(_data), size(_data));
}

/* ========================================================================== */
