#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(AssertionsTest){};
TEST(AssertionsTest, CHECK) {
  // CHECK(boolean condition) - checks any boolean result
  CHECK(true);
}
TEST(AssertionsTest, CHECK_TRUE) {
  // CHECK_TRUE(boolean condition) - checks for true
  CHECK_TRUE(true);
}
TEST(AssertionsTest, CHECK_FALSE) {
  // CHECK_FALSE(boolean condition) - checks for false
  CHECK_FALSE(false);
}
TEST(AssertionsTest, CHECK_EQUAL) {
  // CHECK_EQUAL(expected, actual)
  // - checks for equality between entities using ==.
  // So if you have a class that supports operator==() you can use this
  // macro to compare two instances.
  CHECK_EQUAL(1, 1);
  // CHECK_EQUAL_TEXT(expected, actual, text)
  CHECK_EQUAL_TEXT(1, 1, "1 == 1");
}
TEST(AssertionsTest, STRCMP_EQUAL) {
  // STRCMP_EQUAL(expected, actual)
  // - check const char* strings for equality using strcmp
  STRCMP_EQUAL("hello", "hello");
  // STRCMP_EQUAL_TEXT(expected, actual, text)
  STRCMP_EQUAL_TEXT("hello", "hello", "hello == hello");
}
TEST(AssertionsTest, LONGS_EQUAL) {
  // LONGS_EQUAL(expected, actual) - checks for equality between longs
  LONGS_EQUAL(1, 1);
  LONGS_EQUAL(0xabcd'1234'5678, 0xabcd'1234'5678);
}
TEST(AssertionsTest, BYTES_EQUAL) {
  // BYTES_EQUAL(expected, actual) - Compares two numbers, eight bits wide
  BYTES_EQUAL(0xab, 0xab);
  BYTES_EQUAL(0x1234'5678, 0x78);
}

// [TODO]
// POINTERS_EQUAL(expected, actual) - Compares two const void *
// DOUBLES_EQUAL(expected, actual, tolerance) - Compares two doubles within some
// tolerance ENUMS_EQUAL_INT(excepted, actual) - Compares two enums which their
// underlying type is int ENUMS_EQUAL_TYPE(underlying_type, excepted, actual) -
// Compares two enums which they have the same underlying type FAIL(text) -
// always fails TEST_EXIT - Exit the test without failure - useful for contract
// testing (implementing an assert fake)