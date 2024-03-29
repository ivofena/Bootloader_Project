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

# Include any dependencies generated for this target.
include CMakeFiles/boot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boot.dir/flags.make

CMakeFiles/boot.dir/bootloader.c.obj: CMakeFiles/boot.dir/flags.make
CMakeFiles/boot.dir/bootloader.c.obj: ../bootloader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Tests\Bootloader\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/boot.dir/bootloader.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\boot.dir\bootloader.c.obj   -c C:\Tests\Bootloader\bootloader.c

CMakeFiles/boot.dir/bootloader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boot.dir/bootloader.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Tests\Bootloader\bootloader.c > CMakeFiles\boot.dir\bootloader.c.i

CMakeFiles/boot.dir/bootloader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boot.dir/bootloader.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Tests\Bootloader\bootloader.c -o CMakeFiles\boot.dir\bootloader.c.s

CMakeFiles/boot.dir/crc32.c.obj: CMakeFiles/boot.dir/flags.make
CMakeFiles/boot.dir/crc32.c.obj: ../crc32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Tests\Bootloader\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/boot.dir/crc32.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\boot.dir\crc32.c.obj   -c C:\Tests\Bootloader\crc32.c

CMakeFiles/boot.dir/crc32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boot.dir/crc32.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Tests\Bootloader\crc32.c > CMakeFiles\boot.dir\crc32.c.i

CMakeFiles/boot.dir/crc32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boot.dir/crc32.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Tests\Bootloader\crc32.c -o CMakeFiles\boot.dir\crc32.c.s

CMakeFiles/boot.dir/sha256.c.obj: CMakeFiles/boot.dir/flags.make
CMakeFiles/boot.dir/sha256.c.obj: ../sha256.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Tests\Bootloader\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/boot.dir/sha256.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\boot.dir\sha256.c.obj   -c C:\Tests\Bootloader\sha256.c

CMakeFiles/boot.dir/sha256.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boot.dir/sha256.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Tests\Bootloader\sha256.c > CMakeFiles\boot.dir\sha256.c.i

CMakeFiles/boot.dir/sha256.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boot.dir/sha256.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Tests\Bootloader\sha256.c -o CMakeFiles\boot.dir\sha256.c.s

# Object files for target boot
boot_OBJECTS = \
"CMakeFiles/boot.dir/bootloader.c.obj" \
"CMakeFiles/boot.dir/crc32.c.obj" \
"CMakeFiles/boot.dir/sha256.c.obj"

# External object files for target boot
boot_EXTERNAL_OBJECTS =

libboot.a: CMakeFiles/boot.dir/bootloader.c.obj
libboot.a: CMakeFiles/boot.dir/crc32.c.obj
libboot.a: CMakeFiles/boot.dir/sha256.c.obj
libboot.a: CMakeFiles/boot.dir/build.make
libboot.a: CMakeFiles/boot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Tests\Bootloader\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libboot.a"
	$(CMAKE_COMMAND) -P CMakeFiles\boot.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\boot.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boot.dir/build: libboot.a

.PHONY : CMakeFiles/boot.dir/build

CMakeFiles/boot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\boot.dir\cmake_clean.cmake
.PHONY : CMakeFiles/boot.dir/clean

CMakeFiles/boot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Tests\Bootloader C:\Tests\Bootloader C:\Tests\Bootloader\build C:\Tests\Bootloader\build C:\Tests\Bootloader\build\CMakeFiles\boot.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boot.dir/depend

