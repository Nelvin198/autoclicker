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

# AutoClicker - GUI Version

AutoClicker is a user-friendly tool written in C++ with a graphical interface that simulates mouse clicks at a specified interval. It allows you to automate repetitive clicking tasks with ease.

## Features

- **Start/Stop AutoClicker**: Toggle auto-clicking with a button or the F6 hotkey.
- **Adjustable Click Interval**: Set the delay between clicks in milliseconds.
- **Double-Click Mode**: Enable or disable double-clicking.
- **Hotkey Support**: Use the F6 key to start/stop the auto-clicker.
- **Real-Time Status Updates**: The interface displays the current status (running/stopped).

## User Guide

### How to Use

1. **Start the Program**:
   - Run the executable (`autoclicker_gui.exe`).
   - A window will appear with the following controls:
     - **Start/Stop Button**: Toggles auto-clicking.
     - **Interval Input**: Adjust the click interval (in milliseconds).
     - **Double-Click Checkbox**: Enable or disable double-clicking.
     - **Status Label**: Displays the current status (e.g., "Stopped" or "Running").

2. **Start/Stop AutoClicker**:
   - Click the "Start" button to begin auto-clicking. The button will change to "Stop" when active.
   - Alternatively, press the **F6 key** to start or stop the auto-clicker.

3. **Set Click Interval**:
   - Use the input box or slider to set the desired interval (e.g., `200` for 200ms).

4. **Toggle Double-Click Mode**:
   - Check or uncheck the "Double Click" checkbox.

5. **Exit the Program**:
   - Close the window to exit the application.

### Screenshot

![GUI Screenshot](screenshot.png)

---

## Compilation

### Requirements
- **Qt 5 or later**: The GUI is built using the Qt framework.
- **C++ Compiler**: Ensure you have a compatible compiler (e.g., MinGW, MSVC).

### Steps to Compile
1. Open the project in **Qt Creator**.
2. Configure the project to use the **MinGW** or **MSVC** compiler.
3. Build the project by clicking the **Build** button (hammer icon).
4. The executable will be generated in the `release` or `debug` folder.

---

## Running the Program

### From Qt Creator
1. Click the **Run** button (green play icon) in Qt Creator.

### From Command Line
1. Navigate to the folder containing the executable.
2. Run the program:
   ```bash
   ./autoclicker_gui.exe
