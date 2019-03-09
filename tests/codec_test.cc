// Test base64.h Gaziz Razhapov 9/03/2019
/* ========================================================================== */
#include <vector>
#include <string>
#include <iostream>
#include "inc/base64.h"
#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <benchmark/benchmark.h>
#include <rapidcheck/rapidcheck.h>
/* ========================================================================== */
TEST(base64, decode_vector) {
  const std::vector<char> input_1{'T', 'Q', '=', '='};
  const std::vector<char> input_2{'T', 'W', 'F', 'u'};
  const std::vector<char> input_3{'a', 'G', 'V', 's', 'b', 'G', '8', 'g',
                                  'd', '2', '9', 'y', 'b', 'G', 'Q', '='};

  const std::string output_1 = "M";
  const std::string output_2 = "Man";
  const std::string output_3 = "hello world";

  ASSERT_STREQ(output_1.c_str(), base64::decode(input_1).c_str());
  ASSERT_EQ(base64::decode(input_1).size(), output_1.size());

  ASSERT_STREQ(output_2.c_str(), base64::decode(input_2).c_str());
  ASSERT_EQ(base64::decode(input_2).size(), output_2.size());

  ASSERT_STREQ(output_3.c_str(), base64::decode(input_3).c_str());
  ASSERT_EQ(base64::decode(input_3).size(), output_3.size());
}

/* ========================================================================== */
TEST(base64, decode_string) {
  const std::string input_1{"TQ=="};
  const std::string input_2{"TWFu"};
  const std::string input_3{"aGVsbG8\r\ngd29ybGQ="};

  const std::string output_1 = "M";
  const std::string output_2 = "Man";
  const std::string output_3 = "hello world";

  ASSERT_STREQ(output_1.c_str(), base64::decode(input_1).c_str());
  ASSERT_EQ(base64::decode(input_1).size(), output_1.size());

  ASSERT_STREQ(output_2.c_str(), base64::decode(input_2).c_str());
  ASSERT_EQ(base64::decode(input_2).size(), output_2.size());

  ASSERT_STREQ(output_3.c_str(), base64::decode(input_3).c_str());
  ASSERT_EQ(base64::decode(input_3).size(), output_3.size());
}

/* ========================================================================== */
TEST(base64, decode_char_array) {
  const char input_1[] = "TQ==";
  const char input_2[] = "TWFu";
  const char input_3[] = "aGVsbG8\r\ngd29ybGQ=";

  const std::string output_1 = "M";
  const std::string output_2 = "Man";
  const std::string output_3 = "hello world";

  ASSERT_STREQ(output_1.c_str(), base64::decode(input_1).c_str());
  ASSERT_EQ(base64::decode(input_1).size(), output_1.size());

  ASSERT_STREQ(output_2.c_str(), base64::decode(input_2).c_str());
  ASSERT_EQ(base64::decode(input_2).size(), output_2.size());

  ASSERT_STREQ(output_3.c_str(), base64::decode(input_3).c_str());
  ASSERT_EQ(base64::decode(input_3).size(), output_3.size());
}

/* ========================================================================== */
TEST(base64, decode_char_pointer) {
  const char* input_1 = "TQ==";
  const char* input_2 = "TWFu";
  const char* input_3 = "aGVsbG8\r\ngd29ybGQ=";

  const std::string output_1 = "M";
  const std::string output_2 = "Man";
  const std::string output_3 = "hello world";

  ASSERT_STREQ(output_1.c_str(),
               base64::decode(input_1, strlen(input_1)).c_str());
  ASSERT_EQ(output_1.size(), base64::decode(input_1, strlen(input_1)).size());

  ASSERT_STREQ(output_2.c_str(),
               base64::decode(input_2, strlen(input_2)).c_str());
  ASSERT_EQ(output_2.size(), base64::decode(input_2, strlen(input_2)).size());

  ASSERT_STREQ(output_3.c_str(),
               base64::decode(input_3, strlen(input_3)).c_str());
  ASSERT_EQ(output_3.size(), base64::decode(input_3, strlen(input_3)).size());
}

/* ========================================================================== */
static void BM_base64_decode(benchmark::State& state) {
  for (auto _ : state) {
    base64::decode(
        "L2hvbWUvdnpheXRzZXYvd29yay9yaGVsL2dhdGUvYnJhbmNoZXMvR0FURS00MDc1LWZjZ2"
        "ktc3Rh\r\n"
        "bmRhbG9uZS1vcHRpb24vc21zX2dhdGUvZmNnaV9zZW5kc2F5L3NyYy9zZW5kc2F5X21haW"
        "4uY3Bw\r\n"
        "OjMxNjozNzogZXJyb3I6IGV4cGVjdGVkIHR5cGUtc3BlY2lmaWVyIGJlZm9yZSBDU3RyaW"
        "5nUGFp\r\n"
        "ckVsZW1lbnQK\r\n");
    base64::decode(
        "L2hvbWUvdnpheXRzZXYvd29yay9yaGVsL2dhdGUvYnJhbmNoZXMvR0FURS00MDc1LWZjZ2"
        "ktc3Rh\r\n"
        "bmRhbG9uZS1vcHRpb24vc21zX2dhdGUvZmNnaV9zZW5kc2F5L3NyYy9zZW5kc2F5X21haW"
        "4uY3Bw\r\n"
        "OjMxNjozNzogZXJyb3I6IGV4cGVjdGVkIHR5cGUtc3BlY2lmaWVyIGJlZm9yZSBDU3RyaW"
        "5nUGFp\r\n"
        "ckVsZW1lbnQxCg==\r\n");
    base64::decode(
        "L2hvbWUvdnpheXRzZXYvd29yay9yaGVsL2dhdGUvYnJhbmNoZXMvR0FURS00MDc1LWZjZ2"
        "ktc3Rh\r\n"
        "bmRhbG9uZS1vcHRpb24vc21zX2dhdGUvZmNnaV9zZW5kc2F5L3NyYy9zZW5kc2F5X21haW"
        "4uY3Bw\r\n"
        "OjMxNjozNzogZXJyb3I6IGV4cGVjdGVkIHR5cGUtc3BlY2lmaWVyIGJlZm9yZSBDU3RyaW"
        "5nUGFp\r\n"
        "ckVsZW1lbnQxMgo=\r\n");
  }
}
BENCHMARK(BM_base64_decode);

/* ========================================================================== */
TEST(base64, encode_vector) {
  const std::vector<char> input_1{'M'};
  const std::vector<char> input_2{'M', 'a', 'n'};
  const std::vector<char> input_3{'h', 'e', 'l', 'l', 'o', ' ',
                                  'w', 'o', 'r', 'l', 'd'};

  const std::string output_1 = "TQ==";
  const std::string output_2 = "TWFu";
  const std::string output_3 = "aGVsbG8gd29ybGQ=";

  ASSERT_STREQ(output_1.c_str(), base64::encode(input_1).c_str());
  ASSERT_EQ(base64::encode(input_1).size(), output_1.size());

  ASSERT_STREQ(output_2.c_str(), base64::encode(input_2).c_str());
  ASSERT_EQ(base64::encode(input_2).size(), output_2.size());

  ASSERT_STREQ(output_3.c_str(), base64::encode(input_3).c_str());
  ASSERT_EQ(base64::encode(input_3).size(), output_3.size());
}

/* ========================================================================== */
TEST(base64, encode_string) {
  const std::string input_1 = "M";
  const std::string input_2 = "Man";
  const std::string input_3 = "hello world";

  const std::string output_1 = "TQ==";
  const std::string output_2 = "TWFu";
  const std::string output_3 = "aGVsbG8gd29ybGQ=";

  ASSERT_STREQ(output_1.c_str(), base64::encode(input_1).c_str());
  ASSERT_EQ(base64::encode(input_1).size(), output_1.size());

  ASSERT_STREQ(output_2.c_str(), base64::encode(input_2).c_str());
  ASSERT_EQ(base64::encode(input_2).size(), output_2.size());

  ASSERT_STREQ(output_3.c_str(), base64::encode(input_3).c_str());
  ASSERT_EQ(base64::encode(input_3).size(), output_3.size());
}

/* ========================================================================== */
TEST(base64, encode_char_array) {
  const char input_1[] = "M";
  const char input_2[] = "Man";
  const char input_3[] = "hello world";

  const std::string output_1 = "TQ==";
  const std::string output_2 = "TWFu";
  const std::string output_3 = "aGVsbG8gd29ybGQ=";

  ASSERT_STREQ(output_1.c_str(), base64::encode(input_1).c_str());
  ASSERT_EQ(base64::encode(input_1).size(), output_1.size());

  ASSERT_STREQ(output_2.c_str(), base64::encode(input_2).c_str());
  ASSERT_EQ(base64::encode(input_2).size(), output_2.size());

  ASSERT_STREQ(output_3.c_str(), base64::encode(input_3).c_str());
  ASSERT_EQ(base64::encode(input_3).size(), output_3.size());
}

/* ========================================================================== */
TEST(base64, encode_char_pointer) {
  const char* input_1 = "M";
  const char* input_2 = "Man";
  const char* input_3 = "hello world";

  const std::string output_1 = "TQ==";
  const std::string output_2 = "TWFu";
  const std::string output_3 = "aGVsbG8gd29ybGQ=";

  ASSERT_STREQ(output_1.c_str(),
               base64::encode(input_1, strlen(input_1)).c_str());
  ASSERT_EQ(output_1.size(), base64::encode(input_1, strlen(input_1)).size());

  ASSERT_STREQ(output_2.c_str(),
               base64::encode(input_2, strlen(input_2)).c_str());
  ASSERT_EQ(output_2.size(), base64::encode(input_2, strlen(input_2)).size());

  ASSERT_STREQ(output_3.c_str(),
               base64::encode(input_3, strlen(input_3)).c_str());
  ASSERT_EQ(output_3.size(), base64::encode(input_3, strlen(input_3)).size());
}

/* ========================================================================== */
RC_GTEST_PROP(base64, encode_decode_random_data, ()) {
  auto data = *rc::gen::arbitrary<std::string>();

  auto encoded_data = base64::encode(data);
  auto decoded_data = base64::decode(encoded_data);

  RC_ASSERT(data == decoded_data);
}

/* ========================================================================== */
static void BM_base64_encode(benchmark::State& state) {
  for (auto _ : state) {
    base64::encode(
        "/home/vzaytsev/work/rhel/gate/branches/"
        "GATE-4075-fcgi-standalone-option/sms_gate/fcgi_sendsay/src/"
        "sendsay_main.cpp:316:37: error: expected type-specifier before "
        "CStringPairElement");
    base64::encode(
        "/home/vzaytsev/work/rhel/gate/branches/"
        "GATE-4075-fcgi-standalone-option/sms_gate/fcgi_sendsay/src/"
        "sendsay_main.cpp:316:37: error: expected type-specifier before "
        "CStringPairElement1");
    base64::encode(
        "/home/vzaytsev/work/rhel/gate/branches/"
        "GATE-4075-fcgi-standalone-option/sms_gate/fcgi_sendsay/src/"
        "sendsay_main.cpp:316:37: error: expected type-specifier before "
        "CStringPairElement12");
  }
}
BENCHMARK(BM_base64_encode);
/* ========================================================================== */
