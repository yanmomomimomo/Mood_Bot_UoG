#include <libwebsockets.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

static int interrupted = 0;

static int callback_websockets(struct lws *wsi, enum lws_callback_reasons reason,
                               void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_RECEIVE:
            // Print received message
            printf("Received message: %.*s\n", (int)len, (char *)in);
            break;
        default:
            break;
    }
    return 0;
}

static struct lws_protocols protocols[] = {
    {
        "example-protocol", // Protocol name (doesn't need to strictly match client)
        callback_websockets,
        0,
        1024,
    },
    { NULL, NULL, 0, 0 } // Terminator
};

static void sigint_handler(int sig) {
    interrupted = 1;
}

int main(void) {
    struct lws_context_creation_info info;
    memset(&info, 0, sizeof info);
    info.port = 3001;  // Keep consistent with frontend connection port
    info.protocols = protocols;
    
    // Catch Ctrl+C signal for graceful exit
    signal(SIGINT, sigint_handler);

    struct lws_context *context = lws_create_context(&info);
    if (!context) {
        fprintf(stderr, "libwebsockets initialization failed\n");
        return -1;
    }

    printf("WebSocket server started, listening on port %d...\n", info.port);
    
    // Enter event loop
    while (!interrupted) {
        lws_service(context, 50);
    }

    lws_context_destroy(context);
    printf("Server shutdown complete\n");
    return 0;
}