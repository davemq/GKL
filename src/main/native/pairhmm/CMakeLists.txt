set(VERBOSE 1)
#---------------------------------------------------------------------
# common
#---------------------------------------------------------------------
if(NOT APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-as-needed")
endif()

#---------------------------------------------------------------------
# common includes
#---------------------------------------------------------------------
include_directories(../common)

#---------------------------------------------------------------------
# pairhmm
#---------------------------------------------------------------------
set(TARGET power_pairhmm)
add_library(${TARGET} SHARED PowerPairHmm.cc)
install(TARGETS ${TARGET} DESTINATION ${CMAKE_BINARY_DIR})
