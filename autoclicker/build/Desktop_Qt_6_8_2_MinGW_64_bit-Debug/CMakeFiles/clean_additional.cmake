# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\autoclicker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\autoclicker_autogen.dir\\ParseCache.txt"
  "autoclicker_autogen"
  )
endif()
