/**
 * @file: retry_controller.cpp
 * @brief: Implements the RetryController class that manages execution retries.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

/****** Includes ******/
#include "retry_controller.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public
RetryController::RetryController(const RetryPolicy& policy) : policy_(policy) {
  // Constructor implementation
}

RetryController::~RetryController() {
  // Destructor implementation
}

RetryDecision RetryController::OnExecutionResult(ExecutionResult result) {
  ++attempt_count_;
  return policy_.Decide(attempt_count_, result);
}

uint8_t RetryController::AttemptCount() const {
  return attempt_count_;
}

// Private

}  // namespace thecpuffin

// End of file
