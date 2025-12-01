cmake_minimum_required(VERSION 3.20)

# Habilitamos C y C++
project(AudioScoreLang C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Para que genere compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ANTLR4 runtime
set(ANTLR4_RUNTIME_INCLUDE_DIR "/usr/include/antlr4-runtime")
set(ANTLR4_RUNTIME_LIB "antlr4-runtime")

# LLVM
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Fuentes generadas por ANTLR (los .cpp están en ../gen/grammar/src)
file(GLOB_RECURSE ANTLR_SOURCES
    "${CMAKE_SOURCE_DIR}/../gen/grammar/src/*.cpp"
)

# Fuentes propias
set(SRC_FILES
    ${CMAKE_SOURCE_DIR}/AudioMain.cpp
    ${CMAKE_SOURCE_DIR}/../runtime/runtime_audio_wav.c
)

add_executable(audioscorec
    ${SRC_FILES}
    ${ANTLR_SOURCES}
)

target_include_directories(audioscorec PRIVATE
    ${ANTLR4_RUNTIME_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}                  # donde están AudioMain.cpp / AudioDriver.h
    ${CMAKE_SOURCE_DIR}/../gen/grammar/src 
    ${LLVM_INCLUDE_DIRS}
)

# Enlazar ANTLR + LLVM
target_link_libraries(audioscorec PRIVATE
    ${ANTLR4_RUNTIME_LIB}
    LLVM
)
