#include <libwebsockets.h>
#include <cstring>
#include <iostream>
#include <csignal>

class WebSocketServer {
private:
    static bool interrupted;
    
    static void handleSignal(int) {
        interrupted = true;
    }

    static int websocketCallback(lws* wsi, lws_callback_reasons reason, 
                               void* user, void* in, size_t len) {
        switch (reason) {
            case LWS_CALLBACK_RECEIVE:
                std::cout << "Received message: " 
                          << std::string(static_cast<char*>(in), len) 
                          << std::endl;
                break;
            default:
                break;
        }
        return 0;
    }

    static constexpr lws_protocols protocols[] = {
        {
            "example-protocol",
            websocketCallback,
            0,
            1024,
            0, nullptr, 0
        },
        { nullptr, nullptr, 0, 0, 0, nullptr, 0 }
    };

public:
    static int run() {
        lws_context_creation_info info{};
        info.port = 3001;
        info.protocols = protocols;

        std::signal(SIGINT, handleSignal);

        auto context = lws_create_context(&info);
        if (!context) {
            std::cerr << "libwebsockets initialization failed" << std::endl;
            return -1;
        }

        std::cout << "WebSocket server started, listening on port " 
                  << info.port << "..." << std::endl;

        while (!interrupted) {
            lws_service(context, 50);
        }

        lws_context_destroy(context);
        std::cout << "Server shutdown complete" << std::endl;
        return 0;
    }
};

bool WebSocketServer::interrupted = false;

int main() {
    return WebSocketServer::run();
}