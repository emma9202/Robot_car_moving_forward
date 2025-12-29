#include <LiquidCrystal.h>

LiquidCrystal lcd_1(8, 9, 4, 5, 6, 7);

#define enA A4
#define in1 2
#define in2 3
#define in3 5
#define in4 4
#define enB A3
#define R_S A1
#define L_S A2

int MOTOR_SPEED = 140; 

unsigned long previousMillis = 0;
const long interval = 1000;
int timeCounter = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);

  analogWrite(enA, MOTOR_SPEED);
  analogWrite(enB, MOTOR_SPEED);

  // Initialize LCD
  lcd_1.begin(16, 2);
  lcd_1.print("Bears's time...");
}

void loop() {
  int leftSensor  = digitalRead(L_S); 
  int rightSensor = digitalRead(R_S);

  if (leftSensor == 0 && rightSensor == 0) {
    forward();   
  }
  else if (leftSensor == 1 && rightSensor == 0) {
    turnLeft(); 
  }
  else if (leftSensor == 0 && rightSensor == 1) {
    turnRight(); 
  }
  else if (leftSensor == 1 && rightSensor == 1) {
    Stop();     
  }

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

// Move both motors forward
void forward() {
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Turn left
void turnLeft() {
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);  
  digitalWrite(in4, LOW);
}

// Turn right
void turnRight() {
  digitalWrite(in1, LOW);   
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);  
  digitalWrite(in4, HIGH);
}

// Stop both motors
void Stop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
