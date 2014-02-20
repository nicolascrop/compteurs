cmake_minimum_required(VERSION 2.8)
project(compteurs)
find_package(Boost
	     1.49.0
	     COMPONENTS
			program_options
	     REQUIRED)

link_directories(${Boost_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

SET (EXE_NAME
bin/compteurs
)

file(
  GLOB_RECURSE
  source_files
  src/*
)

add_executable(
  ${EXE_NAME}
  ${source_files}
)

target_link_libraries(
  ${EXE_NAME}
  ${Boost_LIBRARIES}
)
