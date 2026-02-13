/**
 * @file: retry_controller.hpp
 * @brief: Manages execution attempts according to a specified retry policy.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

#ifndef _retry_controller_hpp_
#define _retry_controller_hpp_

/****** Includes ******/
#include <cstdint>
#include "retry_policy.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

/**
 * @brief Controls retries for an execution using a given RetryPolicy.
 *
 * This class tracks the number of attempts and delegates retry decisions
 * to the provided RetryPolicy instance.
 */
class RetryController {
 public:
  /**
   * @brief Constructs a RetryController with the given policy.
   *
   * @param policy Reference to a RetryPolicy used to determine retry logic.
   */
  explicit RetryController(const RetryPolicy& policy);

  /**
   * @brief Destructor.
   */
  ~RetryController();

  /**
   * @brief Handles the result of an execution and determines whether to retry.
   *
   * @param result Result of the execution attempt.
   * @return RetryDecision indicating whether to retry or abort.
   */
  RetryDecision OnExecutionResult(ExecutionResult result);

  /**
   * @brief Returns the number of attempts performed so far.
   *
   * @return Current attempt count.
   */
  uint8_t AttemptCount() const;

 private:
  const RetryPolicy& policy_;             ///< Reference to the associated retry policy.
  uint8_t            attempt_count_ = 0;  ///< Tracks the number of attempts performed.
};

};  // namespace thecpuffin

#endif  // _retry_controller_hpp_

// End of file
