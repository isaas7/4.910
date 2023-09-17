# Compilator - A C++ Compiler

Welcome to Compilator, a C++ compiler project! Compilator is designed to compile C++ source code into executable programs. This README provides an overview of the project and links to the documentation.

## Table of Contents

- [Project Overview](#project-overview)
- [Documentation](#documentation)
- [Getting Started](#getting-started)
- [Contributing](#contributing)
- [License](#license)

## Project Overview

Compilator is a C++ compiler that aims to provide correctness, efficiency, and compatibility with a wide range of C++ language features. The project is divided into several components, including the Lexer, Parser, Semantic Analyzer, and Code Generator.

- **Lexer:** The lexical analyzer responsible for tokenizing the source code. [Learn more](docs/lexer/overview.md).

- **Parser:** The syntax analyzer that constructs the Abstract Syntax Tree (AST) from the tokenized code.

- **Semantic Analyzer:** The component that performs semantic analysis, including type checking and scope resolution.

- **Code Generator:** The module responsible for generating target code (e.g., assembly or machine code).

Compilator is an open-source project, and we welcome contributions from the community. Please refer to the [Contributing Guidelines](CONTRIBUTING.md) for details on how to get involved.

## Documentation

Comprehensive documentation is available to help you understand and work with Compilator:

- [Lexer Documentation](docs/lexer/overview.md): Learn about the Lexer component, its design, and usage.
- [Parser Documentation](docs/parser/overview.md): Discover how the Parser processes source code.
- [Semantic Analyzer Documentation](docs/semantic/overview.md): Explore semantic analysis in Compilator.
- [Code Generator Documentation](docs/codegen/overview.md): Understand code generation for the target architecture.
- [Changelog](CHANGELOG.md): View the project's changelog to see a history of changes and updates.


For more information, including how to contribute to the documentation, see the [Documentation README](docs/README.md).

## Getting Started

To get started with Compilator and compile your C++ programs, follow these steps:

1. **Clone the Repository:** Clone this repository to your local machine.

2. **Build the Compiler:** Follow the build instructions in the [Build Guide](docs/build.md) to compile Compilator.

3. **Compile Your Code:** Use Compilator to compile your C++ source code. Refer to the [Usage Guide](docs/usage.md) for instructions on how to use the compiler.

4. **Run Your Program:** Execute the compiled program generated by Compilator.

For detailed information on building and using Compilator, consult the [Usage Guide](docs/usage.md).

## Contributing

We welcome contributions from the open-source community. If you'd like to contribute to Compilator, please read our [Contributing Guidelines](CONTRIBUTING.md) to get started.

## License

Compilator is open source and licensed under the terms of the [LICENSE](LICENSE). Feel free to review the license for details on how you can use, modify, and distribute Compilator.
