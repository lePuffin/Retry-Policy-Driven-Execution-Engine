/**
 * @file: fixed_retry_policy.hpp
 * @brief: Implements a retry policy with a fixed maximum number of attempts.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

#ifndef _fixed_retry_policy_hpp_
#define _fixed_retry_policy_hpp_

/****** Includes ******/
#include <cstdint>
#include "retry_policy.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

/**
 * @brief Retry policy that allows a fixed number of execution attempts.
 *
 * The policy permits retries until the configured maximum number of attempts
 * is reached, after which execution is considered failed.
 */
class FixedRetryPolicy : public RetryPolicy {
 public:
  /**
   * @brief Constructs a FixedRetryPolicy.
   *
   * @param max_attempts Maximum number of attempts allowed.
   */
  explicit FixedRetryPolicy(uint8_t max_attempts);

  /**
   * @brief Destructor.
   */
  ~FixedRetryPolicy();

  /**
   * @brief Determines whether another retry should be performed.
   *
   * @param attempt Current attempt number.
   * @param last_result Result of the previous execution attempt.
   * @return RetryDecision indicating whether to retry or stop.
   */
  RetryDecision Decide(uint8_t attempt, ExecutionResult last_result) const override;

 private:
  uint8_t max_attempts_;  ///< Maximum number of allowed attempts.
};

};  // namespace thecpuffin

#endif  // _fixed_retry_policy_hpp_

// End of file
