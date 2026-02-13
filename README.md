# Policy-Driven Execution Engine

This repository demonstrates a **deterministic, policy-driven retry
architecture** implemented in modern C++ (C++17).

Instead of embedding retry logic inside executors or control-flow loops,
retry behavior is delegated to **external policies**, resulting in
systems that are:

-   Predictable
-   Fully unit-testable
-   Easy to reason about
-   Safe to evolve

---

## Motivation

Traditional retry implementations often mix execution logic, error
handling, and control flow:

    while (retries < N) {
        if (execute() == Success)
            break;
    }

This style typically introduces:

-   Hidden state
-   Fragile control flow
-   Hard-to-test behavior
-   Tight coupling between components

This project presents a cleaner alternative.

---

## Core Principle

Failures do not cause behavior --- **policies cause behavior**

Execution components report outcomes.\
Policies decide what those outcomes mean.

---

## Architectural Goals

-   No retry logic inside executors
-   No implicit control flow
-   Explicit state transitions
-   Policy-driven decisions
-   Deterministic behavior
-   Straightforward unit testing

---

## Execution Flow

Execution → Result → RetryController → Decision → StateMachine

1.  An execution attempt produces a result
2.  The RetryController forwards the result to a RetryPolicy
3.  The policy decides whether to retry or abort
4.  The StateMachine reacts to the decision

Each component owns a single responsibility.

---

## Project Structure

    src/
    ├── execution/
    |   └── execution_result.hpp
    ├── policy/
    |   ├── fixed_retry_policy.cpp
    |   ├── fixed_retry_policy.hpp
    |   ├── retry_controller.cpp
    |   ├── retry_controller.hpp
    |   ├── retry_decision.hpp
    |   └── retry_policy.hpp
    ├── state/
    |   ├── execution_state.hpp
    |   ├── state_machine.cpp
    |   └── state_machine.hpp
    └── main.cpp

---

## Testing Strategy

Each layer can be tested independently:

-   Policies: pure logic tests
-   RetryController: deterministic behavior tests
-   StateMachine: explicit transition tests

No complex mocks required.

---

## Natural Extensions

This design can be easily extended with:

-   Exponential backoff policies
-   Time budget / deadline policies
-   Circuit breaker policies
-   Rate limiting / quota policies
-   Observability / metrics hooks

---

## Build

Requires **C++20**.
```bash
mkdir build
cd build
cmake ..
make
```

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.
