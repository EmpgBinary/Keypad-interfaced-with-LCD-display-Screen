#include <Keypad.h>
#include <LiquidCrystal.h>


#define ROWS 4
#define COLS 4
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowsPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(keys), rowsPins, colPins, ROWS, COLS);


const int rs = 12, en = 11, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  lcd.print("Enter Key:");
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);
    lcd.clear();
    lcd.print("Key Pressed:");
    lcd.setCursor(0, 1); 
    lcd.print(customKey);
  }
}

