cmake_minimum_required (VERSION 3.14)

project (today VERSION 0.0.1)

# Find the Boost library and the filesystem component
find_package(Boost 1.60 REQUIRED
	COMPONENTS
	filesystem
)

add_executable (today today.cc)

# Link the executable to the desired libraries
target_link_libraries (today Boost::filesystem)

# Install the binary into the host system
install(TARGETS today DESTINATION bin)
