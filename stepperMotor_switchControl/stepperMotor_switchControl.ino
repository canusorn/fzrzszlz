// Stepper Motor

const int dirPin = 2; // Direction
const int pulsePin = 3; // Pulse

// กำหนดยา DIO สำหรับการอ่านค่า
const int dioPin1 = 4; // DIO 4
const int dioPin2 = 5; //DIO 5

// กำหนดค่าการหมุน
const int stepsPerRevolution = 400; // จํานวน pulse ต่อการหมุน 1 รอบ
const int pulseInterval = 2500; // หน่วงเวลาในแต่ละ pulse (2,500 ไมโครวินาที)

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(pulsePin, OUTPUT);
  pinMode(dioPin1, INPUT_PULLUP);
  pinMode(dioPin2, INPUT_PULLUP);
  Serial.begin(115200);

}

void loop() {
  int dioValuel = digitalRead(dioPin1); // อ่านจาก DIO 4
  int dioValue2 = digitalRead(dioPin2); // อ่านค่าจาก DIO 5

  Serial.print("DIO 4 Value: ");
  Serial.println(dioValuel);
  Serial.print("DIO 5 Value: ");
  Serial.println(dioValue2);

  if (dioValuel == LOW) {
    digitalWrite(dirPin, HIGH); //หมุนไปทางขวา

    for (int i = 0; i < stepsPerRevolution; i++) {
      digitalWrite(pulsePin, HIGH);
      delayMicroseconds(pulseInterval / 2);
      digitalWrite(pulsePin, LOW);
      delayMicroseconds(pulseInterval / 2);
    }
  }
  else if (dioValue2 == LOW) {
    digitalWrite(dirPin, LOW); // หมุนไปทางซ้าย

    for (int i ; i < stepsPerRevolution; i++) {
      digitalWrite(pulsePin, HIGH);
      delayMicroseconds(pulseInterval / 2);
      digitalWrite(pulsePin, LOW);
      delayMicroseconds(pulseInterval / 2);
    }
  } else {
    delay(1);
  }
}
