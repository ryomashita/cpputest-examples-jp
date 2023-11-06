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
}
TEST(AssertionsTest, CHECK_EQUAL_TEXT) {
  // CHECK_EQUAL_TEXT(expected, actual, text)
  CHECK_EQUAL_TEXT(1, 1, "1 == 1");
}