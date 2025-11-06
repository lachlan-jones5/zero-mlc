#pragma once

#include <cstdlib>
#include <utility>

namespace zeromlc {

/// @brief Hints to the compiler that a code path is not reachable.
///
/// If this function is called at runtime, it may terminate the program. It is
/// intended to be used in situations where the programmer knows that a certain
/// code path cannot be executed.
[[noreturn]] inline constexpr void unreachable() {
#if defined(__GNUC__) || defined(__clang__)
  __builtin_unreachable();
#else
  // For other compilers, we can only abort at runtime.
  // A call to this in a constant-evaluated context will fail to compile
  // because a [[noreturn]] function returns, which is the desired behavior
  // if we can't express unreachable portably in a constexpr context.
  if (!std::is_constant_evaluated()) {
    std::abort();
  }
#endif
}

namespace utils {}
} // namespace zeromlc
