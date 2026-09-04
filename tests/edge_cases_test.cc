#include <gtest/gtest.h>

#include "int2025_t.h"

namespace {

int2025_t PowerOfTwo(std::size_t exponent) {
  int2025_t result = from_int(1);
  for (std::size_t i = 0; i < exponent; ++i) {
    result = result + result;
  }
  return result;
}

}  // namespace

TEST(WrapAround, MaximumPlusOneBecomesMinimum) {
  const int2025_t minimum = PowerOfTwo(kBits);
  const int2025_t maximum = minimum - from_int(1);

  EXPECT_EQ(maximum + from_int(1), minimum);
}

TEST(WrapAround, MinimumMinusOneBecomesMaximum) {
  const int2025_t minimum = PowerOfTwo(kBits);
  const int2025_t maximum = minimum - from_int(1);

  EXPECT_EQ(minimum - from_int(1), maximum);
}

TEST(WrapAround, NegatingMinimumKeepsMinimum) {
  const int2025_t minimum = PowerOfTwo(kBits);

  EXPECT_EQ(-minimum, minimum);
}

TEST(WrapAround, MinimumDivisionWrapsCorrectly) {
  const int2025_t minimum = PowerOfTwo(kBits);

  EXPECT_EQ(minimum / from_int(1), minimum);
  EXPECT_EQ(minimum / from_int(-1), minimum);
}

TEST(IntegerLimits, MaxValue) {
  int2025_t max_int = from_int(2147483647);
  EXPECT_TRUE(max_int == from_int(2147483647));
}

TEST(IntegerLimits, MinValue) {
  int2025_t min_int = from_int(-2147483648);
  EXPECT_TRUE(min_int == from_int(-2147483648));
}

TEST(IntegerLimits, ArithmeticWithMAX) {
  int2025_t max_int = from_int(2147483647);
  int2025_t zero = from_int(0);
  int2025_t result = max_int + zero;
  EXPECT_TRUE(result == max_int);
}

TEST(IntegerLimits, ArithmeticWithMIN) {
  int2025_t min_int = from_int(-2147483648);
  int2025_t zero = from_int(0);
  int2025_t result = min_int + zero;
  EXPECT_TRUE(result == min_int);
}

TEST(PowersOfTwo, Power8) {
  int2025_t power_8 = from_int(256);
  int2025_t expected_8 = from_string("256");
  EXPECT_TRUE(power_8 == expected_8);
}

TEST(PowersOfTwo, Power16) {
  int2025_t power_16 = from_string("65536");
  int2025_t expected_16 = from_string("65536");
  EXPECT_TRUE(power_16 == expected_16);
}

TEST(PowersOfTwo, Power32) {
  int2025_t power_32 = from_string("4294967296");
  int2025_t expected_32 = from_string("4294967296");
  EXPECT_TRUE(power_32 == expected_32);
}

TEST(PowersOfTen, Power10) {
  int2025_t power_10 = from_string("10000000000");
  int2025_t expected_10 = from_string("10000000000");
  EXPECT_TRUE(power_10 == expected_10);
}

TEST(PowersOfTen, Power20) {
  int2025_t power_20 = from_string("100000000000000000000");
  int2025_t expected_20 = from_string("100000000000000000000");
  EXPECT_TRUE(power_20 == expected_20);
}

TEST(PowersOfTen, Power50) {
  int2025_t power_50 =
      from_string("100000000000000000000000000000000000000000000000000");
  int2025_t expected_50 =
      from_string("100000000000000000000000000000000000000000000000000");
  EXPECT_TRUE(power_50 == expected_50);
}

TEST(SingleDigit, Zero) {
  int2025_t num = from_int(0);
  int2025_t expected = from_int(0);
  EXPECT_TRUE(num == expected);
}

TEST(SingleDigit, One) {
  int2025_t num = from_int(1);
  int2025_t expected = from_int(1);
  EXPECT_TRUE(num == expected);
}

TEST(SingleDigit, Five) {
  int2025_t num = from_int(5);
  int2025_t expected = from_int(5);
  EXPECT_TRUE(num == expected);
}

TEST(SingleDigit, Nine) {
  int2025_t num = from_int(9);
  int2025_t expected = from_int(9);
  EXPECT_TRUE(num == expected);
}

TEST(AlternatingSign, AdditionOpposites) {
  int2025_t a = from_int(100);
  int2025_t b = from_int(-100);
  int2025_t sum = a + b;
  int2025_t zero = from_int(0);
  EXPECT_TRUE(sum == zero);
}

TEST(AlternatingSign, MultiplicationOpposites) {
  int2025_t a = from_int(100);
  int2025_t b = from_int(-100);
  int2025_t product = a * b;
  int2025_t expected_negative = from_int(-10000);
  EXPECT_TRUE(product == expected_negative);
}

TEST(RepeatedOperations, PowerOf2Through10Multiplications) {
  int2025_t result = from_int(1);
  int2025_t two = from_int(2);

  for (int i = 0; i < 10; ++i) {
    result = result * two;
  }

  int2025_t expected = from_int(1024);
  EXPECT_TRUE(result == expected);
}

TEST(ZeroOperations, DivisionZeroByNumber) {
  int2025_t zero = from_int(0);
  int2025_t any_num = from_int(12345);
  int2025_t div_result = zero / any_num;
  EXPECT_TRUE(div_result == zero);
}

TEST(ZeroOperations, MultiplicationZeroByNumber) {
  int2025_t zero = from_int(0);
  int2025_t any_num = from_int(12345);
  int2025_t mult_result = zero * any_num;
  EXPECT_TRUE(mult_result == zero);
}

TEST(StringSpecialCases, AllOnesPattern) {
  int2025_t all_ones = from_string("11111111111111111111");
  int2025_t expected_ones = from_string("11111111111111111111");
  EXPECT_TRUE(all_ones == expected_ones);
}

TEST(StringSpecialCases, AlternatingPattern) {
  int2025_t alternating = from_string("12121212121212121212");
  int2025_t expected_alt = from_string("12121212121212121212");
  EXPECT_TRUE(alternating == expected_alt);
}
