/*
Author: Matthew Love
Date: May 8, 2022
*/

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "lwip/apps/sntp.h"

#include "task_common.h"
#include "http_server.h"
#include "sntp_time_sync.h"
#include "wifi_app.h"

static const char TAG[] = "sntp_time_sync";

// SNTP operating mode set status
static bool sntp_op_mode_set = false;

/*
Init SNTP service using SNTP_OPMODE_POLL mode
*/
static void sntp_time_sync_init_sntp(void)
{
    ESP_LOGI(TAG, "Initializing the SNTP service");

    if (!sntp_op_mode_set)
    {
        // Set the operating mode
        sntp_setoperatingmode(SNTP_OPMODE_POLL);
        sntp_op_mode_set = true;
    }

    sntp_setservername(0, "pool.ntp.org");

    // Init the server
    sntp_init();

    // Let the http_server know service is initialized
    http_server_monitor_send_message(HTTP_MSG_TIME_SERVICE_INITIALIZED);
}

/*
Gets the current time and if the current itme is not up to dat, the
sntp_time_synch_init_sntp function gets called.
*/
static void sntp_time_sync_obtain_time(void)
{
    time_t now = 0;
    struct tm time_info = {0};

    time(&now);
    localtime_r(&now, &time_info);

    // Check the time, in case we need to init/re-init
    if (time_info.tm_year < (2022 - 1900))
    {
        sntp_time_sync_init_sntp();
        // Set time zone
        setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
        tzset();
    }
}


/*
SNTP time synchronization task
*/
static void sntp_time_sync(void *pvParam)
{
    while(1)
    {
        sntp_time_sync_obtain_time();
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

char *sntp_time_sync_get_time(void)
{
    static char time_buffer[100] = {0};

    time_t now = 0;
    struct tm time_info = {0};
    time(&now);
    localtime_r(&now, &time_info);

    if (time_info.tm_year < (2022-1900))
    {
        ESP_LOGI(TAG, "Time is not set yet");
    }
    else
    {
        strftime(time_buffer, sizeof(time_buffer), "%d.%m.%Y %H:%ML%S", &time_info);
        ESP_LOGI(TAG, "Current tiem info: %s", time_buffer);
    }
    return time_buffer;
}


void sntp_time_sync_task_start(void)
{
    xTaskCreatePinnedToCore(&sntp_time_sync, "sntp_time_sync", SNTP_TIME_SYNC_STACK_TASK_SIZE, NULL, SNTP_TIME_SYNC_PRIORITY, NULL, SNTP_TIME_SYNC_CORE_ID);
}