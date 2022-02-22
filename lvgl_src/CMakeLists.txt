SET(CMAKE_BUILD_TYPE "Debug") #当前是debug版本
SET(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -std=gnu11") #debug版本的编译选项
SET(CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=gnu11") #release版本的编译选项

#设置头文件路劲
include_directories(lvgl/)
include_directories(lv_drivers/)
include_directories(gui/)

file(GLOB_RECURSE INCLUDES "./*.h" ) #获取lvg;_src目录下的全部的头文件

aux_source_directory(. DIR_SRCS) #将当前目录的全部c文件添加至DIR_SRC
message("DIR_SRC : ${DIR_SRCS}")

#添加一个子目录并构建该子目录
add_subdirectory(gui)
add_subdirectory(lvgl)
add_subdirectory(lv_drivers)

add_executable(little_prj ${DIR_SRCS})  #链接生成文件little_prj 由DIR_SRC链接。
find_package(Threads)

#set(VAR lv_examples_lib)
set(VAR ${VAR} lvgl_lib)
set(VAR ${VAR} lv_drivers_lib)
set(VAR ${VAR} gui_lib)
message("VAR : ${VAR}")

target_link_libraries(little_prj ${VAR})   #设置链接little_prj的 依赖关系 ，依赖 VAR = lvgl_lib lv_drivers
#target_link_libraries(little_prj /home/cks/work/lvgl/tslib/libts.so)
#链接tslib的动态库
target_link_libraries(little_prj ${CMAKE_THREAD_LIBS_INIT})