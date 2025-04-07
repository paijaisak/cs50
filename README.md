# CS50 Projects - Development Guide

## Build Commands
```
# Initial setup
meson setup builddir

# Build all projects
meson compile -C builddir

# Build specific project
meson compile -C builddir projects/<project_name>

# Run all tests
meson test -C builddir

# Run specific test
meson test -C builddir <project_name>:<test_name>

# Run tests with verbose output
meson test -C builddir -v
```

## Code Style (.clang-format)
- Indent: 8 spaces using tabs
- Braces: Allman style (on new lines)
- Line length: 80 characters max
- Pointer alignment: Right aligned (int *p)
- No short if/blocks/functions on single line
- Always break after return type
- Function prototypes with void for no parameters
- Main function as `int main(void)` or `int main(int argc, string argv[])`

## C Coding Guidelines
- Include proper header guards (#ifndef/#define/#endif)
- Check return values and handle errors with clear messages
- Free all allocated memory to prevent leaks
- Declare variables at the top of their scope
- Add comments for complex logic and function purposes
- Validate all user input before processing

## Project Structure
- `/libs`: Shared libraries (cs50)
- `/projects`: Individual assignments
- Each project follows pattern:
  - `include/`: Header files
  - `src/`: Implementation
  - `test/`: Test files
