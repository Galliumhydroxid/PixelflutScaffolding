#include "pixelflut.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Imlib2.h>


int send_message(int socket, const char* message)
{
    (void) socket;
    (void) message;
    return -1;
}

int receive_message(int socket, char* buffer, size_t length)
{
    (void) socket;
    (void) buffer;
    (void) length;
    return -1;
}

int connect_to_server(const char* ip, int port)
{
    (void) ip;
    (void) port;
    return -1;
}

/**
 * @brief Get the pixelbuf object
 * 
 * @param file_path The file path
 * @param width the width pointer (gets overwritten)
 * @param height the height (gets overwritten)
 * @return uint32_t* A pointer to the image data buffer. It is laid out row-by-row: Coordinate (0, 1) would be at argbuf[width]. The values are laid out as 0xAARRGGBB.
 */
uint32_t *get_pixelbuf(char *file_path, int *width, int *height) {
  Imlib_Image image = imlib_load_image(file_path);
  if (!image) {
    printf("Error: cannot load image\n");
    exit(1);
  }
  imlib_context_set_image(image);
  *width = imlib_image_get_width();
  *height = imlib_image_get_height();

  uint32_t *argbbuf = imlib_image_get_data_for_reading_only();
  if (!argbbuf) {
    printf("Error: cannot get image data\n");
    exit(1);
  }
  return argbbuf;
}

int write_pixel(int socket, int x, int y, int r, int g, int b)
{
    (void) socket;
    (void) x;
    (void) y;
    (void) r;
    (void) g;
    (void) b;
    return -1;
}

int read_pixel(int socket, int x, int y, int* r, int* g, int* b)
{
    (void) socket;
    (void) x;
    (void) y;
    (void) r;
    (void) g;
    (void) b;
    return -1;
}

int read_size(int socket, int* width, int* height)
{
    (void) socket;
    (void) width;
    (void) height;
    return -1;
}

int main(int argc, char const* argv[])
{
    (void) argc;
    (void) argv;
    return 0;
}
