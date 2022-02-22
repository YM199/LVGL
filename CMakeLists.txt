cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_COMPILER "/usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc")

include_directories(/home/yangmou/Desktop/lv/src/lvgl)

#设置编译器，此处为ARM平台，如果你安装了编译链就用名称，没安装请用绝对路径
project(lvgl_prj)
#工程名
add_subdirectory(lvgl_src)
#添加src目录