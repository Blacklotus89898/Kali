#include <ncurses.h>
#include <string>

// Initialize ncurses and set up the window
void init_curses() {
    initscr();                // Initialize the library
    raw();                     // Disable line buffering
    keypad(stdscr, TRUE);      // Enable special keys (e.g., arrows)
    noecho();                  // Don't display user input
    curs_set(0);               // Hide the cursor
}

// Cleanup ncurses and reset terminal
void cleanup_curses() {
    endwin();  // End ncurses mode
}

int main() {
    init_curses();  // Initialize ncurses

    // Create a simple window with a border
    WINDOW *win = newwin(10, 40, 5, 5);  // Create a window: 10 rows, 40 columns
    box(win, 0, 0);                      // Draw a border around the window
    wrefresh(win);                       // Refresh the window to show the changes

    // Display some text
    mvwprintw(win, 1, 1, "Welcome to the TUI app!");
    mvwprintw(win, 2, 1, "Press 'q' to quit.");

    // Handle user input
    int ch;
    while ((ch = wgetch(win)) != 'q') {  // Continue until user presses 'q'
        mvwprintw(win, 4, 1, "Key code: %d", ch);  // Debug print key code
        switch(ch) {
            case KEY_UP:
                mvwprintw(win, 3, 1, "You pressed UP");
                break;
            case KEY_DOWN:
                mvwprintw(win, 3, 1, "You pressed DOWN");
                break;
            default:
                mvwprintw(win, 3, 1, "You pressed an unrecognized key");
                break;
        }
        wrefresh(win);  // Refresh window to show updated text
    }

    cleanup_curses();  // Cleanup ncurses mode
    return 0;
}

