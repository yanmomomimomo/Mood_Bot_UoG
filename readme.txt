1. Install Dependency Libraries
Install the following libraries on the Raspberry Pi:

libmicrohttpd: For handling HTTP requests.

libwebsockets: For implementing WebSocket communication.

bash
sudo apt update
sudo apt install libmicrohttpd-dev libwebsockets-dev
2. Write the C Language Backend Service
Below is a complete example of a C language backend service that supports both HTTP and WebSocket communication.

Example Code (server.c):
c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>
#include <libwebsockets.h>
#include <wiringPi.h>

#define HTTP_PORT 8080
#define WS_PORT 9000

// GPIO pin number
#define MOTOR_PIN 18

// WebSocket context
struct lws_context *context;

// Handle HTTP requests
static int handle_http_request(void *cls, struct MHD_Connection *connection,
                              const char *url, const char *method,
                              const char *version, const char *upload_data,
                              size_t *upload_data_size, void **con_cls) {
    if (strcmp(method, "POST") == 0 && strcmp(url, "/control") == 0) {
        // Read POST data
        char buffer[1024];
        int ret = MHD_get_connection_values(connection, MHD_POSTDATA_KIND, buffer, sizeof(buffer));
        if (ret > 0) {
            // Parse JSON data (simple handling here)
            if (strstr(buffer, "\"command\":\"forward\"") != NULL) {
                digitalWrite(MOTOR_PIN, HIGH);  // Control the motor
            } else if (strstr(buffer, "\"command\":\"stop\"") != NULL) {
                digitalWrite(MOTOR_PIN, LOW);  // Stop the motor
            }
        }

        // Return a response
        const char *response = "{\"status\":\"success\"}";
        struct MHD_Response *mhd_response;
        mhd_response = MHD_create_response_from_buffer(strlen(response), (void *)response, MHD_RESPMEM_PERSISTENT);
        MHD_add_response_header(mhd_response, "Content-Type", "application/json");
        int ret_code = MHD_queue_response(connection, MHD_HTTP_OK, mhd_response);
        MHD_destroy_response(mhd_response);
        return ret_code;
    }

    // Return a 404 error
    const char *response = "{\"status\":\"error\",\"message\":\"Not found\"}";
    struct MHD_Response *mhd_response;
    mhd_response = MHD_create_response_from_buffer(strlen(response), (void *)response, MHD_RESPMEM_PERSISTENT);
    MHD_add_response_header(mhd_response, "Content-Type", "application/json");
    int ret_code = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, mhd_response);
    MHD_destroy_response(mhd_response);
    return ret_code;
}

// WebSocket callback function
static int websocket_callback(struct lws *wsi, enum lws_callback_reasons reason,
                              void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED:
            printf("WebSocket connection established\n");
            break;

        case LWS_CALLBACK_RECEIVE:
            printf("Received WebSocket data: %s\n", (char *)in);
            // Handle commands sent from the frontend
            if (strstr((char *)in, "\"mood\"")) {
                // Handle mood changes
                printf("Mood changed: %s\n", (char *)in);
            } else if (strstr((char *)in, "\"move\"")) {
                // Handle movement commands
                printf("Move command: %s\n", (char *)in);
            }
            break;

        case LWS_CALLBACK_CLOSED:
            printf("WebSocket connection closed\n");
            break;

        default:
            break;
    }
    return 0;
}

// WebSocket protocol
static const struct lws_protocols protocols[] = {
    {
        "moodybot-protocol",
        websocket_callback,
        0,
        1024,
    },
    { NULL, NULL, 0, 0 }  // End marker
};

int main() {
    // Initialize GPIO
    if (wiringPiSetupGpio() == -1) {
        fprintf(stderr, "Failed to initialize GPIO\n");
        return 1;
    }
    pinMode(MOTOR_PIN, OUTPUT);

    // Start the HTTP server
    struct MHD_Daemon *http_daemon;
    http_daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, HTTP_PORT, NULL, NULL,
                                   &handle_http_request, NULL, MHD_OPTION_END);
    if (http_daemon == NULL) {
        fprintf(stderr, "Failed to start HTTP server\n");
        return 1;
    }

    // Start the WebSocket server
    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(info));
    info.port = WS_PORT;
    info.protocols = protocols;

    context = lws_create_context(&info);
    if (context == NULL) {
        fprintf(stderr, "Failed to create WebSocket context\n");
        return 1;
    }

    printf("Server running on HTTP port %d and WebSocket port %d...\n", HTTP_PORT, WS_PORT);

    // Main loop
    while (1) {
        lws_service(context, 1000);  // Handle WebSocket events
    }

    // Clean up resources
    lws_context_destroy(context);
    MHD_stop_daemon(http_daemon);
    return 0;
}
3. Compile the C Code
Use gcc to compile the code and link the libmicrohttpd, libwebsockets, and wiringPi libraries:

bash
gcc -o server server.c -lwiringPi -lmicrohttpd -lwebsockets
4. Run the Backend Service
After compiling, run the generated executable:

bash
./server

The service will listen on:

HTTP Port: 8080

WebSocket Port: 9000

5. Modify the Frontend Code
In the frontend code, change the WebSocket connection address to the Raspberry Pi's IP address and port:
javascript

const socket = io('ws://<Raspberry Pi IP>:9000');

6. Test
Start the backend service.

Run the frontend page.

Test mood changes, movement commands, and other functionalities.

7. Set Up the Backend Service to Start on Boot
Refer to the previous steps to configure the backend service as a system service.

Summary
By following these steps, you can write a backend service in C that supports both HTTP and WebSocket communication and integrate it with a React frontend. Key points include:

Using libmicrohttpd to handle HTTP requests.

Using libwebsockets to implement WebSocket communication.

Integrating with the frontend to handle real-time commands.