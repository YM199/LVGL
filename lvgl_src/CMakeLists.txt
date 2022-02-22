cmake_minimum_required(VERSION 3.16)
set(CMAKE_BUILD_TYPE "Debug") #当前是debug版本
set(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -std=gnu11") #debug版本的编译选项
set(CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=gnu11") #release版本的编译选项

#设置文件保存路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) #可执行二进制的输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) #库的输出路径

#设置头文件路劲
include_directories(lvgl/)
include_directories(lv_drivers/)
include_directories(gui/)


file(GLOB_RECURSE INCLUDES "./*.h" ) #获取lvg_src目录下的全部的头文件
#message("INCLUDES : ${INCLUDES}")
aux_source_directory(. DIR_SRCS) #将当前目录的全部源文件添加至DIR_SRC
message("DIR_SRC : ${DIR_SRCS}")

#set(VAR lv_examples_lib)
set(VAR ${VAR} lvgl_lib)
set(VAR ${VAR} lv_drivers_lib)
set(VAR ${VAR} gui_lib)
message("VAR : ${VAR}")

add_executable(little_prj ${DIR_SRCS})  #链接生成文件little_prj 由DIR_SRC链接。

#链接lvgl_lib lv_drivers_lib gui_lib
target_link_libraries(little_prj ${VAR})   #设置链接little_prj的依赖关系 ，依赖 VAR = lvgl_lib lv_drivers

#链接lpthread
find_package(Threads)
target_link_libraries(little_prj ${CMAKE_THREAD_LIBS_INIT})
message("CMAKE_THREAD_LIBS_INIT : ${CMAKE_THREAD_LIBS_INIT}")

#添加一个子目录并构建该子目录
add_subdirectory(gui)
add_subdirectory(lvgl)
add_subdirectory(lv_drivers)