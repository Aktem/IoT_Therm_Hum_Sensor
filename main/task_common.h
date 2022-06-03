/*
Author: Matthew Love
Date: April 16, 2022
*/

#ifndef MAIN_TASK_COMMON_H_
#define MAIN_TASK_COMMON_H_

// Wifi application task
#define WIFI_APP_TASK_STACK_SIZE        4096
#define WIFI_APP_TASK_PRIORITY          5
#define WIFI_APP_TASK_CORE_ID           0

// HTTP Server task
#define HTTP_SERVER_TASK_STACK_SIZE     8192
#define HTTP_SERVER_TASK_PRIORITY       4
#define HTTP_SERVER_TASK_CORE_ID        0

// HTTP SERVER Monitor task
#define HTTP_SERVER_MONITOR_STACK_SIZE  4096
#define HTTP_SERVER_MONITOR_PRIORITY    3
#define HTTP_SERVER_MONITOR_CORE_ID     0

// Wifi Reset Button task
#define WIFI_RESET_BUTTON_TASK_STACK_SIZE   2048
#define WIFI_RESET_BUTTON_TASK_PRIORITY     6
#define WIFI_RESET_BUTTON_TASK_CORE_ID      0

// DHT22 Sensor Task
#define DHT22_TASK_STACK_SIZE           4096
#define DHT22_TASK_PRIORITY             5
#define DHT22_TASK_CORE_ID              1

// SNTP Time Sync task
#define SNTP_TIME_SYNC_STACK_TASK_SIZE  4096
#define SNTP_TIME_SYNC_PRIORITY   4
#define SNTP_TIME_SYNC_CORE_ID    1


#endif /* MAIN_TASKS_COMMON_H_ */