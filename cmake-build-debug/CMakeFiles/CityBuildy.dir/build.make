# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bar/Documents/school/yearB/CityBuildy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CityBuildy.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CityBuildy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CityBuildy.dir/flags.make

CMakeFiles/CityBuildy.dir/src/main.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CityBuildy.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/main.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/main.cpp

CMakeFiles/CityBuildy.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/main.cpp > CMakeFiles/CityBuildy.dir/src/main.cpp.i

CMakeFiles/CityBuildy.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/main.cpp -o CMakeFiles/CityBuildy.dir/src/main.cpp.s

CMakeFiles/CityBuildy.dir/src/Controller.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/Controller.cpp.o: ../src/Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CityBuildy.dir/src/Controller.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/Controller.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/Controller.cpp

CMakeFiles/CityBuildy.dir/src/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/Controller.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/Controller.cpp > CMakeFiles/CityBuildy.dir/src/Controller.cpp.i

CMakeFiles/CityBuildy.dir/src/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/Controller.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/Controller.cpp -o CMakeFiles/CityBuildy.dir/src/Controller.cpp.s

CMakeFiles/CityBuildy.dir/src/Resources.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/Resources.cpp.o: ../src/Resources.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CityBuildy.dir/src/Resources.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/Resources.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/Resources.cpp

CMakeFiles/CityBuildy.dir/src/Resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/Resources.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/Resources.cpp > CMakeFiles/CityBuildy.dir/src/Resources.cpp.i

CMakeFiles/CityBuildy.dir/src/Resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/Resources.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/Resources.cpp -o CMakeFiles/CityBuildy.dir/src/Resources.cpp.s

CMakeFiles/CityBuildy.dir/src/window.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CityBuildy.dir/src/window.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/window.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/window.cpp

CMakeFiles/CityBuildy.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/window.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/window.cpp > CMakeFiles/CityBuildy.dir/src/window.cpp.i

CMakeFiles/CityBuildy.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/window.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/window.cpp -o CMakeFiles/CityBuildy.dir/src/window.cpp.s

CMakeFiles/CityBuildy.dir/src/Button.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/Button.cpp.o: ../src/Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CityBuildy.dir/src/Button.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/Button.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/Button.cpp

CMakeFiles/CityBuildy.dir/src/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/Button.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/Button.cpp > CMakeFiles/CityBuildy.dir/src/Button.cpp.i

CMakeFiles/CityBuildy.dir/src/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/Button.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/Button.cpp -o CMakeFiles/CityBuildy.dir/src/Button.cpp.s

CMakeFiles/CityBuildy.dir/src/Menu.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/Menu.cpp.o: ../src/Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CityBuildy.dir/src/Menu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/Menu.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/Menu.cpp

CMakeFiles/CityBuildy.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/Menu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/Menu.cpp > CMakeFiles/CityBuildy.dir/src/Menu.cpp.i

CMakeFiles/CityBuildy.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/Menu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/Menu.cpp -o CMakeFiles/CityBuildy.dir/src/Menu.cpp.s

CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.o: ../src/MainMenu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/MainMenu.cpp

CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/MainMenu.cpp > CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.i

CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/MainMenu.cpp -o CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.s

CMakeFiles/CityBuildy.dir/src/TileMap.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/TileMap.cpp.o: ../src/TileMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CityBuildy.dir/src/TileMap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/TileMap.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/TileMap.cpp

CMakeFiles/CityBuildy.dir/src/TileMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/TileMap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/TileMap.cpp > CMakeFiles/CityBuildy.dir/src/TileMap.cpp.i

CMakeFiles/CityBuildy.dir/src/TileMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/TileMap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/TileMap.cpp -o CMakeFiles/CityBuildy.dir/src/TileMap.cpp.s

CMakeFiles/CityBuildy.dir/src/Mouse.cpp.o: CMakeFiles/CityBuildy.dir/flags.make
CMakeFiles/CityBuildy.dir/src/Mouse.cpp.o: ../src/Mouse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CityBuildy.dir/src/Mouse.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CityBuildy.dir/src/Mouse.cpp.o -c /Users/bar/Documents/school/yearB/CityBuildy/src/Mouse.cpp

CMakeFiles/CityBuildy.dir/src/Mouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CityBuildy.dir/src/Mouse.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/Documents/school/yearB/CityBuildy/src/Mouse.cpp > CMakeFiles/CityBuildy.dir/src/Mouse.cpp.i

CMakeFiles/CityBuildy.dir/src/Mouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CityBuildy.dir/src/Mouse.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/Documents/school/yearB/CityBuildy/src/Mouse.cpp -o CMakeFiles/CityBuildy.dir/src/Mouse.cpp.s

# Object files for target CityBuildy
CityBuildy_OBJECTS = \
"CMakeFiles/CityBuildy.dir/src/main.cpp.o" \
"CMakeFiles/CityBuildy.dir/src/Controller.cpp.o" \
"CMakeFiles/CityBuildy.dir/src/Resources.cpp.o" \
"CMakeFiles/CityBuildy.dir/src/window.cpp.o" \
"CMakeFiles/CityBuildy.dir/src/Button.cpp.o" \
"CMakeFiles/CityBuildy.dir/src/Menu.cpp.o" \
"CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.o" \
"CMakeFiles/CityBuildy.dir/src/TileMap.cpp.o" \
"CMakeFiles/CityBuildy.dir/src/Mouse.cpp.o"

# External object files for target CityBuildy
CityBuildy_EXTERNAL_OBJECTS =

CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/main.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/Controller.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/Resources.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/window.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/Button.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/Menu.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/MainMenu.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/TileMap.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/src/Mouse.cpp.o
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/build.make
CityBuildy.app/Contents/MacOS/CityBuildy: /Library/Frameworks/./sfml-graphics.framework/Versions/2.5.1/sfml-graphics
CityBuildy.app/Contents/MacOS/CityBuildy: /Library/Frameworks/./sfml-audio.framework/Versions/2.5.1/sfml-audio
CityBuildy.app/Contents/MacOS/CityBuildy: /Library/Frameworks/./sfml-window.framework/Versions/2.5.1/sfml-window
CityBuildy.app/Contents/MacOS/CityBuildy: /Library/Frameworks/./sfml-system.framework/Versions/2.5.1/sfml-system
CityBuildy.app/Contents/MacOS/CityBuildy: CMakeFiles/CityBuildy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable CityBuildy.app/Contents/MacOS/CityBuildy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CityBuildy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CityBuildy.dir/build: CityBuildy.app/Contents/MacOS/CityBuildy
.PHONY : CMakeFiles/CityBuildy.dir/build

CMakeFiles/CityBuildy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CityBuildy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CityBuildy.dir/clean

CMakeFiles/CityBuildy.dir/depend:
	cd /Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bar/Documents/school/yearB/CityBuildy /Users/bar/Documents/school/yearB/CityBuildy /Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug /Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug /Users/bar/Documents/school/yearB/CityBuildy/cmake-build-debug/CMakeFiles/CityBuildy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CityBuildy.dir/depend

