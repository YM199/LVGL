SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -std=gnu11")
SET(CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(/home/yangmou/Desktop/lv/src/lvgl)

aux_source_directory(. DIR_SRCS) #将当前c文件名添加至DIR_SRC
message("DIR_SRC : ${DIR_SRCS}")

add_subdirectory(gui)        #添加目录 lvgl
add_subdirectory(lvgl)        #添加目录 lvgl
#add_subdirectory(lv_demos) #添加目录 lv_examples
add_subdirectory(lv_drivers)  #添加目录 lv_drivers

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "./*.h" )

include_directories(./lvgl)  #设置头文件路劲
include_directories(./lv_drivers/)  #设置头文件路劲
include_directories(./gui/) #设置头文件路劲

get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> include_dirs=${dirs}") #打印一下目录情况
#include_directories(./lv_demos/src/lv_demo_music/)  #设置头文件路劲
#include_directories(./lv_demos/src/lv_demo_widgets/)  #设置头文件路劲
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