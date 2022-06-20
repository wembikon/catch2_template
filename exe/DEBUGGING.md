# lldb

https://lldb.llvm.org/use/tutorial.html

tested on (lldb —version)
lldb-1200.0.44.2
Apple Swift version 5.3.2 (swiftlang-1200.0.45 clang-1200.0.32.28)

### loading directly from lldb command
lldb <path_to_executable> launch --stop-at-entry -- -t TestSuite/TestCase

### then you can set breakpoints by
breakpoint set --method ClassName::MethodName

### save the break points you have done so far by
breakpoint write -f my_breakpoints

### you can read this session by
breakpoint read -f my_breakpoints

####

## A better way is to write your commands into a file e.g. my_debug_session like as follows
### set the current executable
file <path_to_executable>
### launch the current executable with some options and program arguments (e.g. boost test case args)
process launch --stop-at-entry -- -t TestSuite/TestCase
### set a breakpoint
br s --method ClassName::MethodName

### then load the file by
lldb -S <path_to_command_file>
