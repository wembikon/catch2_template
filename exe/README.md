# Building, Running and Debugging C++ Cmake Projects on VSCode

## Building

1. Open the room cmake folder
2. On the command pallete - CMake: Select a Kit - select your toolchain (e.g. Clang 12.x.x)
   * You can also just click the "wrench" icon on the taskbar to select a kit.
3. On the command pallete - CMake: Select Variant - e.g. (Debug, Release etc.)
   * You can also just click the "exclamation mark" icon on the taskbar to choose a variant.
4. On the command pallete - CMake: Build Target - choose a cmake target.
   * You can also just click the text next to Build button on the taskbar to choose a target.

## Running

1. Select a cmake target to run next to the "triangle" button on the taskbar.
2. Just press the "triangle" button on the taskbar.
   * Tip: You can see the command being executed on the TERMINAL pane.
3. To pass arguments, very important for selecting a specific test case when running a unit
   test etc. On the command pallete - Preferences: Open Workspace Settings (JSON) and add the ff.
   object property at the end, next to the last property.
   * Note: This will create a `settings.json` file inside `${workspaceFolder}/.vscode/`.
```JSON
  "cmake.debugConfig": {
      "args": [
          "-t",
          "TestCaseName"
      ]
  }
```

## Debugging

There are basically 2 ways to run debug builds on VSCode.
1. Using the taskbar's Bug Icon. This one uses the workspace settings.json for its settings
   like passing arguments (uses cmake.debugConfig created in Running section) etc.
2. Using presets specified in the `${workspaceFolder}/.vscode/launch.json`. If you don't have
   a launch.json yet, you can press the "Bug on a Triangle" icon to open up the debug pane,
   then press on the drop down with a Triangle icon on top of that pane, then press
   "Add Configuration". This will automatically create the launch.json file and will ask you
   to choose what configuration section you want to add e.g. C/C++: (lldb) Attach or Launch
   etc. For now let's choose Launch section.
3. Change the launch section to have these values:
```JSON
   {
      "name": "(lldb) Launch",
      "type": "cppdbg",
      "request": "launch",
      "program": "${command:cmake.launchTargetPath}",
      "args": ["-t", "playernode/Expirement/expirement1"],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [{ "name": "PATH", "value": "$PATH:${command:cmake.launchTargetDirectory}" }],
      "externalConsole": false,
      "MIMode": "lldb"
    }
```
   * Note#1: ${command:cmake.launchTargetPath} value in "program" uses the Debug/Run (Bug/Triangle
     button) target that you chose in the taskbar. You can specify absolute path here if you want.
   * Note#2: "args", just like cmake.debugConfig, but only for this preset.
   * Note#3: "environment" value is needed to fine ${command:cmake.launchTargetPath} correctly.
   * Note#4: If you want to know more about each property, its available online.
4. Now, you can run the debug preset either on the taskbar or on the debug pane (Bug on Triangle
   button).






















