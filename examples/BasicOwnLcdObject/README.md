# Example 01 Basic Navigation with your own LCD object

![Basic](https://i.imgur.com/nViET8b.gif)

## Requirements

- Keyboard
- LcdDisplay

## Code

Go to [.../examples/Basic/Basic.ino](https://github.com/forntoh/LcdMenu/tree/master/examples/Basic/Basic.ino)

```cpp
// ../../examples/Basic/Basic.ino#L35-L68

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

    // your own lcd init
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
}
```
