#include <iostream> 

#include <cstring> 

#include <unistd.h>           // For read(), write(), close() 

#include <sys/socket.h>       // For socket(), connect() 

#include <netinet/in.h>       // For sockaddr_in 

#include <arpa/inet.h>        // For inet_addr(), htons() 

  

int main() { 

    int sock_fd;                        // File descriptor for client socket 

    struct sockaddr_in server_addr;     // Server address structure 

    const char* server_ip = "127.0.0.1"; // IP address of the server (localhost) 

    int port = 8080;                    // Port number matching the server 

  

    // 1️⃣ Create a socket: IPv4 (AF_INET), stream-based (TCP), protocol = 0 

    sock_fd = socket(AF_INET, SOCK_STREAM, 0); 

    if (sock_fd < 0) { 

        std::cerr << "Socket creation failed\n"; 

        return -1; 

    } 

  

    // 2️⃣ Zero out the server address structure 

    memset(&server_addr, 0, sizeof(server_addr)); 

    server_addr.sin_family = AF_INET;                  // Set address family to IPv4 

    server_addr.sin_port = htons(port);                // Convert port to network byte order 

    server_addr.sin_addr.s_addr = inet_addr(server_ip); // Convert IP to binary format 

  

    // 3️⃣ Connect to the server 

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) { 

        std::cerr << "Connection to server failed\n"; 

        close(sock_fd); 

        return -1; 

    } 

    std::cout << "Connected to server at " << server_ip << ":" << port << "\n"; 

  

    // 4️⃣ Send data to the server 

    const char* message = "Hello from client"; 

    write(sock_fd, message, strlen(message)); 

  

    // 5️⃣ Receive response from server 

    char buffer[1024] = {0}; 

    int bytes_received = read(sock_fd, buffer, sizeof(buffer)); 

    if (bytes_received > 0) { 

        std::cout << "Server says: " << buffer << "\n"; 

    } 

  

    // 6️⃣ Close the socket 

    close(sock_fd); 

  

    return 0; 

} 
