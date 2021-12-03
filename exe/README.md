Debugging C++ Cmake Projects

Probably the most used use-case is to debug a particular Cmake Target, whether it is the application or the unit test. So, this tutorial teaches how to debug a cmake target.

1. First, make sure that you have configured your toolchain (compiler, linker, debugger etc.).
    1. On Mac, these are xcode and cmake etc, in Linux, these are build-essential, gdb etc.
    2. This link teaches about configuring a cmake project on linux https://code.visualstudio.com/docs/cpp/cmake-linux but most of the steps also applies to Mac.
2. Install vscode extensions for Cmake and C++. See “Prerequisite” section in the link above.
3. Open your project. Make sure the root directory contains the CMakeLists.txt file.
4. Select a kit (compiler) to be used for building and debugging. See “Select a kit” in the link above.
5. Select a variant (mode). See “Select a variant” in the link above. After selecting this and the kit, your project will automatically be configured. If not, press cmd+shift+P then run CMake:Configure.
6. In Vscode, press the “Play with a Bug” button to open the debug panel. In the panel, press “create launch.json”. Although this is optional for basic cases, we need to use a launch.json to control more things like arguments to pass to the executable when debugging. This link teaches that. https://vector-of-bool.github.io/docs/vscode-cmake-tools/debugging.html
    - key take aways on what fields to modify:
        - the “program” field specifies the executable to launch when debugging or attaching executable. by setting it to this, vscode automatically replaces it with the CMake target’s path.
		"program": "${command:cmake.launchTargetPath}",
        - “args” let’s you specify the arguments to the executable. You’ll have to modify this depending on the target.
		"args": ["-t", "SkipTo/ShouldSkipToNextTrack"],
        - “environment” > “PATH” - adds the directory where our target was built to the PATH environment variable. This go hand in hand with “${command:cmake.launchTargetPath}” value so it will be found.
                "environment": [
                   {
                     "name": "PATH",
                     "value": "$PATH:${command:cmake.launchTargetDirectory}"
                   }
                 ],
7. Probably the most important step. In Vscode Debug panel, press the drop down menu near the green Play (triangle) button to add a new configuration. Choose “lldb Launch” and add all the settings above to the new configuration.
8. Press the Play (triangle) button. To verify that it is running the particular target and argument you passed, try to add a breakpoint to the specific part (e.g. unit test). If it stops at the breakpoint and when you resume the debugger it will stop, then your configuration is successful. Note: you cannot use the Bug button in the blue taskbar at the bottom, since they seem to not use launch.json. It is only use for quick build which just executes that target that you have chosen in the blue taskbar.
NOTE: use this instead of the Bug button in the blue taskbar to debug. At the time of this recording, the Bug button in the blue taskbar doesn’t show the content of the variable being debugged.

Running a CMake target
- You can do this by pressing the Triangle button in the blue task bar. But before do that, make sure to configure the variant, kit, build and debug target.
- If you want to pass command line arguments, you can set it in settings.json. Below is the whole content of my settings.json.
{
  "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
  "cmake.debugConfig": {
      "args": [
          "-t",
          "SkipTo/ShouldSkipToNextTrack"
      ]
  }
}

NOTE: use this for quick modify and run cycles.




















