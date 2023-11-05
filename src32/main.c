#include "main.h"

char *vgaBuff = (char *)0xb8000;
int vgaBuffPos = 0;

void clear_screen(void)
{
    int screen_size = (VGA_WIDTH * 2) * VGA_HEIGHT;

    for (int i = 0; i < screen_size; i++)
    {
        vgaBuff[i] = 0;
    }
}

void handle_next_line(void) {
    int screen_width = VGA_WIDTH * 2;

    for (int i = vgaBuffPos; i < screen_width * 2; i++)
    {
        vgaBuff[i] = 0;
    }
    
    vgaBuffPos += screen_width * 2;
}

void print_msg(char* msg)
{
    int i = 0;

    while (msg[i] != '\0')
    {
        if (msg[i] == '\n')
        {
            handle_next_line();
            i++;
            continue;
        }

        vgaBuff[vgaBuffPos] = msg[i];
        vgaBuff[vgaBuffPos + 1] = 15;

        ++i;
        vgaBuffPos += 2;
    }
}

void draw_pixel(int x, int y, char color) {
    char* video_memory = (char*)VGA_MEMORY;

    // Calculate the index in the VGA buffer for this position
    int index = (y * VGA_WIDTH + x) * 2;

    video_memory[index] = ' ';       // Set a space character
    video_memory[index + 1] = color;  // Set the color

    // Set the background color to redish pink (0x50)
    video_memory[index + 1] |= 0x50 << 4;
}