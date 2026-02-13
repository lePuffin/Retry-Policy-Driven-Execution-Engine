/**
 * @file: execution_result.hpp
 * @brief: Defines the ExecutionResult enum used to represent execution outcomes.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

#ifndef _execution_result_hpp_
#define _execution_result_hpp_

/****** Includes ******/

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/**
 * @brief Represents the outcome of an execution step.
 */
enum class ExecutionResult {
  kSuccess,  ///< Execution completed successfully.
  kFailure   ///< Execution failed.
};

/****** Classes ******/

};  // namespace thecpuffin

#endif  // _execution_result_hpp_

// End of file
