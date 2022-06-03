/*
Author: Matthew Love
Date: May 8, 2022
*/

#ifndef WIFI_RESET_BUTTON_
#define WIFI_RESET_BUTTON_

// Default interrupt flag
#define ESP_INTR_FLAG_DEFAULT 0

// Wifi reset button is the Boot button the dev kit
#define WIFI_RESET_BUTTON 0

/*
Configures Wifi reset button and interrupt configuration
*/
void wifi_reset_button_config(void);

#endif