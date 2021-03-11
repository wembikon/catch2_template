The purpose of `exe` is to provide debuggable executable that can be used
for learning how to debug a c++ cmake project for example when configuring
vscode.

##Setup cmake build:
- add `tasks.json` in .vscode in the workspace folder.
- using its current content, pres `shift+command+B` to build on mac.

##Setup intellisense for C/C++ extensions:
- press shift+command+P on mac and choose C/C++: Edit configuration and choose
JSON format. This will create `c_cpp_properties.json` into your .vscode folder.
- the default content should be enough but if you find some of the #include
in the code still displays the squigly, perhaps you need to manually add the
path in `includePath` for it to work.

##Debugging cmake project
- From the main menu, choose Run > Add Configuration... and then choose C++
(GDB/LLDB). This will create `launch.json` in your .vscode folder.
- set `program` to the absolute path of your executable that you want to debug.
- set `stopAtEntry` to true to cause the debugger to stop on the main method
when you start debugging.
- press `F5` to debug.

##References:
https://code.visualstudio.com/docs/cpp/config-clang-mac

##Shorter version
You just really have to open the folder that contains the root CMakeLists.txt
then select kit `screw driver and wrench icon`, target `the Build gear button`
and finally set the absolute executable path in the launch.json. Press only the
`bug` button to debug.

##Sample launch.json
```
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "clang++ - Build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "<absolute path to the executable>",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "lldb",
      "preLaunchTask": "C/C++: clang++ build active file"
    }
  ]
}
```
