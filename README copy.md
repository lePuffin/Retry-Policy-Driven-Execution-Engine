# C++ Project Template

This repository serves as a starting point for C++ projects. It includes a basic structure, build setup, and essential tools to streamline development.

## Project Structure

```
project-name/
-- .devcontainer/      # Docker Container
-- .vscode/            # VSCode Configurations
-- build/              # Build output (ignored by version control)
-- docs/               # Documentation and configurations like clang and cpplint
-- libs/               # Will contain external libraries
-- src/                # Source code
   |-- app/            # Application logic
   |-- interface/      # Interfaces and abstractions
   |-- board/          # Board-specific code or hardware abstraction
-- tests/              # Unit tests
-- .gitignore          # Git ignore rules
-- CMakeLists.txt      # CMake build configuration
-- LICENCE             # Licence of the project
-- README.md           # Project documentation
```

### Directory Description

- **build/**: The directory for compiled files and temporary build artifacts.
- **docs/**: The directory for documentation and configuration files (e.g., clang-format, cpplint).
- **libs/**: Contains the external library files.
- **src/**: Contains the implementation files (.cpp) organized as:
  - **app/**: Core application logic and main functionality.
  - **interface/**: Interfaces and abstractions for modular design.
  - **board/**: Board-specific or hardware abstraction code.
- **tests/**: Contains unit test files.

## Requirements

- C++17 or later
- CMake 3.28 or later
- A C++ compiler (e.g., GCC, Clang, or MSVC)

## Getting Started

### Clone the Repository

```bash
git clone https://github.com/lePuffin/basic_cpp.git
cd basic_cpp
```

### Build the Project

1. Create a build directory:
   ```bash
   mkdir build && cd build
   ```

2. Run CMake:
   ```bash
   cmake .. -DCMAKE_BUILD_TYPE=Release
   ```

3. Compile:
   ```bash
   cmake --build .
   ```

### Run Tests
Commands

```bash
cd build/tests
./UnitTests
```

Or use the CppUTests Extension.

## Usage

Instructions on how to use the application or library, with examples if applicable.

## Contributing

1. Fork the repository.
2. Create a feature branch.
3. Commit your changes.
4. Submit a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
