#include <LiquidCrystal.h>

LiquidCrystal lcd_1(8, 9, 4, 5, 6, 7);

int IN1 = 2;   
int IN2 = 3;   
int IN3 = A1; 
int IN4 = A2;  
int ENA = A3;  
int ENB = A4; 

int leftWheelSpeedFront  = 100;  
int rightWheelSpeedFront = 100; 


unsigned long previousMillis = 0;
const long interval = 1000;
int timeCounter = 0;

void setup() {
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  lcd_1.begin(16, 2);
  lcd_1.print("Bears's time...");
}

void loop() {
 
  runMotors(leftWheelSpeedFront, rightWheelSpeedFront);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    timeCounter++;

    lcd_1.setCursor(0, 1);
    lcd_1.print("Time: ");
    lcd_1.print(timeCounter);
    lcd_1.print(" sec   ");
  }
}

void runMotors(int leftSpeed, int rightSpeed) {
  int period = 255;
  int delayMicrosValue = 40; 


  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  for (int i = 0; i < period; i++) {
    digitalWrite(ENA, (i < leftSpeed) ? HIGH : LOW);
    digitalWrite(ENB, (i < rightSpeed) ? HIGH : LOW);
    delayMicroseconds(delayMicrosValue);
  }
}

void stopMotors() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
