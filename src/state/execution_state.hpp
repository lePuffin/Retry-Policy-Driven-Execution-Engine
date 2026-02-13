/**
 * @file: execution_state.hpp
 * @brief: Defines the ExecutionState enum representing the state of execution.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

#ifndef _execution_state_hpp_
#define _execution_state_hpp_

/****** Includes ******/

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/**
 * @brief Represents the current state of an execution.
 *
 * Used by the execution engine to track whether a task is idle, executing,
 * succeeded, failed, or was aborted.
 */
enum class ExecutionState {
  kIdle,       ///< Execution has not started yet.
  kExecuting,  ///< Execution is currently in progress.
  kSuccess,    ///< Execution completed successfully.
  kFailed,     ///< Execution failed.
  kAborted     ///< Execution was aborted before completion.
};

/****** Classes ******/

};  // namespace thecpuffin

#endif  // _execution_state_hpp_

// End of file
