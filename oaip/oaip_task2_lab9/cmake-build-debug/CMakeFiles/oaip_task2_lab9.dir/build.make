# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\clion\oaip_task2_lab9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\clion\oaip_task2_lab9\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/oaip_task2_lab9.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/oaip_task2_lab9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oaip_task2_lab9.dir/flags.make

CMakeFiles/oaip_task2_lab9.dir/main.cpp.obj: CMakeFiles/oaip_task2_lab9.dir/flags.make
CMakeFiles/oaip_task2_lab9.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\clion\oaip_task2_lab9\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oaip_task2_lab9.dir/main.cpp.obj"
	C:\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\oaip_task2_lab9.dir\main.cpp.obj -c D:\clion\oaip_task2_lab9\main.cpp

CMakeFiles/oaip_task2_lab9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oaip_task2_lab9.dir/main.cpp.i"
	C:\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\clion\oaip_task2_lab9\main.cpp > CMakeFiles\oaip_task2_lab9.dir\main.cpp.i

CMakeFiles/oaip_task2_lab9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oaip_task2_lab9.dir/main.cpp.s"
	C:\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\clion\oaip_task2_lab9\main.cpp -o CMakeFiles\oaip_task2_lab9.dir\main.cpp.s

# Object files for target oaip_task2_lab9
oaip_task2_lab9_OBJECTS = \
"CMakeFiles/oaip_task2_lab9.dir/main.cpp.obj"

# External object files for target oaip_task2_lab9
oaip_task2_lab9_EXTERNAL_OBJECTS =

oaip_task2_lab9.exe: CMakeFiles/oaip_task2_lab9.dir/main.cpp.obj
oaip_task2_lab9.exe: CMakeFiles/oaip_task2_lab9.dir/build.make
oaip_task2_lab9.exe: CMakeFiles/oaip_task2_lab9.dir/linklibs.rsp
oaip_task2_lab9.exe: CMakeFiles/oaip_task2_lab9.dir/objects1.rsp
oaip_task2_lab9.exe: CMakeFiles/oaip_task2_lab9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\clion\oaip_task2_lab9\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable oaip_task2_lab9.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\oaip_task2_lab9.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oaip_task2_lab9.dir/build: oaip_task2_lab9.exe
.PHONY : CMakeFiles/oaip_task2_lab9.dir/build

CMakeFiles/oaip_task2_lab9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\oaip_task2_lab9.dir\cmake_clean.cmake
.PHONY : CMakeFiles/oaip_task2_lab9.dir/clean

CMakeFiles/oaip_task2_lab9.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\clion\oaip_task2_lab9 D:\clion\oaip_task2_lab9 D:\clion\oaip_task2_lab9\cmake-build-debug D:\clion\oaip_task2_lab9\cmake-build-debug D:\clion\oaip_task2_lab9\cmake-build-debug\CMakeFiles\oaip_task2_lab9.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/oaip_task2_lab9.dir/depend

