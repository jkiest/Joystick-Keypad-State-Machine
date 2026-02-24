
#include <Keypad.h>
#include <LiquidCrystal.h>

#define Ls138_A 30
#define Ls138_B 31
#define Ls138_C 32
#define R0 2
#define R1 3
#define R2 4
#define R3 5
#define R4 6
#define R5 7
#define R6 8
#define R7 9
#define BUFFER_SIZE 4
#define row_size 8
#define col_size 8
#define delay_time 300
#define data_15 {0,0,1,1,1,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,0,0,0,1,0,0}
#define data_14 {0,0,1,1,1,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,0,0,0,1,0,0,\
                0,0,1,1,1,1,0,0}
#define data_13 {0,0,1,1,1,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,1,0,0,0,1,0,0,\
                0,1,0,0,0,1,0,0,\
                0,1,0,0,0,1,0,0,\
                0,1,0,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,0,1,1,1,0,0}
#define data_12 {0,0,0,0,0,0,0,0,\
                0,0,0,0,1,1,0,0,\
                0,0,0,1,0,0,1,0,\
                0,0,1,0,0,0,1,0,\
                0,0,0,0,0,0,1,0,\
                0,0,0,0,0,0,1,0,\
                0,0,1,0,0,1,0,0,\
                0,0,0,1,1,0,0,0}
#define data_11 {0,0,0,1,1,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,1,1,1,0,0}
#define data_10 {0,0,0,1,1,0,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,1,0,0,0,0,1,0,\
                0,1,1,1,1,1,1,0,\
                0,1,0,0,0,0,1,0,\
                0,1,0,0,0,0,1,0,\
                0,1,0,0,0,0,1,0}
#define data_9 {0,0,1,1,1,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,1,0,0,0,0,0,\
                0,0,1,0,0,0,0,0,\
                0,0,1,1,1,1,0,0}
#define data_8 {0,0,1,1,1,1,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,1,1,1,0,0}
#define data_7 {0,0,0,0,0,0,0,1,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0}
#define data_6 {0,0,0,0,0,0,1,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0}
#define data_5 {0,0,0,1,1,1,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,0,0,1,0,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,0,0,1,0,1,0,\
                0,1,1,1,1,1,0,0,\
                0,0,0,0,0,1,1,0,\
                0,0,0,0,0,0,0,0}
#define data_4 {0,0,0,1,1,1,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,0,0,1,0,0,0,\
                0,0,0,1,1,1,1,0,\
                0,0,1,0,1,0,0,0,\
                0,0,0,1,1,1,1,1,\
                0,0,1,1,0,0,0,0,\
                0,0,0,0,0,0,0,0}
#define data_3 {0,0,0,0,0,0,0,0,\
                0,0,0,1,0,0,1,0,\
                0,0,1,0,0,0,1,0,\
                0,1,1,0,1,0,1,0,\
                1,1,1,0,1,1,1,0,\
                0,1,1,0,1,0,1,0,\
                0,0,1,0,0,0,1,0,\
                0,0,0,1,0,1,0,1}
#define data_2 {0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,1,0,\
                0,0,0,0,0,0,1,0,\
                0,0,0,0,1,0,1,0,\
                0,0,0,0,1,1,1,0,\
                0,0,0,0,1,0,1,0,\
                0,0,0,0,0,0,1,0,\
                0,0,0,0,0,1,0,1}
#define data_1 {0,1,1,0,0,0,0,0,\
                0,1,1,0,0,0,0,0,\
                0,1,0,0,1,0,0,0,\
                0,0,1,0,1,0,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,0,0,1,0,1,0,\
                0,0,0,0,1,0,1,0,\
                0,0,0,0,1,0,0,0}
#define data_0 {0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,1,0,1,0,0,0,\
                0,0,1,0,1,0,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,0,0,1,0,1,0}
const byte ROWS = 4;
const byte COLS = 4;

char inputBuffer[BUFFER_SIZE] = {'\0', '\0', '\0', '\0'};

// 序列定義
struct Sequence {
  char seq[4];
  int indices[2];  // LED 顯示索引
};

Sequence sequences[3] = {
  {{'D', 'r', 'R', 'P'}, {3, 0}},
  {{'R', 'D', 'r', 'P'}, {2, 1}},
  {{'D', 'l', 'L', 'K'}, {4, 5}}
};

int sequenceIndices[3] = {0, 0, 0};

char hexaKeys[ROWS][COLS]={
  {'F','E','D','C'},
  {'K','3','6','9'},
  {'P','2','5','8'},
  {'0','1','4','7'}};
byte rowPins[ROWS] = {25, 24, 23, 22};
byte colPins[COLS] ={29, 28, 27, 26};
LiquidCrystal lcd(49, 48, 47, 43, 42, 41);
Keypad customKeypad=Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS,COLS);
boolean word_array[16][row_size][col_size] = {data_0,data_1,data_2,data_3,data_4,data_5,data_6,data_7,data_8,data_9,data_10,data_11,data_12,data_13,data_14,data_15};
boolean led[row_size][col_size];

byte row_pin[row_size]={R0, R1, R2, R3, R4, R5, R6, R7};
const int BASE = 2;
const int NUM = 4;
const int BASE1 = 37;

int joyPinX = A1;
int joyPinY = A2;
int SW = A3;
int xzero = 0;
int yzero = 0;
void setup(){
  // 設置輸出引腳
  for (int i = BASE; i < BASE + NUM; i++) {
    pinMode(i, OUTPUT);
  }
  
  // 設置 DIP 開關輸入
  for (int i = BASE1; i < BASE1 + NUM; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  
  // 設置控制引腳
  pinMode(A15, OUTPUT);
  digitalWrite(A15, HIGH);
  pinMode(A14, OUTPUT);
  digitalWrite(A14, LOW);
  
  // 設置 LED 行引腳
  for (int i = 0; i < row_size; i++) {
    pinMode(row_pin[i], OUTPUT);
  }
  
  // 設置 74138 引腳
  pinMode(Ls138_A, OUTPUT);
  pinMode(Ls138_B, OUTPUT);
  pinMode(Ls138_C, OUTPUT);
  
  clear_led();
  
  // 初始化 LCD
  lcd.begin(16, 2);
  lcd.print("ACTION:");
  
  // 初始化搖桿
  pinMode(SW, INPUT_PULLUP);
  yzero = analogRead(joyPinY);
  xzero = analogRead(joyPinX);
}

void loop(){
  handleKeypadInput();
  handleJoystickInput();
}

void clear_led(){
for (int i = 0; i < row_size; i++)
digitalWrite(row_pin[i], LOW);
}
void low_74138pin(int num) {
  digitalWrite(Ls138_A, num & 1);
  digitalWrite(Ls138_B, (num >> 1) & 1);
  digitalWrite(Ls138_C, (num >> 2) & 1);
}
void addToBuffer(char input) {
  // 將新的輸入加入陣列
  for (int i = 0; i < BUFFER_SIZE - 1; i++) {
    inputBuffer[i] = inputBuffer[i + 1];
  }
  inputBuffer[BUFFER_SIZE - 1] = input;
  
  // 更新LCD顯示
  lcd.setCursor(0, 1);
  lcd.print("            ");  // 清空原有內容
  lcd.setCursor(0, 1);
  lcd.print(inputBuffer);

  // 在這裡可以進行對陣列的其他處理，或者在需要時使用 inputBuffer
}
void handleKeypadInput() {
  char customKey = customKeypad.getKey();

  if (customKey != NO_KEY) {
    addToBuffer(customKey);
    checkKeySequence(customKey);
    delay(250);
  }
}
void checkKeySequence(char keyPressed) {
  // 逐個檢查所有序列
  for (int seqIdx = 0; seqIdx < 3; seqIdx++) {
    if (keyPressed == sequences[seqIdx].seq[sequenceIndices[seqIdx]]) {
      sequenceIndices[seqIdx]++;
    } else {
      sequenceIndices[seqIdx] = 0;
    }
    
    // 如果序列完成，執行相應動作
    if (sequenceIndices[seqIdx] == 4) {
      word_to_led(sequences[seqIdx].indices[0]);
      display_led(led, 1000);
      word_to_led(sequences[seqIdx].indices[1]);
      display_led(led, 1000);
      
      sequenceIndices[seqIdx] = 0;
    }
  }
}
void handleJoystickInput() {
  int Xvalue = analogRead(joyPinX);
  int Yvalue = analogRead(joyPinY);
  char direction = 0;

  if (Xvalue < 50) direction = 'U';
  else if (Xvalue > 600) direction = (Yvalue < 50) ? 'r' : (Yvalue > 600) ? 'l' : 'D';
  else if (Yvalue < 50) direction = 'R';
  else if (Yvalue > 600) direction = 'L';
  
  if (direction) {
    addToBuffer(direction);
    checkKeySequence(direction);
    delay(250);
  }
}
void display_led(byte led[row_size][col_size], int ms) {
  unsigned long endTime = millis() + ms;
  while (millis() < endTime) {
    for (int i = 0; i < col_size; i++) {
      clear_led();
      low_74138pin(i);
      for (int j = 0; j < row_size; j++) {
        if (led[i][j]) digitalWrite(row_pin[j], HIGH);
      }
    }
  }
}

void word_to_led(int n) {
  for (int i = 0; i < row_size; i++)
    for (int j = 0; j < col_size; j++)
      led[i][j] = word_array[n][i][j];
}
