#include "CppUTest/CommandLineTestRunner.h"

// CppUTestではテストを実行するためにmainを定義する必要がある。
// テストケース名を指定する必要はなく、すべてのテストケースが実行される。
int main(int argc, char** argv) {
  return CommandLineTestRunner::RunAllTests(argc, argv);
}