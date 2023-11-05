#define VGA_HEIGHT 80
#define VGA_WIDTH 25
#define VGA_MEMORY 0XA0000

void clear_screen(void);
void handle_next_line();
void print_msg(char* msg);
void draw_pixel(int x, int y, char color);