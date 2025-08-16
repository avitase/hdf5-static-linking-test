cmake_minimum_required(VERSION 3.21)

project(
        test
        VERSION 0.1.0
        LANGUAGES C CXX
)

# ---- Declare library ----

add_library(
        test_lib OBJECT
        source/test.cpp
)

target_include_directories(
        test_lib
        PUBLIC
        "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(test_lib PUBLIC cxx_std_23)


# ---- Dependencies ----

find_package(ZLIB 1.3.1 EXACT REQUIRED)
find_package(HDF5 1.14.6 EXACT REQUIRED COMPONENTS C)

target_link_libraries(
        test_lib
        PUBLIC
        hdf5::hdf5
        ZLIB::ZLIB
)


# ---- Declare executable ----

add_executable(test_exe source/main.cpp)
add_executable(test::exe ALIAS test_exe)

set_property(TARGET test_exe PROPERTY OUTPUT_NAME test)

target_compile_features(test_exe PRIVATE cxx_std_23)
target_link_libraries(test_exe PRIVATE test_lib)


# ---- Install rules ----

if (NOT CMAKE_SKIP_INSTALL_RULES)
    install(TARGETS test_exe RUNTIME COMPONENT test_Runtime)

    if (PROJECT_IS_TOP_LEVEL)
        include(CPack)
    endif ()
endif ()
