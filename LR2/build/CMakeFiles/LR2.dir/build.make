# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Qt\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = C:\Qt\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\CG_Labs\LR2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\CG_Labs\LR2\build

# Include any dependencies generated for this target.
include CMakeFiles/LR2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LR2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LR2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LR2.dir/flags.make

CMakeFiles/LR2.dir/main.cpp.obj: CMakeFiles/LR2.dir/flags.make
CMakeFiles/LR2.dir/main.cpp.obj: ../main.cpp
CMakeFiles/LR2.dir/main.cpp.obj: CMakeFiles/LR2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\CG_Labs\LR2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LR2.dir/main.cpp.obj"
	C:\Qt\Tools\mingw900_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LR2.dir/main.cpp.obj -MF CMakeFiles\LR2.dir\main.cpp.obj.d -o CMakeFiles\LR2.dir\main.cpp.obj -c D:\Projects\CG_Labs\LR2\main.cpp

CMakeFiles/LR2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LR2.dir/main.cpp.i"
	C:\Qt\Tools\mingw900_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\CG_Labs\LR2\main.cpp > CMakeFiles\LR2.dir\main.cpp.i

CMakeFiles/LR2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LR2.dir/main.cpp.s"
	C:\Qt\Tools\mingw900_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\CG_Labs\LR2\main.cpp -o CMakeFiles\LR2.dir\main.cpp.s

# Object files for target LR2
LR2_OBJECTS = \
"CMakeFiles/LR2.dir/main.cpp.obj"

# External object files for target LR2
LR2_EXTERNAL_OBJECTS =

LR2.exe: CMakeFiles/LR2.dir/main.cpp.obj
LR2.exe: CMakeFiles/LR2.dir/build.make
LR2.exe: CMakeFiles/LR2.dir/linklibs.rsp
LR2.exe: CMakeFiles/LR2.dir/objects1.rsp
LR2.exe: CMakeFiles/LR2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\CG_Labs\LR2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LR2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LR2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LR2.dir/build: LR2.exe
.PHONY : CMakeFiles/LR2.dir/build

CMakeFiles/LR2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LR2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LR2.dir/clean

CMakeFiles/LR2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\CG_Labs\LR2 D:\Projects\CG_Labs\LR2 D:\Projects\CG_Labs\LR2\build D:\Projects\CG_Labs\LR2\build D:\Projects\CG_Labs\LR2\build\CMakeFiles\LR2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LR2.dir/depend

