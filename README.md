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
- [Project Status](#project-status)

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
│   └── ordered_map.hpp          # (Future) Ordered map interface
├── src/
├── tests/
│   └── doubly_linked_list/      # Test files for doubly linked list
│       ├── front_and_back.cpp   # Tests for front/back operations
│       ├── iterator_tests.cpp   # Tests for iterator functionality
│       ├── pop_back_tests.cpp   # Tests for pop_back operations
│       ├── pop_front_tests.cpp  # Tests for pop_front operations
│       ├── push_back_tests.cpp  # Tests for push_back operations
│       └── push_front_tests.cpp # Tests for push_front operations
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
   ./tests --tags [tag]
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

1. **Choose the appropriate test file** in `tests/doubly_linked_list/` based on the functionality being tested:

   - `front_and_back.cpp` for front/back operations
   - `iterator_tests.cpp` for iterator functionality
   - `pop_back_tests.cpp` for pop_back operations
   - `pop_front_tests.cpp` for pop_front operations
   - `push_back_tests.cpp` for push_back operations
   - `push_front_tests.cpp` for push_front operations

2. **Add your test case**:

   ```cpp
   TEST_CASE("Your test description", "[tag]") {
       DoublyLinkedList<int> list;
       // Your test code here
       REQUIRE(/* your assertion */);
   }
   ```

3. **Rebuild and Test**:
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
  - Inspect assertions in the relevant test file.
  - Run specific tests: `./build/tests --tags [tag]`.
- **GitHub Actions Failures**:
  - Check logs in the "Actions" tab on GitHub.
  - Ensure `build.sh` and dependencies are compatible with `ubuntu-latest`.

## Project Status

The project is currently in development, with the following components:

1. ✅ Doubly Linked List Implementation

   - Basic operations (push_back, pop_back, push_front, pop_front)
   - Memory management using smart pointers
   - Comprehensive test coverage organized by functionality
   - Iterator support (basic implementation)

2. 🔄 Ordered Map Implementation (Coming Soon)
   - Will use the doubly linked list as its underlying data structure
   - Will maintain insertion order while providing map-like functionality

### Checklist for future improvements

- [ ] DoublyLinkedList: Add pre and post decrement operators
- [ ] DoublyLinkedList: Test front(), back(), insertion and deletion functions for copying behavior
- [ ] DoublyLinkedList: Test front(), back(), insertion and deletion functions for destructor behavior 

## Tests

### Doubly Linked List Tests

#### Front and Back Operations
- [x] Empty list has size 0
- [x] Empty list front() throws exception
- [x] Empty list back() throws exception
- [x] List with one element returns correct front
- [x] List with one element returns correct back
- [x] List with multiple elements returns correct front
- [x] List with multiple elements returns correct back

#### Iterator Operations  
- [x] Empty list begin equals end
- [x] Single element list begin points to element
- [x] Single element list begin++ equals end
- [x] Multiple element list begin points to first
- [x] Multiple element list begin++ points to second
- [x] Multiple element list can iterate through all elements

#### Push Back Operations
- [x] Push back one element increases size to 1
- [x] Push back multiple elements increases size correctly
- [x] Push back maintains correct order of elements

#### Push Front Operations
- [x] Push front one element increases size to 1
- [x] Push front multiple elements increases size correctly
- [x] Push front maintains correct order of elements

#### Pop Back Operations
- [x] Pop back on empty list throws exception
- [x] Pop back decreases size by 1
- [x] Pop back removes last element
- [x] Pop back maintains remaining elements

#### Pop Front Operations
- [x] Pop front on empty list throws exception
- [x] Pop front decreases size by 1
- [x] Pop front removes first element
- [x] Pop front maintains remaining elements

### Ordered Map Tests

#### Insertion Operations
- [x] Empty ordered map has size 0
- [x] Inserting <1,2> into empty map sets size to 1
- [x] Inserting duplicate key maintains size of 1
- [x] Inserting different keys increases size
- [x] Inserting <1,2> allows retrieving 2 with key 1
- [x] Inserting string key-value pairs works correctly
- [x] Updating existing key updates the value

