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
CMAKE_SOURCE_DIR = E:\Projects\CG_Labs\LR1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Projects\CG_Labs\LR1\build

# Include any dependencies generated for this target.
include CMakeFiles/LR1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LR1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LR1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LR1.dir/flags.make

CMakeFiles/LR1.dir/Source.cpp.obj: CMakeFiles/LR1.dir/flags.make
CMakeFiles/LR1.dir/Source.cpp.obj: ../Source.cpp
CMakeFiles/LR1.dir/Source.cpp.obj: CMakeFiles/LR1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projects\CG_Labs\LR1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LR1.dir/Source.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LR1.dir/Source.cpp.obj -MF CMakeFiles\LR1.dir\Source.cpp.obj.d -o CMakeFiles\LR1.dir\Source.cpp.obj -c E:\Projects\CG_Labs\LR1\Source.cpp

CMakeFiles/LR1.dir/Source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LR1.dir/Source.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projects\CG_Labs\LR1\Source.cpp > CMakeFiles\LR1.dir\Source.cpp.i

CMakeFiles/LR1.dir/Source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LR1.dir/Source.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projects\CG_Labs\LR1\Source.cpp -o CMakeFiles\LR1.dir\Source.cpp.s

# Object files for target LR1
LR1_OBJECTS = \
"CMakeFiles/LR1.dir/Source.cpp.obj"

# External object files for target LR1
LR1_EXTERNAL_OBJECTS =

LR1.exe: CMakeFiles/LR1.dir/Source.cpp.obj
LR1.exe: CMakeFiles/LR1.dir/build.make
LR1.exe: CMakeFiles/LR1.dir/linklibs.rsp
LR1.exe: CMakeFiles/LR1.dir/objects1.rsp
LR1.exe: CMakeFiles/LR1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projects\CG_Labs\LR1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LR1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LR1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LR1.dir/build: LR1.exe
.PHONY : CMakeFiles/LR1.dir/build

CMakeFiles/LR1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LR1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LR1.dir/clean

CMakeFiles/LR1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projects\CG_Labs\LR1 E:\Projects\CG_Labs\LR1 E:\Projects\CG_Labs\LR1\build E:\Projects\CG_Labs\LR1\build E:\Projects\CG_Labs\LR1\build\CMakeFiles\LR1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LR1.dir/depend
