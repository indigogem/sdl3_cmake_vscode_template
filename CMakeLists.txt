cmake_minimum_required(VERSION 3.29)

project(sdl3_cmake_vscode_template C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

message(STATUS "${CMAKE_MODULE_PATH}")

set(_source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(_lib_name ${PROJECT_NAME})
set( project_TARGETS
     ${_lib_name}
     standalone
   )

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
find_package(GLM MODULE REQUIRED)

message(STATUS "compiler options \"${_lib_name}\" with args:")
foreach(_opt ${CMAKE_CXX_FLAGS})
    message(STATUS "-- ${_opt}")
endforeach()

add_library(${_lib_name})

target_sources(${_lib_name}
    PRIVATE
        ${_source_dir}/defs.h
        ${_source_dir}/base/app.h
        ${_source_dir}/base/app.cpp
    )
    
target_link_libraries(${_lib_name} PUBLIC SDL3::SDL3-static GLM::GLM)

target_include_directories(${_lib_name} PUBLIC "${_source_dir}")

add_executable(standalone "${CMAKE_CURRENT_SOURCE_DIR}/src/standalone/main.cpp")


target_link_libraries(standalone PUBLIC ${_lib_name})


foreach( _target ${project_TARGETS} )
    target_compile_features(${_target} PRIVATE cxx_std_20)
endforeach()

# cmake --preset vs2022win64
# cmake --build --preset debug-win-x64


