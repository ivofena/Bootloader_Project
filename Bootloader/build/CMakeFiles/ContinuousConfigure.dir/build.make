# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Rabita\AppData\Local\Programs\Python\Python37-32\Lib\site-packages\cmake\data\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Rabita\AppData\Local\Programs\Python\Python37-32\Lib\site-packages\cmake\data\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Tests\Bootloader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Tests\Bootloader\build

# Utility rule file for ContinuousConfigure.

# Include the progress variables for this target.
include CMakeFiles/ContinuousConfigure.dir/progress.make

CMakeFiles/ContinuousConfigure:
	C:\Users\Rabita\AppData\Local\Programs\Python\Python37-32\Lib\site-packages\cmake\data\bin\ctest.exe -D ContinuousConfigure

ContinuousConfigure: CMakeFiles/ContinuousConfigure
ContinuousConfigure: CMakeFiles/ContinuousConfigure.dir/build.make

.PHONY : ContinuousConfigure

# Rule to build all files generated by this target.
CMakeFiles/ContinuousConfigure.dir/build: ContinuousConfigure

.PHONY : CMakeFiles/ContinuousConfigure.dir/build

CMakeFiles/ContinuousConfigure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ContinuousConfigure.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousConfigure.dir/clean

CMakeFiles/ContinuousConfigure.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Tests\Bootloader C:\Tests\Bootloader C:\Tests\Bootloader\build C:\Tests\Bootloader\build C:\Tests\Bootloader\build\CMakeFiles\ContinuousConfigure.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousConfigure.dir/depend

