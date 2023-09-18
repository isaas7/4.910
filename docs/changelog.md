# Changelog

All notable changes to the "Compilator - A C++ Compiler" project will be documented in this file.
## [0.0.21] - 2023-09-18


## [0.0.2] - 2023-09-17

### Added

- **Lexer Component Updates:**
  - Modified the `scanToken` method in `lexer.cpp` to handle whitespace more effectively.
  - Added new test cases in `lexer_tests.cpp` to ensure correct tokenization, including handling of whitespace.
  - Added `runtime_error` to `scanToken` and updated test fixture to pass with `EXPECT_THROW`
  - Updated the lexer component documentation in `docs/lexer/overview.md`.

### Test Suite
- Enhanced the test suite in the `tests/` directory to cover recent changes and ensure robust testing.

## [0.0.1] - 2023-09-17

### Added

- **Initial Project Structure:**
  - Created the project directory structure.
  - Added `src/` directory with subdirectories for various components.
  - Included `include/` directory for public header files.
  - Introduced `tests/` directory for the test suite.
  - Set up `examples/` directory for example source code.
  - Established `docs/` directory for project documentation.

- **Component Documentation:**
  - Added documentation for each project component.
    - `docs/lexer/overview.md` provides an overview of the lexer component.
    - `docs/parser/overview.md`, `docs/semantic/overview.md`, `docs/ir/overview.md`, `docs/optimizer/overview.md`, and `docs/codegen/overview.md` for other components.

- **Lexer Component Implementation:**
  - Implemented the basic lexer component in `lexer.h` and `lexer.cpp`.
  - Defined token types and implemented tokenization logic.
  - Introduced the `Lexer` class with a `tokenize` method.

- **Test Suite:**
  - Created a test suite in the `tests/` directory.
  - Implemented `lexer_tests.cpp` to test the lexer component.
  - Added test cases to ensure correct tokenization.

- **Project Overview README:**
  - Created a README.md file with a project overview and links to component documentation.
  - Detailed the project structure.
  - Briefly described components and their responsibilities.
  - Provided links to component documentation.

- **Licensing Information:**
  - Included a LICENSE file with project licensing details.

This version represents the initial setup and documentation of the Compilator project. It includes the creation of the project's directory structure, initial documentation for each component, and the start of the lexer implementation. Further development will include the completion of each component, expanded documentation, and additional features for the lexer and other parts of the compiler.
