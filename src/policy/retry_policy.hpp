/**
 * @file: retry_policy.hpp
 * @brief: Defines the abstract RetryPolicy interface for controlling retries.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

#ifndef _retry_policy_hpp_
#define _retry_policy_hpp_

/****** Includes ******/
#include <cstdint>
#include "../execution/execution_result.hpp"
#include "retry_decision.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

/**
 * @brief Abstract base class for retry policies.
 *
 * Provides the interface for determining whether an execution should be
 * retried based on the attempt number and the last execution result.
 */
class RetryPolicy {
 public:
  /**
   * @brief Destructor.
   */
  virtual ~RetryPolicy() = default;

  /**
   * @brief Determines whether to retry an execution attempt.
   *
   * @param attempt Current attempt number (starting from 1).
   * @param last_result Result of the previous execution attempt.
   * @return RetryDecision indicating whether to retry or abort.
   */
  virtual RetryDecision Decide(uint8_t attempt, ExecutionResult last_result) const = 0;
};

};  // namespace thecpuffin

#endif  // _retry_policy_hpp_

// End of file
