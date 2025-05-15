# Ordered Map

A C++ project implementing an ordered map using a doubly-linked list to maintain element insertion order, built with CMake and tested with Catch2.
Prerequisites

CMake (3.10+): `sudo apt install cmake`
Git: `sudo apt install git`
C++ Compiler: GCC 9.4.0+ (sudo apt install g++)
Clang-Format: For code formatting (sudo apt install clang-format)
VS Code or Cursor: Code editor with C++ support

Verify:

```bash
cmake --version
git --version
g++ --version
clang-format --version
```

Project Structure

```
ordered_map/
├── CMakeLists.txt       # CMake build configuration
├── build.sh            # Script to build and test
├── .clang-format       # Code formatting rules
├── include/
│   └── ordered_map.hpp  # Ordered map interface
├── src/
│   └── doubly_linked_list.cpp  # Doubly-linked list implementation
├── tests/
│   └── test_ordered_map.cpp  # Catch2 test files
```

Setting Up VS Code (or Cursor)

Install Extensions:

In VS Code/Cursor, go to Extensions (Ctrl+Shift+X).
Install:
C/C++ (Microsoft): For IntelliSense and debugging.
CMake Tools (Microsoft): For CMake integration.

Configure IntelliSense:

Let's say PATH is the path to the project directory:

Create .vscode/settings.json (or .cursor/settings.json) with this content:

```json
{
  "C_Cpp.default.compileCommands": "[**PATH**]/ordered_map_lib/build/compile_commands.json"
}
```

Open Project:

Open [**PATH TO PROJECT DIRECTORY**]/ordered_map_lib in VS Code/Cursor.

Formatting Code

Clang-Format: Uses .clang-format for consistent style (Google-based).
Auto-Format: Formats on save (see editor.formatOnSave).
Manual Format:clang-format -i src/_.cpp include/_.hpp tests/\*.cpp

Via build.sh: Formats all .cpp/.hpp files before building.

Building and Running Tests

Build and Test:

```bash
chmod +x build.sh
./build.sh
```

Formats code, builds with CMake/make, and runs Catch2 tests.

Output:

Successful tests show:All tests passed (X assertions in Y test cases)

Run Specific Tests:

```bash
cd build
./tests --tags [canary]
```

Adding a New Test

Edit tests/test_ordered_map.cpp:

Add a TEST_CASE for the ordered map or doubly-linked list. Example:

```cpp
TEST_CASE("Insert maintains order", "[ordered_map]") {
    OrderedMap<int, int> map;
    map.insert(1, 10);
    map.insert(2, 20);
    REQUIRE(map.size() == 2);
}
```

Rebuild and Test:
`./build.sh`

Troubleshooting

Squiggly Lines:
Ensure build/compile_commands.json exists (via build.sh).
Verify `.vscode/settings.json` paths.

Build Errors:

```bash
Clear build: rm -rf build && ./build.sh.
Check prerequisites.
```

Test Failures:
Inspect assertions in test_ordered_map.cpp.
Run specific tests: `./build/tests --tags [tag].`

Example Test File:

```cpp
tests/test_ordered_map.cpp:
#include <catch2/catch_test_macros.hpp>
#include "ordered_map.hpp"

TEST_CASE("Canary test", "[canary]") {
    REQUIRE(true);
}

TEST_CASE("Insert maintains order", "[ordered_map]") {
    OrderedMap<int, int> map;
    map.insert(1, 10);
    map.insert(2, 20);
    REQUIRE(map.size() == 2);
}
```
