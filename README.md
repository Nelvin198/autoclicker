# AutoClicker - C++

AutoClicker is a simple yet powerful tool written in C++ that simulates mouse clicks at a specified interval. It comes in two versions:
1. **Command-Line Interface (CLI)**: A lightweight version for advanced users.
2. **Graphical User Interface (GUI)**: A user-friendly version with a graphical interface.

## Features

### Command-Line Version
- Start/Stop auto-clicking.
- Adjust click interval (in milliseconds).
- Toggle double-click mode.
- Lightweight and fast.

### GUI Version
- Start/Stop auto-clicking with a button.
- Adjust click interval using a slider.
- Toggle double-click mode with a checkbox.
- Real-time status updates.

## User Guide

### Command-Line Version

#### How to Use
1. **Start the Program**:
   - Run the executable (`autoclicker.exe`).
   - A menu will appear with the following options:
     ```
     AutoClicker - C++
     ----------------
     1. Start/Stop AutoClicker
     2. Set Click Interval (Current: 100 ms)
     3. Toggle Double Click (Current: Disabled)
     4. Exit
     Enter your choice:
     ```

2. **Start/Stop AutoClicker**:
   - Choose option `1` to start or stop the auto-clicker.

3. **Set Click Interval**:
   - Choose option `2` and enter the desired interval in milliseconds (e.g., `200` for 200ms).

4. **Toggle Double-Click Mode**:
   - Choose option `3` to enable or disable double-clicking.

5. **Exit the Program**:
   - Choose option `4` to exit.

#### Compilation
To compile the command-line version:
```bash
g++ autoclicker.cpp -o autoclicker.exe -lgdi32
