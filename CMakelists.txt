cmake_minimum_required(VERSION 3.10)
project(gtest_example)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 커버리지 플래그 추가
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

# Google Test 설정
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# 소스 파일 추가
set(SOURCE_FILES
    src/main.cpp
)

# 실행 파일 생성
add_executable(gtest_example ${SOURCE_FILES})

# Google Test 링크
target_link_libraries(gtest_example
    GTest::gtest
    GTest::gtest_main
)

# 테스트 활성화
enable_testing()
add_test(NAME gtest_example COMMAND gtest_example)