# zero-mlc C++23 Style Guide

# Introduction

This style guide outlines the coding conventions for C++23 code developed for the `zero-mlc` project. It is based on the [LLVM C++ Style Guide](https://llvm.org/docs/CodingStandards.html), with modifications and clarifications tailored for this project.

`zero-mlc` is a compiler project aiming to compile AI workloads, starting with PyTorch modules, down to the AArch64 instruction set. It serves as a hands-on environment for experimentation, learning, and applying modern C++ features. As such, this guide emphasizes clean, modern C++23 practices. All code in this repository is written by hand.

# Key Principles

* **Readability:** Code should be easy to understand.
* **Maintainability:** Code should be easy to modify and extend.
* **Consistency:** Adhering to a consistent style improves collaboration and reduces errors.
* **Performance:** While readability is paramount, code should be efficient.
* **Modernity & Experimentation:** Actively prefer and utilize modern C++23 features. This project is a space to learn and apply them.

# Core Formatting

* **Line Length:** 80 characters.
* **Indentation:** 2 spaces. Do not use tabs.

# Naming Conventions

This project follows the core LLVM naming scheme with some clarifications:

* **Types (Classes, Structs, Enums, TypeAliases):** Use `PascalCase` (e.g., `ModuleLoader`, `NodeIterator`).
* **Functions/Methods:** Use `camelCase` (e.g., `processNode()`, `getValue()`).
* **Variables (including class members):** Use `camelCase` (e.g., `nodeName`, `localCount`).
* **Constants (incl. `constexpr` and `const` globals):** Use `PascalCase` (e.g., `MaxBufferSize`, `DefaultTimeout`).
* **Filenames:** Use `PascalCase` (e.g., `ModuleLoader.h`, `ModuleLoader.cpp`).

# Comments & Documentation

* **Doxygen Style:** Use Doxygen-compatible comments to document public APIs (classes, functions, methods).
* **Header Documentation:** Use `///` for single-line comments or blocks of `///` for multi-line documentation.
    ```cpp
    /// This is a brief summary.
    ///
    /// This is a more detailed description.
    /// @param paramName Description of the parameter.
    /// @return Description of the return value.
    MyClass::myMethod(int paramName) {
      // ...
    }
    ```
* **Inline Comments:** Use `//` for inline comments. Focus on explaining the "why" behind a piece of code, not the "what".
    ```cpp
    // Bad: Increment i.
    i++; 
    
    // Good: Skip the first element (it's a header).
    i++;
    ```

# Modern C++ & Design

* **Type Deduction:** Use `auto` when the type is obvious from the right-hand side, but do not use it when it obscures the type or reduces clarity.
* **Modern Features:** Actively prefer modern C++ features. For example:
    * Use `concepts` (C++20) to constrain templates.
    * Prefer `std::ranges` (C++20) over complex iterator-based loops where it improves readability.
    * Use `constexpr` and `consteval` wherever possible.
* **Error Handling:**
    * **No RTTI, No Exceptions:** Following LLVM, RTTI and C++ exceptions are disabled. Do not use `try...catch` or `throw`.
    * **Asserts:** Use `assert()` liberally to check for invariants, pre-conditions, and post-conditions. This is for unrecoverable logic errors.
    * **Recoverable Errors:** For graceful handling of recoverable errors, strongly prefer `std::expected` (C++23). For simple "value or nothing" cases, `std::optional` is acceptable.
* **Design Patterns:** Strive for clean, maintainable, and extensible code. Apply well-known design patterns (e.g., Gang of Four patterns) and C++-specific patterns (e.g., RAII) where they simplify the design and solve common problems.

# Tooling

* **Code Formatter:** `clang-format` is used to enforce consistent formatting. Run `git clang-format` before committing. A `.clang-format` file based on the LLVM style is provided in the repository root.
* **Linter:** `clang-tidy` is used to identify potential issues, style violations, and uses of non-modern C++.

# Example Code

The following snippet demonstrates many of these rules in action.

```cpp
#include <cassert>
#include <expected>
#include <string>

/// Error codes for parsing operations.
enum class ParseError {
  IsEmpty,
  IsInvalid,
};

/// A simple parser to demonstrate style.
class ValueParser {
public:
  /// Parses a string view into an integer.
  ///
  /// @param input The string to parse.
  /// @return A std::expected containing the integer or a ParseError.
  std::expected<int, ParseError> parseInt(std.string_view input) {
    assert(!input.empty() && "Input must not be a null pointer");

    if (input.empty()) {
      return std::unexpected(ParseError::IsEmpty);
    }

    int result = 0;
    for (char c : input) {
      if (c >= '0' && c <= '9') {
        // Use 'auto' when the type is clear (result * 10).
        auto newResult = result * 10 + (c - '0');
        result = newResult;
      } else {
        // Not a digit, invalid input.
        return std::unexpected(ParseError::IsInvalid);
      }
    }
    return result;
  }
};
```
