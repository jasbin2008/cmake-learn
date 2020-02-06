# ./mod1/mod2/CMakeLists.txt
add_library(mod2 STATIC mod2.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

install(TARGETS mod2 ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)  # 安装到 usr/lib
install(FILES mod2.h DESTINATION include/mod2) # 安装到 usr/include/mod2
