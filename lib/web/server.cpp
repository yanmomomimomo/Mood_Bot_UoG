#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <system_error>

constexpr int PORT = 3001;
constexpr int BUFFER_SIZE = 1024;
constexpr int MAX_CONNECTIONS = 5;

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) {
        if (bytes_received < 0) {
            std::cerr << "Error receiving data" << std::endl;
            break;
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received data
        std::cout << "Received button press: " << buffer << std::endl;
    }

    close(client_socket);
    std::cout << "Client disconnected." << std::endl;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        throw std::system_error(errno, std::system_category(), "Socket creation failed");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) {
        close(server_socket);
        throw std::system_error(errno, std::system_category(), "Bind failed");
    }

    // Start listening
    if (listen(server_socket, MAX_CONNECTIONS)) {
        close(server_socket);
        throw std::system_error(errno, std::system_category(), "Listen failed");
    }

    std::cout << "Server listening on port " << PORT << "..." << std::endl;

    try {
        while (true) {
            // Accept new connection
            client_socket = accept(server_socket, reinterpret_cast<sockaddr*>(&client_addr), &addr_size);
            if (client_socket < 0) {
                std::cerr << "Client connection failed" << std::endl;
                continue;
            }

            std::cout << "Client connected from " 
                      << inet_ntoa(client_addr.sin_addr) << ":"
                      << ntohs(client_addr.sin_port) << std::endl;
            
            handle_client(client_socket);
        }
    } catch (...) {
        close(server_socket);
        throw;
    }

    close(server_socket);
    return 0;
}
