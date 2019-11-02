cmake_minimum_required(VERSION 2.8)
project(vescuart)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Boost REQUIRED COMPONENTS 
    system 
    thread)

###########
# library #
###########

set(VESCUART_SOURCES
    src/Vesc.cpp
    src/VescMessage.cpp
    src/VescMotor.cpp
)

include_directories(include
    ${Boost_INCLUDE_DIRS})

add_library(vescuart SHARED ${VESCUART_SOURCES})
target_link_libraries(vescuart
    ${Boost_LIBRARIES})

#add_library(vescuart_static STATIC ${VESCUART_SOURCES})
#target_link_libraries(vescuart_static
#    ${Boost_LIBRARIES})


###################
# install library #
###################

install(TARGETS vescuart
        EXPORT vescuartTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

install(DIRECTORY include/vescuart
        DESTINATION include ${CMAKE_INSTALL_INCLUDEDIR})


#######################
# install cmake stuff #
#######################

include(CMakePackageConfigHelpers)

set(INCLUDE_INSTALL_DIR include/)
set(LIB_INSTALL_DIR lib/)
set(SYSCONFIG_INSTALL_DIR etc/vescuart/)

install(EXPORT vescuartTargets
        FILE vescuartTargets.cmake
        NAMESPACE vescuart::
        DESTINATION ${LIB_INSTALL_DIR}/cmake/vescuart)

configure_package_config_file(VescuartConfig.cmake
                           ${CMAKE_CURRENT_BINARY_DIR}/VescuartConfig.cmake
                            INSTALL_DESTINATION ${LIB_INSTALL_DIR}/cmake/vescuart
                            PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR)

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/VescuartConfigVersion.cmake
                                COMPATIBILITY SameMajorVersion
                                VERSION 0.0.1)


install(FILES ${CMAKE_CURRENT_BINARY_DIR}/VescuartConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/VescuartConfigVersion.cmake
    DESTINATION ${LIB_INSTALL_DIR}/cmake/vescuart)
