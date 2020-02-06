# ./CMakeLists.txt

# 设置debug和release调试信息
set(CMAKE_C_FLAGS_DEBUG "-g -Wall -pedantic -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -pedantic -DDEBUG")
message(STATUS "debug flags: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "release flags: ${CMAKE_C_FLAGS_RELEASE}")

cmake_minimum_required(VERSION 3.5)
PROJECT(PROJECT_ONE)
add_subdirectory(mod1 lib)          # 添加一个模块，并且将编译好库文件放置在 build/lib 目录
add_executable(main main.cpp)
target_link_libraries(main mod1)    # 链接 mod1

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake) # find_package会在CMAKE_MODULE_PATH查找

# 连接 libxml2.lib
find_package(LIBXML2)
if(LIBXML2_FOUND)
    include_directories(${LIBXML2_INCLUDE_DIR})
    include_directories(/usr/local/include/libxml2)
    link_directories(/usr/local/lib)
    target_link_libraries(main xml2)
else(LIBXML2_FOUND)
    message(FATAL_ERROR "libxml2.so not be found!")
endif(LIBXML2_FOUND)

# 通过cmakeconfig.h传递参数给源文件
set(AUTHOR "user")
set(RELEASE_DATE "2019-11-06")
set(USE_MY_LIB "0")
configure_file(
    ${PROJECT_SOURCE_DIR}/cmakeconfig.h.in
    ${PROJECT_BINARY_DIR}/cmakeconfig.h
)
include_directories(${PROJECT_BINARY_DIR})


set(CMAKE_INSTALL_PREFIX /home/user/Source/hb) # 安装路径前缀
install(DIRECTORY doc/ DESTINATION share/PROJECT_ONE) #安装项目文档
install(TARGETS main RUNTIME DESTINATION bin) #main 安装到 /home/user/Source/hb/bin
