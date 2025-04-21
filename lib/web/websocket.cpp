#include <libwebsockets.h>
#include <string>
#include <iostream>
#include <csignal>

// Global flag for graceful shutdown
static volatile int interrupted = 0;

/**
 * WebSocket callback function handling various events
 * 
 * @param wsi WebSocket instance
 * @param reason Callback reason (event type)
 * @param user User data
 * @param in Received data (if applicable)
 * @param len Length of received data
 * @return 0 on success
 */
static int websocket_callback(struct lws *wsi, 
                             enum lws_callback_reasons reason,
                             void *user, 
                             void *in, 
                             size_t len) 
{
    switch (reason) {
        case LWS_CALLBACK_RECEIVE:
            // Print received message
            std::cout << "Received message: " 
                      << std::string(static_cast<char*>(in), len) 
                      << std::endl;
            break;
            
        default:
            break;
    }
    return 0;
}

// Supported WebSocket protocols
static struct lws_protocols protocols[] = {
    {
        "example-protocol",  // Protocol name (doesn't need client match)
        websocket_callback, // Callback function
        0,                  // User data size
        1024,              // RX buffer size
    },
    { nullptr, nullptr, 0, 0 } // Terminator
};

/**
 * Signal handler for graceful shutdown
 * 
 * @param sig Signal number
 */
static void sigint_handler(int sig) 
{
    interrupted = 1;
}

int main() 
{
    // Initialize context creation info
    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(info));
    info.port = 3001;        // Port to listen on (matches frontend)
    info.protocols = protocols;
    
    // Register signal handler for Ctrl+C
    std::signal(SIGINT, sigint_handler);

    // Create WebSocket context
    struct lws_context* context = lws_create_context(&info);
    if (!context) {
        std::cerr << "Failed to initialize libwebsockets" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "WebSocket server started, listening on port " 
              << info.port << "..." << std::endl;
    
    // Main event loop
    while (!interrupted) {
        lws_service(context, 50);  // 50ms timeout
    }

    // Cleanup
    lws_context_destroy(context);
    std::cout << "Server shutdown complete" << std::endl;
    
    return EXIT_SUCCESS;
}
