#include <stdio.h>
#include <string.h>
#include <openssl/sha.h> // Include the OpenSSL SHA library

int main() {
    // Input string to hash
    const char* str = "hello world";
    unsigned char hash[SHA256_DIGEST_LENGTH]; // Buffer to store the hash (32 bytes)
    int i;

    // Calculate SHA256 hash
    // SHA256() function computes the hash of the data
    SHA256((const unsigned char*)str, strlen(str), hash);

    // Print the resulting hash as a string of hex digits
    printf("SHA256(\"%s\") = ", str);
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]); // Print each byte as two hexadecimal digits

    printf("\n");
    return 0;
}
