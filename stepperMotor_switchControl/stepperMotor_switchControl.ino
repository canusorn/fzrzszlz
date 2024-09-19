// Stepper Motor

const int dirPin = 2; // Direction
const int pulsePin = 3; // Pulse


//const int dirPin = 9; // Direction
//const int pulsePin = 11; // Pulse

// กำหนดยา DIO สำหรับการอ่านค่า
const int dioPin1 = 4; // DIO 4
const int dioPin2 = 5; //DIO 5

// กำหนดค่าการหมุน
const int stepsPerRevolution = 400; // จํานวน pulse ต่อการหมุน 1 รอบ
const int pulseInterval = 2500; // หน่วงเวลาในแต่ละ pulse (2,500 ไมโครวินาที)

unsigned long previousMillis = 0;

void setup() {

//  pinMode(8 , OUTPUT);
//  pinMode(10, OUTPUT);
//  pinMode(12 , OUTPUT);
//  pinMode(13, OUTPUT);
//  digitalWrite(8, LOW);
//  digitalWrite(10, LOW);
//  digitalWrite(12, LOW);
//  digitalWrite(13, LOW);



  pinMode(dirPin, OUTPUT);
  pinMode(pulsePin, OUTPUT);
  pinMode(dioPin1, INPUT_PULLUP);
  pinMode(dioPin2, INPUT_PULLUP);
  Serial.begin(115200);

}

void loop() {
  int dioValuel = digitalRead(dioPin1); // อ่านจาก DIO 4
  int dioValue2 = digitalRead(dioPin2); // อ่านค่าจาก DIO 5

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    if (dioValuel == LOW) Serial.println("Right Dir");
    else if (dioValue2 == LOW) Serial.println("Left Dir");
    else Serial.println("Stop");
  }

  if (dioValuel == LOW) {
    digitalWrite(dirPin, HIGH); //หมุนไปทางขวา

    digitalWrite(pulsePin, HIGH);
    delayMicroseconds(pulseInterval / 2);
    digitalWrite(pulsePin, LOW);
    delayMicroseconds(pulseInterval / 2);

  }  else if (dioValue2 == LOW) {
    digitalWrite(dirPin, LOW); // หมุนไปทางซ้าย

    digitalWrite(pulsePin, HIGH);
    delayMicroseconds(pulseInterval / 2);
    digitalWrite(pulsePin, LOW);
    delayMicroseconds(pulseInterval / 2);
  } else {
    delay(1);
  }

}
