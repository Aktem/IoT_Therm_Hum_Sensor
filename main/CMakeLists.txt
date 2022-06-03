idf_component_register(SRCS "DHT22.c" "http_server.c" "wifi_app.c" "rgb_led.c" "main.c" "app_nvs.c" "wifi_reset_button.c" "sntp_time_sync.c"
                    INCLUDE_DIRS "."
                    EMBED_FILES webpage/app.css webpage/app.js webpage/favicon.ico webpage/index.html webpage/jquery-3.3.1.min.js)
