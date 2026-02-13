/**
 * @file main.cpp
 * @brief Entry point for the application.
 * @author lePuffin
 * @copyright Copyright (c) 2026 Carlos Estevao
 * @date 2026-01-31
 */

/****** Includes ******/
#include <iostream>
#include "execution/execution_result.hpp"
#include "policy/fixed_retry_policy.hpp"
#include "policy/retry_controller.hpp"
#include "state/state_machine.hpp"

/****** Defines ******/
static constexpr const char* TAG = "[Main]";

/****** Functions ******/
// Public
thecpuffin::ExecutionResult SimulateExecution(uint8_t attempt) {
  // Simulação determinística para demo:
  // Falha nas primeiras duas tentativas, sucesso depois.
  return (attempt >= 3) ? thecpuffin::ExecutionResult::kSuccess
                        : thecpuffin::ExecutionResult::kFailure;
}

int main() {
  // Initialization phase: Print a message and create the TaskManager.
  std::cout << TAG << " Initializing application..." << std::endl;

  thecpuffin::FixedRetryPolicy retryPolicy(5);
  thecpuffin::RetryController  retryController(retryPolicy);
  thecpuffin::StateMachine     stateMachine;

  stateMachine.StartExecution();

  // Main execution phase: Run the task(s) and handle any errors.
  try {
    std::cout << TAG << " Application is running..." << std::endl;

    while (stateMachine.State() == thecpuffin::ExecutionState::kExecuting) {
      // Usual application logic would go here (e.g., event loop, more tasks, etc.)
      int currentAttempt = retryController.AttemptCount() + 1;

      std::cout << TAG << " Attempt #" << currentAttempt << std::endl;

      thecpuffin::ExecutionResult result = SimulateExecution(currentAttempt);

      thecpuffin::RetryDecision decision = retryController.OnExecutionResult(result);

      if (result == thecpuffin::ExecutionResult::kSuccess) {
        stateMachine.OnExecutionFinished(result);
        std::cout << TAG << " Execution succeeded" << std::endl;
        break;
      }

      if (decision == thecpuffin::RetryDecision::kAbort) {
        stateMachine.Abort();
        std::cout << TAG << " Retry policy aborted execution" << std::endl;
        break;
      }

      std::cout << TAG << " Retrying..." << std::endl;
    }
  } catch (const std::exception& e) {
    // Handle known exceptions and print the error message.
    std::cerr << TAG << " An error occurred: " << e.what() << std::endl;
    return EXIT_FAILURE;
  } catch (...) {
    // Handle any other unknown exceptions.
    std::cerr << TAG << " An unknown error occurred." << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << TAG << " Final state: ";

  switch (stateMachine.State()) {
    case thecpuffin::ExecutionState::kSuccess:
      std::cout << "Success";
      break;

    case thecpuffin::ExecutionState::kFailed:
      std::cout << "Failed";
      break;

    case thecpuffin::ExecutionState::kAborted:
      std::cout << "Aborted";
      break;

    default:
      std::cout << "Unexpected";
      break;
  }

  std::cout << std::endl;

  // Cleanup phase: Print a message before exiting.
  std::cout << TAG << " Cleaning up and exiting..." << std::endl;

  return EXIT_SUCCESS;
}

// End of file
