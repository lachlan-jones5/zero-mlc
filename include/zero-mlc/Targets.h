#pragma once

#include <string_view>
#include <zero-mlc/Utils.h>

namespace zeromlc {
namespace backend {

/// Represents the compilation target.
///
/// @note Targets right now are only instruction sets, but there is more to
/// consider than just instruction sets when doing codegen.
/// This will be revisited once we start doing codegen.
enum class Target { aarch64 };

/// Converts a Target enum to its string representation.
/// @param target The target enum.
/// @return A string view representing the target.
constexpr std::string_view toString(Target target) noexcept {
  switch (target) {
  case Target::aarch64:
    return "aarch64";
  }
  zeromlc::unreachable();
}

} // end namespace backend
} // end namespace zeromlc
