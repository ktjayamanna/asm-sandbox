# RS-232 Fundamentals in 24 Hours - Firmware Engineer's Crash Course

## Hour 1-3: Core ASCII Control Codes (For Terminal Interpretation)

### Must-Memorize Control Characters
```c
// These 8 codes explain 90% of terminal behavior:
\x0D = \r = Carriage Return (Enter key)
\x0A = \n = Line Feed (new line)  
\x07 = \a = Bell (beep sound)
\x08 = \b = Backspace
\x1B = \e = Escape (starts control sequences)
\x7F = Delete key
\x03 = Ctrl+C (interrupt)
\x04 = Ctrl+D (end of file)
```

**Quick Test**: Write a C program that prints these and see what happens.

## Hour 4-6: Basic VT100 Escape Sequences

### 5 Essential Sequences
```c
"\x1b[2J"    // Clear entire screen
"\x1b[H"     // Move cursor to top-left
"\x1b[31m"   // Red text
"\x1b[1m"    // Bold text  
"\x1b[0m"    // Reset all attributes
```

**Exercise**: Make a colored "Hello World" using these codes.

## Hour 7-9: termios Basics

### The 3 Key termios Modes
```c
#include <termios.h>

struct termios tty;
tcgetattr(0, &tty);

// 1. Cooked Mode (default - line editing)
tty.c_lflag |= (ICANON | ECHO);

// 2. Raw Mode (programs like vim)
tty.c_lflag &= ~(ICANON | ECHO);

// 3. Apply changes
tcsetattr(0, TCSANOW, &tty);
```

## Hour 10-12: Practical Raw Mode Example

### Minimal Raw Terminal Program
```c
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios old, new;
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~(ICANON | ECHO);  // Raw mode
    tcsetattr(0, TCSANOW, &new);
    
    // Now read input character by character
    char c;
    while (read(0, &c, 1) > 0 && c != 'q') {
        printf("Got: 0x%02X '%c'\r\n", c, c);
    }
    
    tcsetattr(0, TCSANOW, &old);  // Restore
    return 0;
}
```

## Hour 13-15: Input/Output Mapping (ANSI Escape Codes (also called VT100 escape sequences))

Special keys (arrows, function keys, Home, End, etc.) in terminal emulators send ANSI escape sequences, while regular keys send normal characters.

### Key Press → Byte Mapping
```
Arrow Up    = \x1b[A
Arrow Down  = \x1b[B  
Arrow Right = \x1b[C
Arrow Left  = \x1b[D
Enter       = \r or \n
Backspace   = \x7F or \x08
Tab         = \t
```

**Exercise**: Run the raw mode program and press these keys to see the actual bytes.

## Hour 16-18: Flow Control (XON/XOFF)

### Simple Flow Control Implementation (Raw Mode Only)
```c
int paused = 0;

void handle_byte(unsigned char c) {
    if (c == 0x13) {        // Ctrl+S (XOFF)
        paused = 1;
        printf("\r\n[PAUSED - Press Ctrl+Q to resume]\r\n");
    }
    else if (c == 0x11) {   // Ctrl+Q (XON)
        paused = 0; 
        printf("\r\n[RESUMED]\r\n");
    }
    else if (!paused) {
        // Process normal input
    }
}
```

## Hour 19-21: Real-World Analysis

### See What Programs Actually Send
```bash
# Watch Python's terminal output
strace -e write python -c "print('Hello')" 2>&1 | grep write

# Check your terminal settings
stty -a

# Send raw escape sequences
printf "\x1b[31mRed Text\x1b[0m" 
```

## Hour 22-24: Integration Project

### Simple Terminal Monitor
```c
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
```

## Cheat Sheet

### Control Characters
- `\r` = Enter, `\n` = Newline, `\b` = Backspace
- `\e` = Escape, `\a` = Bell, `\t` = Tab

### termios Quick Reference
```c
ICANON  // Line buffering (backspace works)
ECHO    // Show typed characters
~ICANON // Raw mode (vim, less)
~ECHO   // Password input
```

### Essential Commands
```bash
stty -a                  # View terminal settings
printf "\x1b[31m"        # Send red color
strace -e write program  # See terminal writes
```
