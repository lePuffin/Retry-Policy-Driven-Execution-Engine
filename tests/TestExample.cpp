/**
 * @file: main.cpp
 * @brief: Test example for CppUTest framework
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "CppUTest/TestHarness.h"

/****** Defines ******/

/****** Functions ******/

// clang-format off
TEST_GROUP(FirstTestGroup) {
   void setup() {
      // Code here will be called immediately before each test
   }
   void teardown() {
      // Code here will be called immediately after each test
   }
};
// clang-format on

TEST(FirstTestGroup, FirstTest) {
    CHECK_TRUE(true);
}

// End of file
