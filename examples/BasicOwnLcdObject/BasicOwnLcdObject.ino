/*
 Basic Menu Navigation

 This sketch demostrates how to get started with the LcdMenu library

 Circuit:
 * Arduino Board
 * LCD SLC pin to arduino SLC pin
 * LCD SDA pin to arduino SDA pin

 created 22 July 2020
 by Forntoh Thomas

 This example is in the public domain.

 https://github.com/forntoh/LcdMenu/tree/master/examples/Basic/Basic.ino

*/

#include <LcdMenu.h>

#define LCD_ROWS 2
#define LCD_COLS 16

// Configure keyboard keys (ASCII)
#define UP 56        // NUMPAD 8
#define DOWN 50      // NUMPAD 2
#define LEFT 52      // NUMPAD 4
#define RIGHT 54     // NUMPAD 6
#define ENTER 53     // NUMPAD 5
#define BACK 55      // NUMPAD 7
#define LCD_CONTROL 56      // NUMPAD 8
#define MENU_CONTROL 57      // NUMPAD 9
#define BACKSPACE 8  // BACKSPACE
#define CLEAR 46     // NUMPAD .




// Initialize the main menu items
MAIN_MENU(
    ITEM_BASIC("Start service"),
    ITEM_BASIC("Connect to WiFi"),
    ITEM_BASIC("Settings"),
    ITEM_BASIC("Blink SOS"),
    ITEM_BASIC("Blink random")
);
// Construct the LcdMenu
LcdMenu menu(LCD_ROWS, LCD_COLS);

LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);


void setup() {
    Serial.begin(9600);

    // initialize the LCD
    lcd.init();
    lcd.backlight();

    // Initialize LcdMenu with the menu items
    menu.setup(&lcd, mainMenu);
}


void loop() {
    if (!Serial.available()) return;
    char command = Serial.read();

    if (command == UP)
        menu.up();
    else if (command == DOWN)
        menu.down();
    else if (command == LEFT)
        menu.left();
    else if (command == RIGHT)
        menu.right();
    else if (command == ENTER)
        menu.enter();
    else if (command == BACK)
        menu.back();
    else if (command == LCD_CONTROL){
        menu.hide();
        lcd.setCursor(0,0);
        lcd.print("Hello");
    }else if (command == MENU_CONTROL){
        menu.show();
    }
}