set(COMPILER_WARNING_OPTIONS -Wall -Wextra -pedantic-errors)
if (psqlxx_WARNINGS_AS_ERRORS)
    list(APPEND COMPILER_WARNING_OPTIONS -Werror)
endif ()

configure_file(version.cpp.in version.cpp @ONLY)
add_library(psqlxx_version STATIC ${CMAKE_CURRENT_BINARY_DIR}/version.cpp version.hpp)
add_library(psqlxx::version ALIAS psqlxx_version)
set_target_properties(psqlxx_version PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_compile_options(psqlxx_version PRIVATE ${COMPILER_WARNING_OPTIONS})

add_library(psqlxx_psqlxx args.cpp args.hpp)
add_library(psqlxx::psqlxx ALIAS psqlxx_psqlxx)
target_link_libraries(
    psqlxx_psqlxx
    PRIVATE psqlxx::version
    PUBLIC cxxopts)
target_compile_options(psqlxx_psqlxx PUBLIC ${COMPILER_WARNING_OPTIONS})

add_executable(psqlxx_main main.cpp)
add_executable(psqlxx::main ALIAS psqlxx_main)
target_link_libraries(psqlxx_main PRIVATE psqlxx::psqlxx)
set_target_properties(psqlxx_main PROPERTIES OUTPUT_NAME psqlxx)

add_test(NAME psqlxx.main.can_display_help COMMAND psqlxx_main --help)
add_test(NAME psqlxx.main.can_display_version COMMAND psqlxx_main --version)
enable_auto_test_command(psqlxx_main ^psqlxx.main)
enable_auto_test_command(psqlxx_main ^psqlxx.real_db.psql_diff$)

discover_gtest_for(args psqlxx::psqlxx)

if (psqlxx_WANT_INSTALLER)
    install(
        TARGETS psqlxx_main
        EXPORT psqlxx_apps
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT psqlxx_apps)
endif ()
