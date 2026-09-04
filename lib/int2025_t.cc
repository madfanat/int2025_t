#include "int2025_t.h"

#include <cstddef>
#include <cstdint>
#include <ostream>

namespace {

constexpr std::uint8_t kLastByteMask =
    static_cast<std::uint8_t>((1U << (kBits % 8 + 1)) - 1U);

bool Bit(const int2025_t& value, std::size_t position) {
  const std::size_t byte = position / 8;
  const std::size_t bit = position % 8;

  return ((value.value[byte] >> bit) & 1U) != 0;
}

int2025_t Normalized(int2025_t value) {
  value.value[kBytes - 1] &= kLastByteMask;

  return value;
}

bool IsNegative(const int2025_t& value) { return Bit(value, kBits); }

}  // namespace

int2025_t from_int(
    std::int32_t value) {  // NOLINT(readability-identifier-naming)
  const bool is_negative = value < 0;

  std::uint32_t value_abs;
  if (is_negative) {
    value_abs = static_cast<std::uint32_t>(-static_cast<std::int64_t>(value));
  } else {
    value_abs = static_cast<std::uint32_t>(value);
  }

  int2025_t result;

  std::size_t byte = 0;
  while (value_abs != 0) {
    result.value[byte] = static_cast<std::uint8_t>(value_abs % 256);
    value_abs /= 256;
    ++byte;
  }

  if (is_negative) {
    return -result;
  }

  return result;
}

int2025_t from_string(  // NOLINT(readability-identifier-naming)
    const char* buffer) {
  bool is_negative = false;
  if (*buffer == '-' || *buffer == '+') {
    is_negative = *buffer == '-';
    ++buffer;
  }

  const int2025_t base = from_int(10);
  int2025_t result;
  while (*buffer != '\0') {
    const int digit = *buffer - '0';
    result = result * base + from_int(digit);
    ++buffer;
  }

  if (is_negative) {
    return -result;
  }

  return result;
}

int2025_t operator~(const int2025_t& value) {
  int2025_t result;
  for (std::size_t i = 0; i < kBytes; ++i) {
    result.value[i] = static_cast<std::uint8_t>(~value.value[i]);
  }
  return Normalized(result);
}

int2025_t operator-(const int2025_t& value) { return ~value + from_int(1); }

int2025_t abs(
    const int2025_t& value) {  // NOLINT(readability-identifier-naming)
  if (IsNegative(value)) {
    return -value;
  }

  return value;
}

int2025_t operator+(const int2025_t& lhs, const int2025_t& rhs) {
  int2025_t result;
  std::uint16_t carry = 0;

  for (std::size_t i = 0; i < kBytes; ++i) {
    const std::uint16_t sum = static_cast<std::uint16_t>(lhs.value[i]) +
                              static_cast<std::uint16_t>(rhs.value[i]) + carry;
    result.value[i] = static_cast<std::uint8_t>(sum % 256);
    carry = sum / 256;
  }

  return Normalized(result);
}

int2025_t operator-(const int2025_t& lhs, const int2025_t& rhs) {
  return lhs + (-rhs);
}

int2025_t operator*(const int2025_t& lhs, const int2025_t& rhs) {
  int2025_t result;

  for (std::size_t i = 0; i < kBytes; ++i) {
    std::uint32_t carry = 0;
    for (std::size_t j = 0; i + j < kBytes; ++j) {
      const std::uint32_t product =
          static_cast<std::uint32_t>(result.value[i + j]) +
          static_cast<std::uint32_t>(lhs.value[i]) * rhs.value[j] + carry;
      result.value[i + j] = static_cast<std::uint8_t>(product % 256);
      carry = product / 256;
    }
  }

  return Normalized(result);
}

int2025_t operator/(const int2025_t& lhs, const int2025_t& rhs) {
  const int2025_t zero;
  if (rhs == zero) {
    return zero;
  }

  const bool is_negative = IsNegative(lhs) != IsNegative(rhs);
  const int2025_t lhs_abs = abs(lhs);
  const int2025_t rhs_abs = abs(rhs);

  int2025_t result;

  int2025_t remainder;
  for (std::size_t position = kBits + 1; position-- > 0;) {
    remainder = remainder + remainder;
    if (Bit(lhs_abs, position)) {
      remainder = remainder + from_int(1);
    }

    const int2025_t difference = remainder - rhs_abs;
    if (!IsNegative(difference)) {
      remainder = difference;
      result.value[position / 8] |=
          static_cast<std::uint8_t>(1U << (position % 8));
    }
  }

  if (is_negative) {
    return -result;
  }

  return result;
}

bool operator==(const int2025_t& lhs, const int2025_t& rhs) {
  for (std::size_t i = 0; i < kBytes; ++i) {
    if (lhs.value[i] != rhs.value[i]) {
      return false;
    }
  }

  return true;
}

bool operator!=(const int2025_t& lhs, const int2025_t& rhs) {
  return !(lhs == rhs);
}

bool operator<(const int2025_t& lhs, const int2025_t& rhs) {
  const bool lhs_is_negative = IsNegative(lhs);
  const bool rhs_is_negative = IsNegative(rhs);

  if (lhs_is_negative != rhs_is_negative) {
    return lhs_is_negative;
  }

  for (std::size_t i = kBytes; i-- > 0;) {
    if (lhs.value[i] != rhs.value[i]) {
      return lhs.value[i] < rhs.value[i];
    }
  }

  return false;
}

bool operator<=(const int2025_t& lhs, const int2025_t& rhs) {
  return !(rhs < lhs);
}

bool operator>(const int2025_t& lhs, const int2025_t& rhs) { return rhs < lhs; }

bool operator>=(const int2025_t& lhs, const int2025_t& rhs) {
  return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& stream, const int2025_t& value) {
  const int2025_t zero;
  if (value == zero) {
    return stream << '0';
  }

  if (IsNegative(value)) {
    stream << '-';
  }
  stream << "0b";

  const int2025_t value_abs = abs(value);

  bool has_output = false;
  for (std::size_t position = kBits + 1; position > 0; --position) {
    const bool bit = Bit(value_abs, position - 1);
    if (bit) {
      has_output = true;
    }

    if (has_output) {
      stream << (bit ? '1' : '0');
    }
  }

  return stream;
}
