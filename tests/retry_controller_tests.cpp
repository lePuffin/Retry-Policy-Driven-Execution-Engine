/**
 * @file: retry_controller_tests.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

/****** Includes ******/
#include "policy/fixed_retry_policy.hpp"
#include "policy/retry_controller.hpp"

#include "CppUTest/TestHarness.h"

/****** Defines ******/

/****** Functions ******/
// Test group

// clang-format off
TEST_GROUP(RetryControllerTests) {
  void setup() {
    // Code here will be called immediately before each test
  }
  void teardown() {
    // Code here will be called immediately after each test
  }
};
// clang-format on

// Tests
TEST(RetryControllerTests, IncrementsAttempts) {
  thecpuffin::FixedRetryPolicy policy(3);
  thecpuffin::RetryController  controller(policy);

  controller.OnExecutionResult(thecpuffin::ExecutionResult::kFailure);
  controller.OnExecutionResult(thecpuffin::ExecutionResult::kFailure);

  CHECK_EQUAL(2, controller.AttemptCount());
}

TEST(RetryControllerTests, StopsRetryingAfterSuccess) {
  thecpuffin::FixedRetryPolicy policy(3);
  thecpuffin::RetryController  controller(policy);

  thecpuffin::RetryDecision decision =
      controller.OnExecutionResult(thecpuffin::ExecutionResult::kSuccess);

  CHECK_EQUAL((uint8_t) thecpuffin::RetryDecision::kAbort, (uint8_t) decision);
}

// End of file
