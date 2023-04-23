/// @see https://www.geeksforgeeks.org/gtest-framework/

#include <gtest/gtest.h>

#include <cmath>
#include <sstream>
#include <string>

#include "../src/base_datos.h"

std::stringstream stream_for_tests{};

/****************\
|* TESTS PARA X *|
\****************/

TEST(TestGroupName, TestName) {
  EXPECT_EQ(12, 67);
}