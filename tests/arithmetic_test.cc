#include <gtest/gtest.h>

#include <string>
#include <tuple>

#include "int2025_t.h"

TEST(Addition, PositiveNumbers) {
  int2025_t a = from_int(10);
  int2025_t b = from_int(20);
  int2025_t expected = from_int(30);
  int2025_t result = a + b;
  EXPECT_TRUE(result == expected);
}

TEST(Addition, NegativeAndPositive) {
  int2025_t c = from_int(-10);
  int2025_t d = from_int(20);
  int2025_t expected = from_int(10);
  int2025_t result = c + d;
  EXPECT_TRUE(result == expected);
}

TEST(Addition, BothNegative) {
  int2025_t e = from_int(-10);
  int2025_t f = from_int(-20);
  int2025_t expected = from_int(-30);
  int2025_t result = e + f;
  EXPECT_TRUE(result == expected);
}

TEST(Addition, WithZeroLeft) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  int2025_t result = a + zero;
  EXPECT_TRUE(result == a);
}

TEST(Addition, WithZeroRight) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  int2025_t result = zero + a;
  EXPECT_TRUE(result == a);
}

TEST(Subtraction, PositiveNumbers) {
  int2025_t a = from_int(30);
  int2025_t b = from_int(20);
  int2025_t expected = from_int(10);
  int2025_t result = a - b;
  EXPECT_TRUE(result == expected);
}

TEST(Subtraction, ResultNegative) {
  int2025_t c = from_int(10);
  int2025_t d = from_int(20);
  int2025_t expected = from_int(-10);
  int2025_t result = c - d;
  EXPECT_TRUE(result == expected);
}

TEST(Subtraction, BothNegative) {
  int2025_t e = from_int(-10);
  int2025_t f = from_int(-20);
  int2025_t expected = from_int(10);
  int2025_t result = e - f;
  EXPECT_TRUE(result == expected);
}

TEST(Subtraction, MinusZero) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  int2025_t result = a - zero;
  EXPECT_TRUE(result == a);
}

TEST(Subtraction, ZeroMinus) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  int2025_t result = zero - a;
  int2025_t expected = from_int(-42);
  EXPECT_TRUE(result == expected);
}

TEST(Multiplication, PositiveNumbers) {
  int2025_t a = from_int(6);
  int2025_t b = from_int(7);
  int2025_t expected = from_int(42);
  int2025_t result = a * b;
  EXPECT_TRUE(result == expected);
}

TEST(Multiplication, NegativeAndPositive) {
  int2025_t c = from_int(-6);
  int2025_t d = from_int(7);
  int2025_t expected = from_int(-42);
  int2025_t result = c * d;
  EXPECT_TRUE(result == expected);
}

TEST(Multiplication, BothNegative) {
  int2025_t e = from_int(-6);
  int2025_t f = from_int(-7);
  int2025_t expected = from_int(42);
  int2025_t result = e * f;
  EXPECT_TRUE(result == expected);
}

TEST(Multiplication, WithZeroLeft) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  int2025_t result = a * zero;
  EXPECT_TRUE(result == zero);
}

TEST(Multiplication, WithZeroRight) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  int2025_t result = zero * a;
  EXPECT_TRUE(result == zero);
}

TEST(Multiplication, WithOneLeft) {
  int2025_t a = from_int(42);
  int2025_t one = from_int(1);
  int2025_t result = a * one;
  EXPECT_TRUE(result == a);
}

TEST(Multiplication, WithOneRight) {
  int2025_t a = from_int(42);
  int2025_t one = from_int(1);
  int2025_t result = one * a;
  EXPECT_TRUE(result == a);
}

TEST(Division, PositiveNumbers) {
  int2025_t a = from_int(42);
  int2025_t b = from_int(7);
  int2025_t expected = from_int(6);
  int2025_t result = a / b;
  EXPECT_TRUE(result == expected);
}

TEST(Division, NegativeAndPositive) {
  int2025_t c = from_int(-42);
  int2025_t d = from_int(7);
  int2025_t expected = from_int(-6);
  int2025_t result = c / d;
  EXPECT_TRUE(result == expected);
}

TEST(Division, BothNegative) {
  int2025_t e = from_int(-42);
  int2025_t f = from_int(-7);
  int2025_t expected = from_int(6);
  int2025_t result = e / f;
  EXPECT_TRUE(result == expected);
}

TEST(Division, ByOne) {
  int2025_t a = from_int(42);
  int2025_t one = from_int(1);
  int2025_t result = a / one;
  EXPECT_TRUE(result == a);
}

TEST(LargeNumbers, Addition) {
  int2025_t a = from_string("12345678901234567890");
  int2025_t b = from_string("98765432109876543210");
  int2025_t sum = a + b;
  int2025_t expected_sum = from_string("111111111011111111100");
  EXPECT_TRUE(sum == expected_sum);
}

TEST(LargeNumbers, Multiplication) {
  int2025_t product = from_string("123") * from_string("456");
  int2025_t expected_product = from_string("56088");
  EXPECT_TRUE(product == expected_product);
}

TEST(ArithmeticIdentities, AdditiveIdentityLeft) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  EXPECT_TRUE((a + zero) == a);
}

TEST(ArithmeticIdentities, AdditiveIdentityRight) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  EXPECT_TRUE((zero + a) == a);
}

TEST(ArithmeticIdentities, MultiplicativeIdentityLeft) {
  int2025_t a = from_int(42);
  int2025_t one = from_int(1);
  EXPECT_TRUE((a * one) == a);
}

TEST(ArithmeticIdentities, MultiplicativeIdentityRight) {
  int2025_t a = from_int(42);
  int2025_t one = from_int(1);
  EXPECT_TRUE((one * a) == a);
}

TEST(ArithmeticIdentities, MultiplicativeZeroLeft) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  EXPECT_TRUE((a * zero) == zero);
}

TEST(ArithmeticIdentities, MultiplicativeZeroRight) {
  int2025_t a = from_int(42);
  int2025_t zero = from_int(0);
  EXPECT_TRUE((zero * a) == zero);
}

TEST(SelfOperations, SelfSubtraction) {
  int2025_t a = from_int(42);
  int2025_t diff = a - a;
  int2025_t zero = from_int(0);
  EXPECT_TRUE(diff == zero);
}

TEST(SelfOperations, SelfDivision) {
  int2025_t a = from_int(42);
  int2025_t quotient = a / a;
  int2025_t one = from_int(1);
  EXPECT_TRUE(quotient == one);
}

class ArithmeticOperationsTestSuite
    : public ::testing::TestWithParam<
          std::tuple<std::string, std::string, std::string, std::string,
                     std::string, std::string>> {
 protected:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_P(ArithmeticOperationsTestSuite, Addition) {
  auto params = GetParam();
  std::string a_str = std::get<0>(params);
  std::string b_str = std::get<1>(params);
  std::string expected_str = std::get<2>(params);

  int2025_t a = from_string(a_str.c_str());
  int2025_t b = from_string(b_str.c_str());
  int2025_t expected = from_string(expected_str.c_str());

  EXPECT_TRUE((a + b) == expected)
      << "Сложение: " << a_str << " + " << b_str << " != " << expected_str;
}

TEST_P(ArithmeticOperationsTestSuite, Subtraction) {
  auto params = GetParam();
  std::string a_str = std::get<0>(params);
  std::string b_str = std::get<1>(params);
  std::string expected_str = std::get<3>(params);

  int2025_t a = from_string(a_str.c_str());
  int2025_t b = from_string(b_str.c_str());
  int2025_t expected = from_string(expected_str.c_str());

  EXPECT_TRUE((a - b) == expected)
      << "Вычитание: " << a_str << " - " << b_str << " != " << expected_str;
}

TEST_P(ArithmeticOperationsTestSuite, Multiplication) {
  auto params = GetParam();
  std::string a_str = std::get<0>(params);
  std::string b_str = std::get<1>(params);
  std::string expected_str = std::get<4>(params);

  int2025_t a = from_string(a_str.c_str());
  int2025_t b = from_string(b_str.c_str());
  int2025_t expected = from_string(expected_str.c_str());

  EXPECT_TRUE((a * b) == expected)
      << "Умножение: " << a_str << " * " << b_str << " != " << expected_str;
}

TEST_P(ArithmeticOperationsTestSuite, Division) {
  auto params = GetParam();
  std::string a_str = std::get<0>(params);
  std::string b_str = std::get<1>(params);
  std::string expected_str = std::get<5>(params);

  int2025_t a = from_string(a_str.c_str());
  int2025_t b = from_string(b_str.c_str());
  int2025_t expected = from_string(expected_str.c_str());

  EXPECT_TRUE((a / b) == expected)
      << "Деление: " << a_str << " / " << b_str << " != " << expected_str;
}

INSTANTIATE_TEST_SUITE_P(
    ArithmeticTestCases, ArithmeticOperationsTestSuite,
    testing::Values(
        // a, b, a + b, a - b, a * b, a / b
        std::make_tuple("1", "1", "2", "0", "1", "1"),
        std::make_tuple("5", "3", "8", "2", "15", "1"),
        std::make_tuple("12", "4", "16", "8", "48", "3"),
        std::make_tuple("7", "11", "18", "-4", "77", "0"),

        std::make_tuple("-8", "3", "-5", "-11", "-24", "-2"),
        std::make_tuple("15", "-5", "10", "20", "-75", "-3"),
        std::make_tuple("-12", "-4", "-16", "-8", "48", "3"),
        std::make_tuple("-42", "7", "-35", "-49", "-294", "-6"),

        std::make_tuple("123", "456", "579", "-333", "56088", "0"),
        std::make_tuple("999", "111", "1110", "888", "110889", "9"),
        std::make_tuple("2048", "64", "2112", "1984", "131072", "32"),
        std::make_tuple("1000", "250", "1250", "750", "250000", "4"),

        std::make_tuple("12345", "6789", "19134", "5556", "83810205", "1"),
        std::make_tuple("1000000", "999999", "1999999", "1", "999999000000",
                        "1"),
        std::make_tuple("123456789", "987654321", "1111111110", "-864197532",
                        "121932631112635269", "0"),

        std::make_tuple("0", "1", "1", "-1", "0", "0"),
        std::make_tuple("42", "0", "42", "42", "0", "0"),
        std::make_tuple("0", "12345", "12345", "-12345", "0", "0"),
        std::make_tuple("-100", "0", "-100", "-100", "0", "0"),

        std::make_tuple("42", "1", "43", "41", "42", "42"),
        std::make_tuple("1", "999", "1000", "-998", "999", "0"),
        std::make_tuple("-123", "1", "-122", "-124", "-123", "-123"),
        std::make_tuple("5", "1", "6", "4", "5", "5"),

        std::make_tuple("2147483647", "1", "2147483648", "2147483646",
                        "2147483647", "2147483647"),
        std::make_tuple("-2147483648", "1", "-2147483647", "-2147483649",
                        "-2147483648", "-2147483648"),
        std::make_tuple("2147483647", "-2147483648", "-1", "4294967295",
                        "-4611686016279904256", "0"),

        std::make_tuple("1024", "1", "1025", "1023", "1024", "1024"),
        std::make_tuple("999999999999999999", "1", "1000000000000000000",
                        "999999999999999998", "999999999999999999",
                        "999999999999999999"),

        std::make_tuple("405272312330606683982498447530407677486444946329741970"
                        "511324085183808429621437",
                        "1",
                        "405272312330606683982498447530407677486444946329741970"
                        "511324085183808429621438",
                        "405272312330606683982498447530407677486444946329741970"
                        "511324085183808429621436",
                        "405272312330606683982498447530407677486444946329741970"
                        "511324085183808429621437",
                        "405272312330606683982498447530407677486444946329741970"
                        "511324085183808429621437"),

        std::make_tuple("256", "2", "258", "254", "512", "128"),
        std::make_tuple("1024", "1024", "2048", "0", "1048576", "1"),
        std::make_tuple("65536", "256", "65792", "65280", "16777216", "256"),

        std::make_tuple("1000", "100", "1100", "900", "100000", "10"),
        std::make_tuple("1000000000", "1000", "1000001000", "999999000",
                        "1000000000000", "1000000"),

        std::make_tuple("123456789012345", "123456789012345", "246913578024690",
                        "0", "15241578753238669120562399025", "1"),
        std::make_tuple("-999999999999999999", "999999999999999999", "0",
                        "-1999999999999999998",
                        "-999999999999999998000000000000000001", "-1"),

        std::make_tuple("17", "3", "20", "14", "51", "5"),
        std::make_tuple("100", "25", "125", "75", "2500", "4"),
        std::make_tuple("-50", "10", "-40", "-60", "-500", "-5")));
