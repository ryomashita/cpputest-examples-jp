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
TEST(AssertionsTest, POINTERS_EQUAL) {
  // POINTERS_EQUAL(expected, actual) - Compares two const void *
  int a = 1;
  int &b = a;
  POINTERS_EQUAL(&a, &b);
}
TEST(AssertionsTest, DOUBLES_EQUAL) {
  // DOUBLES_EQUAL(expected, actual, tolerance) - Compares two doubles within
  // some tolerance
  DOUBLES_EQUAL(1.7, (double)85 / 50, 0);
  DOUBLES_EQUAL((double)1 / 3, 0.333, 0.001);
}
TEST(AssertionsTest, ENUMS_EQUAL_INT) {
  // ENUMS_EQUAL_INT(excepted, actual) - Compares two enums which their
  enum MyEnum1 { A1, B1, C1 };
  ENUMS_EQUAL_INT(A1, A1);

  /* intにcastして比較されるので、上位桁は無視される */
  enum class MyEnum2 : uint64_t {
    A = 0xffff'ffff'1234'5678,
    B = 0x1234'5678,
  };
  ENUMS_EQUAL_INT(MyEnum2::A, MyEnum2::B);
}
TEST(AssertionsTest, ENUMS_EQUAL_TYPE) {
  // ENUMS_EQUAL_TYPE(underlying_type, excepted, actual) - Compares two enums
  // which they have the same underlying type
  enum class MyEnum1 : uint64_t {
    A = 0xffff'ffff'1234'5678,
    B = 0x1234'5678,
    C = 0xffff'ffff'1234'5678,
  };
  // ENUMS_EQUAL_TYPE(uint64_t, MyEnum1::A, MyEnum1::B); // failed
  ENUMS_EQUAL_TYPE(uint64_t, MyEnum1::A, MyEnum1::C);
}
TEST(AssertionsTest, FAIL) {
  // FAIL(text) - always fails
  if (false) FAIL("This is a failure");
}
TEST(AssertionsTest, TEST_EXIT) {
  // TEST_EXIT - Exit the test without failure - useful for contract testing
  // (implementing an assert fake)
  TEST_EXIT;
  FAIL("won't reach here");
}
