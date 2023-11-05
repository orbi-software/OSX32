#include "main.h"

/*                CODE                */

void reboot() {
    asm volatile ("int $0x19");
}

unsigned int seed = 1; //SEED

unsigned int random() {
    seed = (1103515245 * seed + 12345) & 0x7FFFFFFF; //LGC Formula
    return seed;
}

int clamp(int value, int min, int max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}

void delay(int milliseconds) {
    for (int i = 0; i < milliseconds * 10000; i++) {
    }
}

int max = 50000;
int min = 100;

void kernel_main() {
    clear_screen();
    delay(max);
    print_msg("[ [ OSX ] LPM32B ]\n");
    delay(clamp(random() % (max - min + 1) + min, min, max));
    print_msg("            [ LOSX ]\n");
    delay(clamp(random() % (max - min + 1) + min, min, max));
    print_msg("                      [ BOOTING ]\n");
    delay(clamp(random() % (max - min + 1) + min, min, max));
    print_msg("                   [ [ DONE ] LKIM ]\n");
    delay(clamp(random() % (max - min + 1) + min, min, max));
    print_msg("             [ [ DONE ] LLTM ]\n");
    delay(clamp(random() % (max - min + 1) + min, min, max));
    print_msg("             [ [ DONE ] Operating System Loaded Successfully! ]\n");
    delay(clamp(random() % (max - min + 1) + min, min, max) + 50000);
    clear_screen();
    delay(max*min);
    print_msg("\n\n\n\n\n PRESS ANY TO REBOOT!");
    delay(max^3);

    asm volatile ("sti");
    
    while (0) {
        key_press();
    }
}

void key_press() {
    unsigned char key_code;

    asm volatile (
        "mov ah, 0x00\n"
        "int 0x16\n"
        "mov %0, ah\n"
        : "=r" (key_code) 
        : 
        : "ah"
    );
    if (key_code == 0x13) {
        reboot();
    }
}