# install CppUTest with FetchContent
# refer: https://github.com/cpputest/cpputest#integration-as-external-cmake-project
include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master # or use release tag, eg. v4.0
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

# link CppUTest to a target
function(link_cpputest target)
  target_link_libraries(target PRIVATE
    CppUTest::CppUTest
    CppUTest::CppUTestExt)
endfunction()

# add target to CTest's test suite
function(add_cpputest target)
  include(CTest)
  add_test(target target)
endfunction()

function(link_and_addtest_cpputest target)
  link_cpputest(${target})
  add_cpputest(${target})
endfunction()