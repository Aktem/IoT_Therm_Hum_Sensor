/*
Author: Matthew Love
Date: May 7, 2022
*/

#ifndef APP_NVS_H
#define APP_NVS_H

/*
Save station mode Wifi cred. to NVS
@return ESP_OK if success
*/
esp_err_t app_nvs_save_sta_creds(void);

/*
Loads the prev. saved cred from NVS
@return true if prev saved creds were found
*/
bool app_nvs_load_sta_creds(void);

/*
Clears sta mode cred. from NVS
@return ESP_OK if success
*/
esp_err_t app_nvs_clear_sta_creds(void);
#endif