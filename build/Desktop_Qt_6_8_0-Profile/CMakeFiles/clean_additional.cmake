# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles/password_manager_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/password_manager_autogen.dir/ParseCache.txt"
  "password_manager_autogen"
  )
endif()
