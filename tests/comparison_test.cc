#include <gtest/gtest.h>

#include "int2025_t.h"

TEST(Ordering, NegativeValuesHaveCorrectOrder) {
  const int2025_t minus_two = from_int(-2);
  const int2025_t minus_one = from_int(-1);

  EXPECT_TRUE(minus_two < minus_one);
  EXPECT_TRUE(minus_two <= minus_one);
  EXPECT_FALSE(minus_two > minus_one);
  EXPECT_FALSE(minus_two >= minus_one);
}

TEST(Ordering, ValuesAcrossZeroHaveCorrectOrder) {
  const int2025_t negative = from_int(-1);
  const int2025_t zero = from_int(0);
  const int2025_t positive = from_int(1);

  EXPECT_TRUE(negative < zero);
  EXPECT_TRUE(zero < positive);
  EXPECT_TRUE(negative < positive);
}

TEST(Equality, SameSmallNumbers) {
  int2025_t a = from_int(42);
  int2025_t b = from_int(42);
  EXPECT_TRUE(a == b);
}

TEST(Equality, DifferentSmallNumbers) {
  int2025_t a = from_int(42);
  int2025_t c = from_int(43);
  EXPECT_FALSE(a == c);
}

TEST(Equality, SameLargeNumbers) {
  int2025_t d = from_string("12345678901234567890");
  int2025_t e = from_string("12345678901234567890");
  EXPECT_TRUE(d == e);
}

TEST(Equality, DifferentLargeNumbers) {
  int2025_t d = from_string("12345678901234567890");
  int2025_t f = from_string("12345678901234567891");
  EXPECT_FALSE(d == f);
}

TEST(Inequality, SameSmallNumbers) {
  int2025_t a = from_int(42);
  int2025_t b = from_int(42);
  EXPECT_FALSE(a != b);
}

TEST(Inequality, DifferentSmallNumbers) {
  int2025_t a = from_int(42);
  int2025_t c = from_int(43);
  EXPECT_TRUE(a != c);
}

TEST(Inequality, SameLargeNumbers) {
  int2025_t d = from_string("12345678901234567890");
  int2025_t e = from_string("12345678901234567890");
  EXPECT_FALSE(d != e);
}

TEST(Inequality, DifferentLargeNumbers) {
  int2025_t d = from_string("12345678901234567890");
  int2025_t f = from_string("12345678901234567891");
  EXPECT_TRUE(d != f);
}

TEST(ZeroComparison, IntAndStringZero) {
  int2025_t zero1 = from_int(0);
  int2025_t zero2 = from_string("0");
  EXPECT_TRUE(zero1 == zero2);
}

TEST(ZeroComparison, IntAndNegativeStringZero) {
  int2025_t zero1 = from_int(0);
  int2025_t zero3 = from_string("-0");
  EXPECT_TRUE(zero1 == zero3);
}

TEST(ZeroComparison, StringAndNegativeStringZero) {
  int2025_t zero2 = from_string("0");
  int2025_t zero3 = from_string("-0");
  EXPECT_TRUE(zero2 == zero3);
}

TEST(SignComparison, PositiveVsNegative) {
  int2025_t positive = from_int(42);
  int2025_t negative = from_int(-42);
  EXPECT_TRUE(positive != negative);
}

TEST(SignComparison, PositiveVsZero) {
  int2025_t positive = from_int(42);
  int2025_t zero = from_int(0);
  EXPECT_TRUE(positive != zero);
}

TEST(SignComparison, NegativeVsZero) {
  int2025_t negative = from_int(-42);
  int2025_t zero = from_int(0);
  EXPECT_TRUE(negative != zero);
}

TEST(LargeNumberComparison, SameVeryLargeNumbers) {
  int2025_t large1 = from_string("999999999999999999999999999999");
  int2025_t large2 = from_string("999999999999999999999999999999");
  EXPECT_TRUE(large1 == large2);
}

TEST(LargeNumberComparison, DifferentVeryLargeNumbers) {
  int2025_t large1 = from_string("999999999999999999999999999999");
  int2025_t large3 = from_string("999999999999999999999999999998");
  EXPECT_TRUE(large1 != large3);
}

TEST(LargeNumberComparison, DifferentVeryLargeNumbersNotEqual) {
  int2025_t large1 = from_string("999999999999999999999999999999");
  int2025_t large3 = from_string("999999999999999999999999999998");
  EXPECT_FALSE(large1 == large3);
}
