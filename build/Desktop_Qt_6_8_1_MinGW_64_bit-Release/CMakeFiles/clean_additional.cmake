# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\qt-sistema-de-estoque_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\qt-sistema-de-estoque_autogen.dir\\ParseCache.txt"
  "qt-sistema-de-estoque_autogen"
  )
endif()
