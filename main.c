#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include "lv_demos/lv_demo.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h> 
#include <sys/time.h>

#define DISP_HOR_RES 800
#define DISP_VER_RES 480
 

#define MY_DISP_HOR_RES 800
#define MY_DISP_VER_RES 480




int main(void)
{
    /*LittlevGL init*/
    lv_init();
    /*Linux frame buffer device init*/
    fbdev_init();

     /*初始化图像数据缓存区*/
     static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf1_1[DISP_HOR_RES * 100];
    static lv_color_t buf1_2[DISP_HOR_RES * 100];
    lv_disp_draw_buf_init(&draw_buf, buf1_1, buf1_2, DISP_HOR_RES * 100);

    lv_disp_drv_t disp_drv;               /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);          /*Basic initialization*/
    disp_drv.flush_cb = fbdev_flush;    /*Set your driver function*/
    disp_drv.draw_buf = &draw_buf;          /*Assign the buffer to the display*/
    disp_drv.hor_res = MY_DISP_HOR_RES;   /*Set the horizontal resolution of the display*/
    disp_drv.hor_res = MY_DISP_VER_RES;   /*Set the verizontal resolution of the display*/
    lv_disp_drv_register(&disp_drv);      /*Finally register the driver*/

    lv_indev_drv_t indev_drv;                  /*Descriptor of a input device driver*/
    lv_indev_drv_init(&indev_drv);             /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
    indev_drv.read_cb = evdev_read;      /*Set your driver function*/
    lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/


    lv_demo_widgets();
    while (1)
    {
        lv_tick_inc(5);
        lv_task_handler();
        usleep(5000);        
    }
}




