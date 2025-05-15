# Ordered Map

A C++ project implementing an ordered map using a doubly-linked list to maintain element insertion order, built with CMake, tested with Catch2, and formatted with Clang-Format.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Setting Up VS Code (or Cursor)](#setting-up-vs-code-or-cursor)
- [Formatting Code](#formatting-code)
- [Building and Running Tests](#building-and-running-tests)
- [GitHub Actions CI](#github-actions-ci)
- [Adding a New Test](#adding-a-new-test)
- [Troubleshooting](#troubleshooting)
- [Example Test File](#example-test-file)

## Prerequisites

- **CMake** (3.10+): `sudo apt install cmake`
- **Git**: `sudo apt install git`
- **C++ Compiler**: GCC 9.4.0+ (`sudo apt install g++`)
- **Clang-Format**: For code formatting (`sudo apt install clang-format`)
- **VS Code** or **Cursor**: Code editor with C++ support

Verify installations:

```bash
cmake --version
git --version
g++ --version
clang-format --version
```

## Project Structure

```
ordered_map/
├── .github/
│   └── workflows/
│       └── cmake.yml       # GitHub Actions workflow
├── CMakeLists.txt         # CMake build configuration
├── build.sh              # Script to build and test
├── .clang-format         # Code formatting rules
├── include/
│   ├── doubly_linked_list.hpp    # Doubly-linked list implementation
│   └── ordered_map.hpp          # (Future) Ordered map implementation
├── src/
├── tests/
│   └── test_doubly_linked_list.cpp  # Catch2 test files
```

## Setting Up VS Code (or Cursor)

1. **Install Extensions**:

   - In VS Code/Cursor, go to Extensions (Ctrl+Shift+X).
   - Install:
     - **C/C++** (Microsoft): For IntelliSense and debugging.
     - **CMake Tools** (Microsoft): For CMake integration.

2. **Configure IntelliSense**:

   - Create `.vscode/settings.json` (or `.cursor/settings.json`):
     ```json
     {
       "C_Cpp.default.compileCommands": "${workspaceFolder}/build/compile_commands.json",
       "C_Cpp.clang_format_path": "/usr/bin/clang-format",
       "C_Cpp.formatting": "clangFormat",
       "editor.formatOnSave": true,
       "[cpp]": {
         "editor.defaultFormatter": "ms-vscode.cpptools"
       }
     }
     ```

3. **Open Project**:
   - Open the project folder in VS Code/Cursor.

## Formatting Code

- **Clang-Format**: Uses `.clang-format` for consistent style (Google-based).
- **Auto-Format**: Formats on save (see `editor.formatOnSave`).
- **Manual Format**:
  ```bash
  clang-format -i src/*.cpp include/*.hpp tests/*.cpp
  ```
- **Via build.sh**: Formats all `.cpp`/`.hpp` files before building.

## Building and Running Tests

1. **Build and Test**:

   ```bash
   chmod +x build.sh
   ./build.sh
   ```

   - Formats code, builds with CMake/make, and runs Catch2 tests.

2. **Output**:

   - Successful tests show:
     ```
     All tests passed (X assertions in Y test cases)
     ```

3. **Run Specific Tests**:
   ```bash
   cd build
   ./tests --tags [canary]
   ```

## GitHub Actions CI

- **Workflow**: `.github/workflows/cmake.yml` automates building and testing on push to `main` or pull requests to `main`.
- **Setup**:
  1. Push your repository to GitHub.
  2. Ensure `.github/workflows/cmake.yml` exists.
  3. CI runs `build.sh` on `ubuntu-latest`, formatting, building, and testing.
- **View Results**:
  - Check the "Actions" tab on GitHub for CI logs.

## Adding a New Test

1. **Edit `tests/test_doubly_linked_list.cpp`**:

   - Add a `TEST_CASE` for the doubly-linked list. Example:
     ```cpp
     TEST_CASE("Push back maintains order", "[push_back]") {
         DoublyLinkedList<int> list;
         list.push_back(1);
         list.push_back(2);
         REQUIRE(list.size() == 2);
         REQUIRE(list.front() == 1);
         REQUIRE(list.back() == 2);
     }
     ```

2. **Rebuild and Test**:
   ```bash
   ./build.sh
   ```

## Troubleshooting

- **Squiggly Lines**:
  - Ensure `build/compile_commands.json` exists (via `build.sh`).
  - Verify `.vscode/settings.json` paths.
- **Build Errors**:
  - Clear build: `rm -rf build && ./build.sh`.
  - Check prerequisites.
- **Test Failures**:
  - Inspect assertions in `test_doubly_linked_list.cpp`.
  - Run specific tests: `./build/tests --tags [tag]`.
- **GitHub Actions Failures**:
  - Check logs in the "Actions" tab on GitHub.
  - Ensure `build.sh` and dependencies are compatible with `ubuntu-latest`.

## Example Test File

`tests/test_doubly_linked_list.cpp`:

```cpp
#include <catch2/catch_test_macros.hpp>
#include "doubly_linked_list.hpp"

TEST_CASE("Canary test", "[canary]") {
    REQUIRE(true);
}

TEST_CASE("Push back maintains order", "[push_back]") {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 2);
}
```

## Project Status

The project is currently in development, with the following components:

1. ✅ Doubly Linked List Implementation

   - Basic operations (push_back, pop_back, push_front, pop_front)
   - Memory management using smart pointers
   - Comprehensive test coverage

2. 🔄 Ordered Map Implementation (Coming Soon)
   - Will use the doubly linked list as its underlying data structure
   - Will maintain insertion order while providing map-like functionality
