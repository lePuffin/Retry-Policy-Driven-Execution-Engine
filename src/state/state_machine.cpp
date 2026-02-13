/**
 * @file: state_machine.cpp
 * @brief: Implements the StateMachine class that manages execution states.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

/****** Includes ******/
#include "state_machine.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public
StateMachine::StateMachine() {
}

StateMachine::~StateMachine() {
}

ExecutionState StateMachine::State() const {
  return state_;
}

void StateMachine::StartExecution() {
  state_ = ExecutionState::kExecuting;
}

void StateMachine::OnExecutionFinished(ExecutionResult result) {
  state_ =
      (result == ExecutionResult::kSuccess) ? ExecutionState::kSuccess : ExecutionState::kFailed;
}

void StateMachine::Abort() {
  state_ = ExecutionState::kAborted;
}

// Private

}  // namespace thecpuffin

// End of file
