#pragma once

#include <string_view>
#include <zero-mlc/Utils.h>

namespace zeromlc {
namespace frontend {

/// Represents the source language for compilation.
enum class SourceLanguage { pytorch };

/// Converts a SourceLanguage enum to its string representation.
/// @param source The source language enum.
/// @return A string view representing the source language.
constexpr std::string_view toString(SourceLanguage source) noexcept {
  switch (source) {
  case SourceLanguage::pytorch:
    return "PyTorch";
  }
  zeromlc::unreachable();
}

} // end namespace frontend
} // end namespace zeromlc
