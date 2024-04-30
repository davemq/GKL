project(GKL)
cmake_minimum_required(VERSION 2.8)

# add jni include path
find_package(Java 1.8 REQUIRED)
find_package(JNI)
include_directories(${JNI_INCLUDE_DIRS})

# common compiler and linker settings
if (NOT CMAKE_SYSTEM_PROCESSOR STREQUAL ppc64le)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2 ")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 ")
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "ppc64le")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat -Werror=format-security -Wfloat-conversion -Wbool-compare")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat -Werror=format-security -Wconversion -Wfloat-conversion -Wbool-compare")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-all ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-overflow -fno-delete-null-pointer-checks -fwrapv ")
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "ppc64le")
  string(APPEND CMAKE_CXX_FLAGS " -I${PROJECT_SOURCE_DIR}")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
if(APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++")
elseif(UNIX)
  set(CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++ -static-libgcc -Wl,-z,now")
endif()
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")

# add CMakeLists.txt in subdirectories
set(NATIVE_DIR ${PROJECT_SOURCE_DIR}/src/main/native)

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
add_subdirectory("${NATIVE_DIR}/compression")
endif()
add_subdirectory("${NATIVE_DIR}/pairhmm")
if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
add_subdirectory("${NATIVE_DIR}/utils")
add_subdirectory("${NATIVE_DIR}/smithwaterman")
add_subdirectory("${NATIVE_DIR}/pdhmm")
endif()
