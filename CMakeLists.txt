cmake_minimum_required(VERSION 3.2)
project(otus_2 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
#project(otus_2)
#enable_testing()
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)
#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)

add_executable(otus_2_cli main.cpp ip_filter.cpp ip_filter.h)
#add_executable(otus2_test ip_filter.cpp ip_filter.h gtest.cpp)
#target_link_libraries(otus_2_cli gtest gtest_main)
#target_link_libraries(otus2_test gtest gtest_main)

set_target_properties(otus_2_cli PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )


if (MSVC)

else ()
    target_compile_options(otus_2_cli PRIVATE
            -Wall -Wextra -pedantic -O4
            )
#    target_compile_options(otus2_test PRIVATE
#            -Wall -Wextra -pedantic -O4
#            )
endif()

install(TARGETS otus_2_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

#add_test(otus2_test otus2_test)