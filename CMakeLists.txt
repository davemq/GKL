cmake_minimum_required(VERSION 2.8)

# add jni include path
find_package(Java 1.8 REQUIRED)
find_package(JNI)
include_directories(${JNI_INCLUDE_DIRS})

# common compiler and linker settings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mcpu=power9 -mtune=power9 -mvsx")
set(CMAKE_CXX_COMPILER "/opt/at15.0/bin/c++")
set(CMAKE_C_COMPILER "/opt/at15.0/bin/cc")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
if(APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++")
elseif(UNIX)
  set(CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++ -static-libgcc -Wl,-z,now")
endif()
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")

# add CMakeLists.txt in subdirectories
set(NATIVE_DIR ${PROJECT_SOURCE_DIR}/src/main/native)

add_subdirectory("${NATIVE_DIR}/pairhmm")
