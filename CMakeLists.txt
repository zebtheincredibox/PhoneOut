cmake_minimum_required(VERSION 3.13.4)

# Define Mod ID and Project
set(MOD_ID "zebtheincredibox.phoneout")
project(PhoneOut VERSION 1.0.0)

# Ensure CMake can find the Geode SDK in the GitHub Action environment
if(NOT DEFINED GEODE_SDK)
    set(GEODE_SDK $ENV{GEODE_SDK})
endif()

# Find Geode package with explicit path
find_package(Geode REQUIRED PATHS ${GEODE_SDK})

# Source files
add_geode_mod(
    ${MOD_ID}
    SOURCES 
        src/main.cpp
)

# Finalize platform-specific setup (Windows/Android)
setup_geode_mod(${MOD_ID})
