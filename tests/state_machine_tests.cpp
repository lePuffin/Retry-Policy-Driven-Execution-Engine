/**
 * @file: state_machine_tests.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-13
 */

/****** Includes ******/
#include "state/state_machine.hpp"

#include "CppUTest/TestHarness.h"

/****** Defines ******/

/****** Functions ******/
// Test group

// clang-format off
TEST_GROUP(StateMachineTests) {
  void setup() {
    // Code here will be called immediately before each test
  }
  void teardown() {
    // Code here will be called immediately after each test
  }
};
// clang-format on

// Tests
TEST(StateMachineTests, StartsIdle) {
  thecpuffin::StateMachine sm;
  CHECK_EQUAL((uint8_t) thecpuffin::ExecutionState::kIdle, (uint8_t) sm.State());
}

TEST(StateMachineTests, MovesToExecuting) {
  thecpuffin::StateMachine sm;
  sm.StartExecution();

  CHECK_EQUAL((uint8_t) thecpuffin::ExecutionState::kExecuting, (uint8_t) sm.State());
}

TEST(StateMachineTests, SuccessTransition) {
  thecpuffin::StateMachine sm;
  sm.StartExecution();
  sm.OnExecutionFinished(thecpuffin::ExecutionResult::kSuccess);

  CHECK_EQUAL((uint8_t) thecpuffin::ExecutionState::kSuccess, (uint8_t) sm.State());
}

TEST(StateMachineTests, FailureTransition) {
  thecpuffin::StateMachine sm;
  sm.StartExecution();
  sm.OnExecutionFinished(thecpuffin::ExecutionResult::kFailure);

  CHECK_EQUAL((uint8_t) thecpuffin::ExecutionState::kFailed, (uint8_t) sm.State());
}

// End of file
