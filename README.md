一、clone仓库

```shell
git clone https://github.com/YM199/LVGL.git
git submodule init  
git submodule update
```
二、设置头文件

在工程根目录执行以下语句

```shell
cp ./lvgl/lv_conf_template.h ./lv_conf.h
cp ./lv_drivers/lv_drv_conf_template.h lv_drv_conf.h
cp ./lv_demos/lv_demo_conf_template.h lv_demo_conf.h
```



将lv_conf.h、lv_drv_conf.h、lv_demo_conf.h的第10行的 `#if 0` 改为 `#if 1`

将lv_conf.h的`\#define LV_COLOR_DEPTH   32`改为`\#define LV_COLOR_DEPTH   16`
<font color=red>注意</font>：这里对应自己显示器的硬件配置。比如我的显示器是16的（RGB565）。

**lv_drv_conf.h**

```C
#  define USE_FBDEV           1 #改为1 使用framebuffer为/dev/fb0
#  define USE_EVDEV           1 #改为1 打开输入，使用/dev/input/event2
```

你的板子的输入事件可能不是event1，根据实际进行修改。可以使用cat命令来测试一下你板子的触摸屏输入对应的是哪一个event，如：

![](https://github.com/YM199/LVGL/blob/main/image/image-20210612173308112.png?raw=true)

此时，触摸一下屏幕，则终端会有信息（乱码信息）输出，则说明当前板子的触摸输入对应的就是这个event。



**lv_ex_conf.h**

主函数调用哪个demo，就把哪个demo的宏定义设置为1，例如

```C
/*Printer demo, optimized for 800x480*/
#define LV_USE_DEMO_PRINTER     1
```











目前的github版本有一些bug，比如如下图：

![](https://github.com/YM199/LVGL/blob/main/image/image-20210627163848018.png?raw=true)

这是属于语法错误了，只需要对着错误改掉就行。





遇见`error: ‘lv_font_montserrat_xx’ undeclared (first use in this function);`，只需要去lv_conf.h将对应的宏定义

`#define LV_FONT_MONTSERRAT_xx  1`打开就行

