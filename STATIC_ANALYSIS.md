# Using `clang-tidy`.

## Installation

1. First, search whether it is already installed.
```
find /usr/local -name clang-tidy
/usr/local/Cellar/llvm/9.0.0_1/bin/clang-tidy
```
2. If not found, install it by:
```
brew install llvm
```

## Generate `compile_commands.json` from a cmake project

1. Configure cmake (assuming you have this option declared in CMakeLists.txt)
```
cmake . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```
2. `compile_commands.json` should have been generated

## Checking the option value using ccmake

```
ccmake .
```

## Usage

```
/usr/local/Cellar/llvm/9.0.0_1/bin/clang-tidy -checks=* -p . <path-to-source e.g. exe/main.cpp>
```
