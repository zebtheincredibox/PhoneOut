cmake_minimum_required(VERSION 3.13.4)

# Define the project
project(PhoneOut VERSION 1.0.0)

# Find the Geode SDK (Required for GD Modding)
find_package(Geode REQUIRED)

# Set your Mod ID from mod.json
set(MOD_ID "zebtheincredibox.phoneout")

# Add the source files
add_geode_mod(
    ${MOD_ID}
    SOURCES 
        src/main.cpp
)

# Setup the mod for Windows and Android
setup_geode_mod(${MOD_ID})
