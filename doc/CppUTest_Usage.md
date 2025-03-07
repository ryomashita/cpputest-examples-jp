# CppUTest Usage Guide

This guide provides a complete overview of how to use CppUTest, a lightweight unit testing framework for C/C++, covering things from writing test cases to integrating with CMake using FetchContent and running tests. It is self-contained, explaining all necessary aspects, including structuring tests, implementing main(), and executing tests. Let me know if you need further modifications.

## 1. Overview

CppUTest is designed to help you write unit tests for your C/C++ code efficiently. This guide explains how to structure your tests, implement your own main function, and integrate CppUTest into your build system using CMake.

## 2. Setup

This guide assumes you are using CMake as your build system. CMake is used to install and build all required libraries, including CppUTest.

### Required Tools
- CMake
- A C++ compiler (e.g., gcc, clang)
- CppUTest (automatically fetched and configured via CMake)

### Build Steps

1. From the source root directory, create a build directory and run CMake:

   ```bash
   cmake -S . -B build
   ```

2. Build the project using the generated build files:

   ```bash
   cmake --build build
   ```

## 3. Running Tests

After a successful build, a test executable will be generated. To run the tests, execute the appropriate binary. For example:

```bash
./build/path/to/test_executable
```

*Note:* The exact path to the test executable depends on your build configuration and CMake settings.

## 4. Basic Usage of CppUTest

A basic test case using CppUTest is structured as follows:

```cpp
#include "CppUTest/TestHarness.h"

TEST_GROUP(SampleGroup)
{
    void setup() {}
    void teardown() {}
};

TEST(SampleGroup, ExampleTest)
{
    int expected = 10;
    int actual = 10; // Replace this with your actual computation or function call
    CHECK_EQUAL(expected, actual);
}
```

- The **TEST_GROUP** macro defines a group of tests along with shared setup and teardown routines.
- The **TEST** macro declares an individual test case.
- Various assertion macros (e.g., CHECK_EQUAL, LONGS_EQUAL, STRCMP_EQUAL) compare expected and actual values.

**Important:** In CppUTest, you must provide your own `main` function. A common pattern is to create an `AllTests.cpp` file containing:

```cpp
#include "CppUTest/CommandLineTestRunner.h"

int main(int argc, char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
```

This file is compiled along with your test cases to produce the final test executable.

## 5. Using CppUTest with CMake

Integrate CppUTest into your CMake project using the following configuration, adapted directly from the FetchContent-based setup in `cmake/install_cpputest.cmake`:

```cmake
# install CppUTest with FetchContent
# refer: https://github.com/cpputest/cpputest#integration-as-external-cmake-project
include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master # or use a release tag, eg. v4.0
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

# Link CppUTest to a target
function(link_cpputest target)
  target_link_libraries(${target} PRIVATE
    CppUTest::CppUTest
    CppUTest::CppUTestExt)
endfunction()

# Add target to CTest's test suite
function(add_cpputest target)
  include(CTest)
  add_test(${target} ${target})
endfunction()

function(link_and_addtest_cpputest target)
  link_cpputest(${target})
  add_cpputest(${target})
endfunction()
```

Include this configuration in your CMake project to automatically download CppUTest and enable linking with your test targets. Use the provided functions to link the CppUTest libraries and integrate your tests with CTest.

## 6. Troubleshooting and Notes

- **Build Issues**
  - Verify the settings in your CMakeLists.txt files and the configuration in your CMake setup.
  
- **Runtime Issues**
  - Ensure the test executable is correctly built and run from the appropriate path.
  
- **Extensibility**
  - You can add or modify test cases as needed. Refer to the official CppUTest documentation and sample code for guidance on adding custom assertions or extending functionality.

## 7. References

- [CppUTest Official Documentation](http://cpputest.github.io/)
- [CMake Documentation](https://cmake.org/cmake/help/latest/)

---

Use this guide as a self-contained reference to understand how to implement, integrate, and run unit tests with CppUTest.
