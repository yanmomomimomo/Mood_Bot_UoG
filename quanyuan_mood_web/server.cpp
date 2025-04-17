#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

class TCPServer {
private:
    static constexpr int PORT = 3001;
    static constexpr int BUFFER_SIZE = 1024;
    static constexpr int MAX_CONNECTIONS = 5;
    
    int server_socket;
    sockaddr_in server_addr;

    void setupSocket() {
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            throw std::runtime_error("Socket creation failed");
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(PORT);

        if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) {
            throw std::runtime_error("Binding failed");
        }

        if (listen(server_socket, MAX_CONNECTIONS) {
            throw std::runtime_error("Listening failed");
        }
    }

    void handleConnection(int client_socket) const {
        char buffer[BUFFER_SIZE];
        int bytes_received;

        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[bytes_received] = '\0';
            std::cout << "Received button: " << buffer << std::endl;
        }

        close(client_socket);
        std::cout << "Client disconnected." << std::endl;
    }

public:
    TCPServer() {
        setupSocket();
        std::cout << "Server listening on port " << PORT << "..." << std::endl;
    }

    ~TCPServer() {
        close(server_socket);
    }

    void run() {
        while (true) {
            sockaddr_in client_addr{};
            socklen_t addr_size = sizeof(client_addr);
            
            int client_socket = accept(server_socket, 
                                     (struct sockaddr*)&client_addr, 
                                     &addr_size);
            if (client_socket < 0) {
                std::cerr << "Client connection failed" << std::endl;
                continue;
            }

            std::cout << "Client connected." << std::endl;
            handleConnection(client_socket);
        }
    }
};

int main() {
    try {
        TCPServer server;
        server.run();
    } catch (const std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}