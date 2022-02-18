# LVGL移植

## 一、clone仓库

```shell
git clone https://github.com/YM199/LVGL.git
cd LVGL/
git submodule update --init --recursive
```

## 二、设置头文件

在工程根目录执行以下语句

```shell
cp ./lvgl/lv_conf_template.h ./lv_conf.h
cp ./lv_drivers/lv_drv_conf_template.h lv_drv_conf.h
cp ./lv_demos/lv_demo_conf_template.h lv_demo_conf.h
```

将lv_conf.h、lv_drv_conf.h、lv_demo_conf.h的第10行的 `#if 0` 改为 `#if 1`

将lv_conf.h的`\#define LV_COLOR_DEPTH   32`改为`\#define LV_COLOR_DEPTH   16`
注意：这里对应自己显示器的硬件配置。比如我的显示器是16的（RGB565）。

### lv_drv_conf.h

```C
#  define USE_FBDEV 1 /*改为1 使用framebuffer为/dev/fb0*/
#  define USE_EVDEV 1 /*改为1 打开输入，使用/dev/input/event2*/
```

>具体是哪个设备就改为哪个设备

你的板子的输入事件可能不是event1，根据实际进行修改。可以使用cat命令来测试一下你板子的触摸屏输入对应的是哪一个event，如：

![输入设备](image/image-20210612173308112.png)

此时，触摸一下屏幕，则终端会有信息（乱码信息）输出，则说明当前板子的触摸输入对应的就是这个event。

### lv_demo_conf.h

主函数调用哪个demo，就把哪个demo的宏定义设置为1，例如

```C
#define LV_USE_DEMO_STRESS   1
```

> 默认 music demo是打开的，关闭所有demo，我书写了个简单的测试demo

![错误](image/image-20210627163848018.png)

将 . 改为->
> 这是个指针成员，不知道为什么源代码要用 . 来指向。

遇见`error: ‘lv_font_montserrat_xx’ undeclared (first use in this function);`，只需要去lv_conf.h将对应的宏定义`#define LV_FONT_MONTSERRAT_xx  1`打开就行。

最终生成的可执行文件为demo。
