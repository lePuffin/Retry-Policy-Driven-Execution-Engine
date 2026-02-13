/**
 * @file: retry_policy_tests.cpp
 * @brief: Test example for CppUTest framework
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "execution/execution_result.hpp"
#include "policy/fixed_retry_policy.hpp"
#include "policy/retry_decision.hpp"

#include "CppUTest/TestHarness.h"

/****** Defines ******/

/****** Functions ******/

// clang-format off
TEST_GROUP(FixedRetryPolicyTests) {
  void setup() {
    // Code here will be called immediately before each test
  }
  void teardown() {
    // Code here will be called immediately after each test
  }
};
// clang-format on

TEST(FixedRetryPolicyTests, RetriesWhileUnderLimit) {
  thecpuffin::FixedRetryPolicy policy(3);

  CHECK_EQUAL((uint8_t) thecpuffin::RetryDecision::kRetry,
              (uint8_t) policy.Decide(1, thecpuffin::ExecutionResult::kFailure));

  CHECK_EQUAL((uint8_t) thecpuffin::RetryDecision::kRetry,
              (uint8_t) policy.Decide(2, thecpuffin::ExecutionResult::kFailure));
}

TEST(FixedRetryPolicyTests, AbortsWhenLimitExceeded) {
  thecpuffin::FixedRetryPolicy policy(2);

  CHECK_EQUAL((uint8_t) thecpuffin::RetryDecision::kAbort,
              (uint8_t) policy.Decide(2, thecpuffin::ExecutionResult::kFailure));
}

TEST(FixedRetryPolicyTests, AbortsOnSuccess) {
  thecpuffin::FixedRetryPolicy policy(5);

  CHECK_EQUAL((uint8_t) thecpuffin::RetryDecision::kAbort,
              (uint8_t) policy.Decide(1, thecpuffin::ExecutionResult::kSuccess));
}

// End of file
