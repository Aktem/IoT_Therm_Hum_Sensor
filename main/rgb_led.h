/*
Author: Matthew Love
Date: April 16, 2022
*/

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_

// RGB LED GPIOs
#define RGB_LED_RED_GPIO 21
#define RGB_LED_GREEN_GPIO 22
#define RGB_LED_BLUE_GPIO 23

// RGB LED color mix channels
#define RGB_LED_CHANNEL_NUM 3

// RGB LED Config
typedef struct
{
    /* data */
    int channel;
    int gpio;
    int mode;
    int timer_index;
} ledc_info_t;

ledc_info_t ledc_ch[RGB_LED_CHANNEL_NUM];

/*
Color to indicate WiFi application has started.
*/
void rgb_led_wifi_app_started(void);


/*
Color to indicate HTTP sever has started.
*/
void rgb_led_http_sever_started(void);

/*
Color to indicate that the ESPE32 is connected to an access point
*/
void rgb_led_wifi_connected(void);

#endif /* MAIN_RGB_LED_H_ */
