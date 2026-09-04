#pragma once

#include <cstddef>
#include <cstdint>
#include <iosfwd>

constexpr std::size_t kBits = 2024;
constexpr std::size_t kBytes = (kBits + 1 + 7) / 8;

struct int2025_t {  // NOLINT(readability-identifier-naming)
  std::uint8_t value[kBytes]{};
};

static_assert(sizeof(int2025_t) <= 254,
              "Size of int2025_t must be no higher than 254 bytes");

int2025_t from_int(
    std::int32_t value);  // NOLINT(readability-identifier-naming)
int2025_t from_string(    // NOLINT(readability-identifier-naming)
    const char* buffer);

int2025_t operator~(const int2025_t& value);
int2025_t operator-(const int2025_t& value);
int2025_t abs(const int2025_t& value);  // NOLINT(readability-identifier-naming)

int2025_t operator+(const int2025_t& lhs, const int2025_t& rhs);
int2025_t operator-(const int2025_t& lhs, const int2025_t& rhs);
int2025_t operator*(const int2025_t& lhs, const int2025_t& rhs);
int2025_t operator/(const int2025_t& lhs, const int2025_t& rhs);

bool operator==(const int2025_t& lhs, const int2025_t& rhs);
bool operator!=(const int2025_t& lhs, const int2025_t& rhs);
bool operator<(const int2025_t& lhs, const int2025_t& rhs);
bool operator<=(const int2025_t& lhs, const int2025_t& rhs);
bool operator>(const int2025_t& lhs, const int2025_t& rhs);
bool operator>=(const int2025_t& lhs, const int2025_t& rhs);

std::ostream& operator<<(std::ostream& stream, const int2025_t& value);
