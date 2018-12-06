enable_testing()

set(TARGET_NAME codec_tests)
set(src codec_test.cc)

add_executable(${TARGET_NAME} ${src})

target_link_libraries(${TARGET_NAME}
                           PRIVATE
                              GTest::GTest
                              GTest::Main)

target_include_directories(${TARGET_NAME}
                               PRIVATE
                                  ${PROJECT_SOURCE_DIR})

add_test(${TARGET_NAME} ${TARGET_NAME})
