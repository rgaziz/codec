// Test base64.h Gaziz Razhapov 25/10/2018
/* ===================================================================== */
#include <gtest/gtest.h>
#include "inc/codec.h"
#include <vector>
#include <string>
/* ===================================================================== */
TEST(test_decoder, test_vector) {

  std::vector<char> input_1{'T', 'Q', '=', '='};
  std::vector<char> input_2{'T', 'W', 'F', 'u'};
  std::vector<char> input_3{'a', 'G', 'V', 's', 'b', 'G', '8', 'g',
                            'd', '2', '9', 'y', 'b', 'G', 'Q', '='};

  ASSERT_STREQ("M", base64::decode(input_1).c_str());
  ASSERT_TRUE(base64::decode(input_1).size() > 0);

  ASSERT_STREQ("Man", base64::decode(input_2).c_str());
  ASSERT_TRUE(base64::decode(input_2).size() > 0);

  ASSERT_STREQ("hello world", base64::decode(input_3).c_str());
  ASSERT_TRUE(base64::decode(input_3).size() > 0);
}

/* ===================================================================== */
TEST(test_decoder, test_string) {

  std::string input_1{"TQ=="};
  std::string input_2{"TWFu"};
  std::string input_3{"aGVsbG8gd29ybGQ="};

  ASSERT_STREQ("M", base64::decode(input_1).c_str());
  ASSERT_TRUE(base64::decode(input_1).size() > 0);

  ASSERT_STREQ("Man", base64::decode(input_2).c_str());
  ASSERT_TRUE(base64::decode(input_2).size() > 0);

  ASSERT_STREQ("hello world", base64::decode(input_3).c_str());
  ASSERT_TRUE(base64::decode(input_3).size() > 0);
}

/* ===================================================================== */
TEST(test_decoder, test_char_array) {

  ASSERT_STREQ("M", base64::decode("TQ==").c_str());
  ASSERT_TRUE(base64::decode("TQ==").size() > 0);

  ASSERT_STREQ("Man", base64::decode("TWFu").c_str());
  ASSERT_TRUE(base64::decode("TWFu").size() > 0);

  ASSERT_STREQ("hello world", base64::decode("aGVsbG8gd29ybGQ=").c_str());
  ASSERT_TRUE(base64::decode("aGVsbG8gd29ybGQ=").size() > 0);
}

/* ===================================================================== */
TEST(test_decoder, test_char_ptr) {

  static constexpr const char *c_ptr_1 = "TQ==";
  static constexpr const char *c_ptr_2 = "TWFu";
  static constexpr const char *c_ptr_3 = "aGVsbG8gd29ybGQ=";

  ASSERT_STREQ("M", base64::decode(c_ptr_1, strlen(c_ptr_1)).c_str());
  ASSERT_TRUE(base64::decode(c_ptr_1, strlen(c_ptr_1)).size() > 0);

  ASSERT_STREQ("Man", base64::decode(c_ptr_2, strlen(c_ptr_2)).c_str());
  ASSERT_TRUE(base64::decode(c_ptr_2, strlen(c_ptr_2)).size() > 0);

  ASSERT_STREQ("hello world", base64::decode(c_ptr_3, strlen(c_ptr_3)).c_str());
  ASSERT_TRUE(base64::decode(c_ptr_3, strlen(c_ptr_3)).size() > 0);
}

/* ===================================================================== */
TEST(test_encoder, test_vector) {

  std::vector<char> input_1{'M'};
  std::vector<char> input_2{'M', 'a', 'n'};
  std::vector<char> input_3{'h', 'e', 'l', 'l', 'o', ' ',
                            'w', 'o', 'r', 'l', 'd'};

  ASSERT_STREQ("TQ==", base64::encode(input_1).c_str());
  ASSERT_TRUE(base64::encode(input_1).size() > 0);

  ASSERT_STREQ("TWFu", base64::encode(input_2).c_str());
  ASSERT_TRUE(base64::encode(input_2).size() > 0);

  ASSERT_STREQ("aGVsbG8gd29ybGQ=", base64::encode(input_3).c_str());
  ASSERT_TRUE(base64::encode(input_3).size() > 0);
}

/* ===================================================================== */
TEST(test_encoder, test_string) {

  std::string input_1 = "M";
  std::string input_2 = "Man";
  std::string input_3 = "hello world";

  ASSERT_STREQ("TQ==", base64::encode(input_1).c_str());
  ASSERT_TRUE(base64::encode(input_1).size() > 0);

  ASSERT_STREQ("TWFu", base64::encode(input_2).c_str());
  ASSERT_TRUE(base64::encode(input_2).size() > 0);

  ASSERT_STREQ("aGVsbG8gd29ybGQ=", base64::encode(input_3).c_str());
  ASSERT_TRUE(base64::encode(input_3).size() > 0);
}

/* ===================================================================== */
TEST(test_encoder, test_char_array) {

  ASSERT_STREQ("TQ==", base64::encode("M").c_str());
  ASSERT_TRUE(base64::encode("M").size() > 0);

  ASSERT_STREQ("TWFu", base64::encode("Man").c_str());
  ASSERT_TRUE(base64::encode("Man").size() > 0);

  ASSERT_STREQ("aGVsbG8gd29ybGQ=", base64::encode("hello world").c_str());
  ASSERT_TRUE(base64::encode("hello world").size() > 0);
}

/* ===================================================================== */
TEST(test_encoder, test_char_ptr) {

  static constexpr const char *c_ptr_1 = "M";
  static constexpr const char *c_ptr_2 = "Man";
  static constexpr const char *c_ptr_3 = "hello world";

  ASSERT_STREQ("TQ==", base64::encode(c_ptr_1, strlen(c_ptr_1)).c_str());
  ASSERT_TRUE(base64::encode(c_ptr_1, strlen(c_ptr_1)).size() > 0);

  ASSERT_STREQ("TWFu", base64::encode(c_ptr_2, strlen(c_ptr_2)).c_str());
  ASSERT_TRUE(base64::encode(c_ptr_2, strlen(c_ptr_2)).size() > 0);

  ASSERT_STREQ("aGVsbG8gd29ybGQ=",
               base64::encode(c_ptr_3, strlen(c_ptr_3)).c_str());
  ASSERT_TRUE(base64::encode(c_ptr_3, strlen(c_ptr_3)).size() > 0);
}

/* ===================================================================== */
