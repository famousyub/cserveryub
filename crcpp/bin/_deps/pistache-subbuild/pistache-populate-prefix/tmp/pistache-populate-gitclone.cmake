
if(NOT "/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-subbuild/pistache-populate-prefix/src/pistache-populate-stamp/pistache-populate-gitinfo.txt" IS_NEWER_THAN "/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-subbuild/pistache-populate-prefix/src/pistache-populate-stamp/pistache-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-subbuild/pistache-populate-prefix/src/pistache-populate-stamp/pistache-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/oktal/pistache.git" "pistache-src"
    WORKING_DIRECTORY "/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/oktal/pistache.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout d4f85bd42a38202dd0687d485a90cc41d6c8c8d8 --
  WORKING_DIRECTORY "/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'd4f85bd42a38202dd0687d485a90cc41d6c8c8d8'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-subbuild/pistache-populate-prefix/src/pistache-populate-stamp/pistache-populate-gitinfo.txt"
    "/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-subbuild/pistache-populate-prefix/src/pistache-populate-stamp/pistache-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/user/Bureau/atmproject/moquito/crcpp/bin/_deps/pistache-subbuild/pistache-populate-prefix/src/pistache-populate-stamp/pistache-populate-gitclone-lastrun.txt'")
endif()

