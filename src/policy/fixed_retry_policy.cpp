/**
 * @file: fixed_retry_policy.cpp
 * @brief: Implements the FixedRetryPolicy retry strategy.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

/****** Includes ******/
#include "fixed_retry_policy.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public

FixedRetryPolicy::FixedRetryPolicy(uint8_t max_attempts) : max_attempts_(max_attempts) {
}

FixedRetryPolicy::~FixedRetryPolicy() {
}

RetryDecision FixedRetryPolicy::Decide(uint8_t attempt, ExecutionResult last_result) const {
  if (last_result == ExecutionResult::kSuccess) {
    return RetryDecision::kAbort;
  }

  return (attempt < max_attempts_) ? RetryDecision::kRetry : RetryDecision::kAbort;
}

// Private

}  // namespace thecpuffin

// End of file
