**Here's the complete data flow for both input and output, comparing VT100 vs Modern Terminal:**

## **INPUT FLOW: User → Terminal → Shell**

### **Scenario: User types `echo -e "\e[31mhello\e[0m"` + Enter**

#### **VT100 (1978):**
```
USER TYPES:    e c h o space - e space " \ e [ 3 1 m h e l l o \ e [ 0 m " Enter
               ↓
VT100:         Converts keys to ASCII bytes via keyboard hardware
               Sends: 65 63 68 6F 20 2D 65 20 22 5C 65 5B 33 31 6D 68 65 6C 6C 6F 5C 65 5B 30 6D 22 0D
               ↓  
RS-232 CABLE:  9600 baud serial transmission
               ↓
SHELL:         Receives raw bytes, parses as command string
```

#### **Modern Terminal (2024):**
```
USER TYPES:    e c h o space - e space " \ e [ 3 1 m h e l l o \ e [ 0 m " Enter
               ↓
GNOME TERMINAL: GTK+ event system captures key presses
               Converts to UTF-8 bytes via OS keyboard driver
               Sends: 65 63 68 6F 20 2D 65 20 22 5C 65 5B 33 31 6D 68 65 6C 6C 6F 5C 65 5B 30 6D 22 0A
               ↓
PTY (Pseudo Terminal): Kernel pipes the data
               ↓  
SHELL:         Receives identical bytes, parses as command string
```

**Key Insight: Input is IDENTICAL - both just forward raw bytes!**

## **OUTPUT FLOW: Shell → Terminal → User**

### **Scenario: Shell executes `echo -e "\e[31mhello\e[0m"`**

#### **Shell Processing:**
```bash
# Shell interprets escape sequences
"\e[31mhello\e[0m" → converts to bytes: 1B 5B 33 31 6D 68 65 6C 6C 6F 1B 5B 30 6D 0A
```

#### **VT100 Output:**
```
SHELL SENDS:    1B 5B 33 31 6D 68 65 6C 6C 6F 1B 5B 30 6D 0A
                ↓
RS-232:         Serial transmission to VT100
                ↓
VT100 HARDWARE: Microprocessor interprets sequences:
                - 1B5B33316D: "Switch to red attribute" 
                - Stores "hello" in video RAM with red flag
                - 1B5B306D: "Reset attributes"
                - 0A: "Move cursor down one line"
                ↓
PHOSPHOR SCREEN: Electron beam paints "hello" in red, then resets
USER SEES:      "hello" in monochrome red on green screen
```

#### **Modern Terminal Output:**
```
SHELL SENDS:    1B 5B 33 31 6D 68 65 6C 6C 6F 1B 5B 30 6D 0A
                ↓
PTY:            Kernel pipes bytes to terminal emulator
                ↓
GNOME TERMINAL: VTE library interprets sequences:
                - 1B5B33316D: "Use RGB(255,0,0) with current font"
                - Renders "hello" with anti-aliasing, subpixel rendering
                - 1B5B306D: "Reset to default style"
                - 0A: "New line with line spacing"
                ↓
GPU RENDERING:  OpenGL/DirectX renders text with transparency, shadows
USER SEES:      "hello" in smooth true red on high-DPI display
```
