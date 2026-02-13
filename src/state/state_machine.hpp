/**
 * @file: state_machine.hpp
 * @brief: Defines the StateMachine class for managing execution states.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

#ifndef _state_machine_hpp_
#define _state_machine_hpp_

/****** Includes ******/
#include "../execution/execution_result.hpp"
#include "execution_state.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

/**
 * @brief Manages the state of an execution task.
 *
 * Tracks the current state (idle, executing, success, failed, aborted)
 * and provides methods to start, finish, or abort execution.
 */
class StateMachine {
 public:
  /**
   * @brief Constructs a StateMachine in the idle state.
   */
  StateMachine();

  /**
   * @brief Destructor.
   */
  ~StateMachine();

  /**
   * @brief Returns the current execution state.
   *
   * @return Current ExecutionState.
   */
  ExecutionState State() const;

  /**
   * @brief Starts execution and transitions the state to kExecuting.
   */
  void StartExecution();

  /**
   * @brief Handles completion of execution and updates the state accordingly.
   *
   * @param result Result of the execution attempt.
   */
  void OnExecutionFinished(ExecutionResult result);

  /**
   * @brief Aborts execution and transitions the state to kAborted.
   */
  void Abort();

 private:
  ExecutionState state_ = ExecutionState::kIdle;  ///< Tracks the current execution state.
};

};  // namespace thecpuffin

#endif  // _state_machine_hpp_

// End of file
