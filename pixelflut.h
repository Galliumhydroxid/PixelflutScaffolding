#ifndef PIXELFLUT_H
#define PIXELFLUT_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Get a pixel buffer for a given image file
 * 
 * @param file_path The file path
 * @param width the width pointer (gets overwritten)
 * @param height the height (gets overwritten)
 * @return uint32_t* A pointer to the image data buffer. It is laid out row-by-row: Coordinate (0, 1) would be at argbuf[width]. The values are laid out as 0xAARRGGBB.
 */
uint32_t *get_pixelbuf(char *file_path, int *width, int *height);


// -------- CLIENT --------

/**
 * @brief Send a message over the socket
 * 
 * @param socket 
 * @param message 
 * @return int Number of bytes sent, or -1 on error
 */
int send_message(int socket, const char* message);

/**
 * @brief Receive a message from the socket
 * 
 * @param socket 
 * @param buffer 
 * @param length 
 * @return int Number of bytes received, or -1 on error
 */
int receive_message(int socket, char* buffer, size_t length);

/**
 * @brief Create a socket to a server
 * 
 * @param ip the ip of the server, as a string
 * @param port the port of the server, as integer
 * @return int the file descriptor to the socket, or -1 on failure
 */
int connect_to_server(const char* ip, int port);

// -------- API --------

/**
 * @brief Write a pixel on the server instance
 * 
 * @param socket the socket fd
 * @param x 
 * @param y 
 * @param r 
 * @param g 
 * @param b 
 * @return int 0 on success, -1 on failure
 */
int write_pixel(int socket, int x, int y, int r, int g, int b);

/**
 * @brief Read a pixel on the server instance
 * 
 * @param socket the socket fd
 * @param x 
 * @param y 
 * @param r 
 * @param g 
 * @param b 
 * @return int 0 on success, -1 on failure
 */
int read_pixel(int socket, int x, int y, int* r, int* g, int* b);

/**
 * @brief Read the size of the server instance canvas
 * 
 * @param socket the socket fd
 * @param width 
 * @param height 
 * @return int 0 on success, -1 on failure
 */
int read_size(int socket, int* width, int* height);

// -------- MAIN --------

/**
 * @brief Main entry point of the program. Decide the arguments yourself!
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const* argv[]);

#endif // !PIXELFLUT_H
