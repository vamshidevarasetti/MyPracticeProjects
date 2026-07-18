#include <iostream> 

#include <cstring> 

#include <unistd.h>         // For close() 

#include <sys/socket.h>     // For socket(), bind(), listen(), accept(), read(), write() 

#include <netinet/in.h>     // For sockaddr_in 

#include <arpa/inet.h>      // For htons(), inet_addr() 

  

int main() { 

    int server_fd;                  // File descriptor for server socket 

    struct sockaddr_in server_addr; // Structure to hold server address 

    int port = 8080;                // Port number for server to listen on 

  

    // 1️⃣ Create a socket: IPv4 (AF_INET), stream-based (TCP), protocol = 0 (auto) 

    server_fd = socket(AF_INET, SOCK_STREAM, 0); 

    if (server_fd < 0) { 

        std::cerr << "Socket creation failed\n"; 

        return -1; 

    } 

  

    // 2️⃣ Zero out the server_addr structure , specifying the address

    memset(&server_addr, 0, sizeof(server_addr)); 
    
    //specifying the address

    server_addr.sin_family = AF_INET;                          // Set address family to IPv4 

    server_addr.sin_addr.s_addr = INADDR_ANY;        // Accept connections from any IP 

    server_addr.sin_port = htons(port);                          // Convert port to network byte order 

  

    // 3️⃣ Bind the socket to the IP address and port 

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) { 

        std::cerr << "Bind failed\n"; 

        close(server_fd); 

        return -1; 

    } 

  

    // 4️⃣ Listen on the socket, with a backlog of 5 pending connections 

    if (listen(server_fd, 5) < 0) { 

        std::cerr << "Listen failed\n"; 

        close(server_fd); 

        return -1; 

    } 

    std::cout << "Server is listening on port " << port << "...\n"; 

  

    // 5️⃣ Accept an incoming connection 

    int client_fd = accept(server_fd, NULL, NULL); // You can use sockaddr to get client info 

    if (client_fd < 0) { 

        std::cerr << "Accept failed\n"; 

        close(server_fd); 

        return -1; 

    } 

  

    // 6️⃣ Read data sent by the client 

    char buffer[1024] = {0}; 

    int bytes_read = read(client_fd, buffer, sizeof(buffer)); 

    if (bytes_read > 0) { 

        std::cout << "Client says: " << buffer << "\n"; 

    } 

  

    // 7️⃣ Send a response back to the client 

    const char* reply = "Hello from server"; 

    write(client_fd, reply, strlen(reply)); 

  

    // 8️⃣ Close sockets to release resources 

    close(client_fd); 

    close(server_fd); 

  

    return 0; 

} 
