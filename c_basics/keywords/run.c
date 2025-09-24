#include <termios.h>
#include <unistd.h>
#include <stdio.h>

void setup_raw_mode() {
    struct termios tty;
    tcgetattr(0, &tty);

    // 1. Cooked Mode (default - line editing)
    tty.c_lflag |= (ICANON | ECHO);

    // 2. Raw Mode (programs like vim)
    tty.c_lflag &= ~(ICANON | ECHO);

    // 3. Apply changes
    tcsetattr(0, TCSANOW, &tty);
}



// Final project: A basic terminal input logger
void monitor_terminal() {
    setup_raw_mode();
    
    printf("Terminal Monitor - Press keys (q to quit)\r\n");
    
    unsigned char c;
    while (read(0, &c, 1) > 0 && c != 'q') {
        if (c == 0x1B) {
            printf("[ESC]");
            // Read the rest of escape sequence
            read(0, &c, 1);  // '['
            read(0, &c, 1);  // 'A','B','C','D'
            printf(" sequence: %c\r\n", c);
        } else {
            printf("Char: 0x%02X '%c'\r\n", c, 
                   (c >= 32 && c < 127) ? c : '.');
        }
    }
}

int main() {
    monitor_terminal();
    return 0;
}
