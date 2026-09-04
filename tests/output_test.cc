#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "int2025_t.h"

TEST(OutputStream, ExactPositiveOutput) {
  std::ostringstream stream;

  stream << from_int(42);

  EXPECT_EQ(stream.str(), "0b101010");
}

TEST(OutputStream, ExactNegativeOutput) {
  std::ostringstream stream;

  stream << from_int(-42);

  EXPECT_EQ(stream.str(), "-0b101010");
}

TEST(OutputStream, ExactZeroOutput) {
  std::ostringstream stream;

  stream << from_int(0);

  EXPECT_EQ(stream.str(), "0");
}

TEST(OutputStream, IgnoresBoolalphaFormatting) {
  std::ostringstream stream;
  stream << std::boolalpha;

  stream << from_int(5);

  EXPECT_EQ(stream.str(), "0b101");
}

TEST(OutputStream, BasicOutput) {
  int2025_t a = from_int(42);
  std::stringstream ss;
  ss << a;
  std::string result = ss.str();
  EXPECT_FALSE(result.empty());
}

TEST(OutputStream, NegativeNumberOutput) {
  int2025_t a = from_int(-42);
  std::stringstream ss;
  ss << a;
  std::string result = ss.str();
  EXPECT_FALSE(result.empty());
}

TEST(OutputStream, ZeroOutput) {
  int2025_t zero = from_int(0);
  std::stringstream ss;
  ss << zero;
  std::string result = ss.str();
  EXPECT_FALSE(result.empty());
}

TEST(OutputStream, LargeNumberOutput) {
  int2025_t large =
      from_string("12345678901234567890123456789012345678901234567890");
  std::stringstream ss;
  ss << large;
  std::string result = ss.str();
  EXPECT_FALSE(result.empty());
}

TEST(OutputStream, VeryLargeNumberOutput) {
  int2025_t very_large = from_string(
      "123456789012345678901234567890123456789012345678901234567890123456789012"
      "345678901234567890123456789012345678901234567890123456789012345678901234"
      "567890123456789012345678901234567890123456789012345678901234567890123456"
      "789012345678901234567890123456789012345678901234567890123456789012345678"
      "901234567890123456789012345678901234567890123456789012345678901234567890"
      "123456789012345678901234567890123456789012345678901234567890123456789012"
      "345678901234567890123456789012345678901234567890123456789012345678901234"
      "567890123456789012345678901234567890123456789012345678901234567890123456"
      "789012345678901234567890123456789012345678901234567890");
  std::stringstream ss;
  ss << very_large;
  std::string result = ss.str();
  EXPECT_FALSE(result.empty());
}

TEST(OutputStream, MultipleOutputToSameStream) {
  int2025_t a = from_int(123);
  int2025_t b = from_int(456);
  std::stringstream ss;
  ss << a << " " << b;
  std::string result = ss.str();
  EXPECT_FALSE(result.empty());
}

TEST(OutputStream, OutputConsistency) {
  int2025_t a = from_int(42);
  int2025_t b = from_int(42);

  std::stringstream ss1, ss2;
  ss1 << a;
  ss2 << b;

  EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(OutputStream, OutputInequalityFromInt) {
  int2025_t a = from_int(566);
  int2025_t b = from_int(239);

  std::stringstream ss1, ss2;
  ss1 << a;
  ss2 << b;
  EXPECT_FALSE(ss1.str() == ss2.str());
}

TEST(OutputStream, OutputInequalityFromString) {
  int2025_t a = from_string("5661234567890566");
  int2025_t b = from_string("5661234567890567");

  std::stringstream ss1, ss2;
  ss1 << a;
  ss2 << b;
  EXPECT_FALSE(ss1.str() == ss2.str());
}
