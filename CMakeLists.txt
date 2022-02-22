cmake_minimum_required(VERSION 3.16)
#工程名
project(lvgl_prj)
#设置编译器，此处为ARM平台，如果你安装了编译链就用名称，没安装请用绝对路径
set(CMAKE_C_COMPILER "/usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc")
#添加lvgl_src目录
add_subdirectory(lvgl_src)

#创建make copy
add_custom_command(OUTPUT cpoy_file
                   COMMAND cp lvgl_src/little_prj /home/yangmou/linux/nfs/rootfs/yangmou/)
add_custom_target(copy DEPENDS cpoy_file)



