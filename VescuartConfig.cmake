include("${CMAKE_CURRENT_LIST_DIR}/sialibTargets.cmake")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/Modules")

set(SIALIB_INCLUDE_DIRS
    @SIALIB_INSTALL_INCLUDE_DIRS@
)

set(SIALIB_DEFINITIONS "")
set(SIALIB_LIBRARIES sialib::sialib)
set(SIALIB_STATIC_LIBRARIES
    sialib::sialib_static
)

find_package(Boost REQUIRED)
list(APPEND SIALIB_INCLUDE_DIRS ${Boost_INCLUDE_DIRS})
list(APPEND SIALIB_DEFINITIONS ${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
list(APPEND SIALIB_LIBRARIES ${Boost_LIBRARIES})

set(SIALIB_FOUND TRUE)