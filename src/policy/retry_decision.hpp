/**
 * @file: retry_decision.hpp
 * @brief: Defines the RetryDecision enum used to indicate retry actions.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

#ifndef _retry_decision_hpp_
#define _retry_decision_hpp_

/****** Includes ******/

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/**
 * @brief Represents the decision after an execution attempt.
 *
 * Used by retry policies and controllers to indicate whether execution
 * should be retried or aborted.
 */
enum class RetryDecision {
  kRetry,  ///< Indicates that the execution should be retried.
  kAbort   ///< Indicates that the execution should be aborted.
};

/****** Classes ******/

};  // namespace thecpuffin

#endif  // _retry_decision_hpp_

// End of file
