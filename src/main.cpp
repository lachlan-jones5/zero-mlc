#include <filesystem>
#include <iostream>
#include <string_view>

#include <zero-mlc/SourceLanguages.h>
#include <zero-mlc/Targets.h>

int main(int argc, char *argv[]) {
  if (2 != argc) {
    std::cerr << "Error: Expected a single file path argument\n";
    std::cerr << "Usage: zero-mlc <path-to-file>"
              << "\n";
    return 1;
  }

  const std::string_view filepathArg = argv[1];
  const std::filesystem::path filepath(filepathArg);

  if (!std::filesystem::exists(filepath)) {
    std::cerr << "Error: File does not exist: " << filepath << "\n";
    return 1;
  }

  constexpr zeromlc::frontend::SourceLanguage SourceLanguage =
      zeromlc::frontend::SourceLanguage::pytorch;
  constexpr zeromlc::backend::Target Target = zeromlc::backend::Target::aarch64;

  std::cout << "Compiling " << std::filesystem::absolute(filepath).string()
            << " from " << zeromlc::frontend::toString(SourceLanguage) << " to "
            << zeromlc::backend::toString(Target) << "\n";

  return 0;
}
