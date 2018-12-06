// main.cc Gaziz Razhapov 6/12/2018
/* ===================================================================== */
#include "inc/codec.h"
/* ===================================================================== */
int main(int argc, char **argv) {

  std::string encode_result = base64::encode("hello world");
  std::cout << "Encode result: " << encode_result.c_str() << std::endl;

  std::string decode_result = base64::decode(encode_result);
  std::cout << "Decode result: " << decode_result.c_str() << std::endl;

  return 0;
}
/* ===================================================================== */
