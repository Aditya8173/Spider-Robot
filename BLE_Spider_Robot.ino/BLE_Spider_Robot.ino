#include <Servo.h>
#include <SoftwareSerial.h>

// ================= BLUETOOTH =================
SoftwareSerial BT(10, 11); // RX, TX
char cmd = 'S';

// ================= SERVO SETUP =================
Servo servo[8];

// Your mapping
int pins[8] = {8, 2, 9, 3, 6, 4, 7, 5};

// Servo states
float currentPos[8] = {90,90,90,90,90,90,90,90};

// ================= GAIT PARAMETERS =================
float t = 0;
float speedFactor = 0.05;

// gait tuning
float x_amp = 20;
float z_amp = 25;

// ================= INIT =================
void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  for (int i = 0; i < 8; i++) {
    servo[i].attach(pins[i]);
    servo[i].write(90);
  }

  delay(2000);
}

// ================= APPLY SERVO =================
void setServo(int i, float angle) {
  angle = constrain(angle, 0, 180);
  servo[i].write(angle);
  currentPos[i] = angle;
}

// ================= FORWARD =================
void gaitForward() {
  t += speedFactor;

  for (int i = 0; i < 4; i++) {

    float phase = (i % 2 == 0) ? 0 : PI;

    float hip = 90 + x_amp * sin(t + phase);
    float knee = 90 + z_amp * sin(t + phase + PI/2);

    int hipIndex = i;
    int kneeIndex = i + 4;

    // mirror right side
    if (i == 1 || i == 3) {
      hip = 180 - hip;
      knee = 180 - knee;
    }

    setServo(hipIndex, hip);
    setServo(kneeIndex, knee);
  }
}

// ================= BACKWARD =================
void gaitBackward() {
  t -= speedFactor;  // reverse motion

  for (int i = 0; i < 4; i++) {

    float phase = (i % 2 == 0) ? 0 : PI;

    float hip = 90 + x_amp * sin(t + phase);
    float knee = 90 + z_amp * sin(t + phase + PI/2);

    int hipIndex = i;
    int kneeIndex = i + 4;

    if (i == 1 || i == 3) {
      hip = 180 - hip;
      knee = 180 - knee;
    }

    setServo(hipIndex, hip);
    setServo(kneeIndex, knee);
  }
}

// ================= TURN LEFT =================
void turnLeft() {
  t += speedFactor;

  for (int i = 0; i < 4; i++) {

    float phase = (i % 2 == 0) ? 0 : PI;

    // Left legs forward, right legs backward
    float direction = (i == 0 || i == 2) ? 1 : -1;

    float hip = 90 + direction * x_amp * sin(t + phase);
    float knee = 90 + z_amp * sin(t + phase + PI/2);

    int hipIndex = i;
    int kneeIndex = i + 4;

    if (i == 1 || i == 3) {
      hip = 180 - hip;
      knee = 180 - knee;
    }

    setServo(hipIndex, hip);
    setServo(kneeIndex, knee);
  }
}

// ================= TURN RIGHT =================
void turnRight() {
  t += speedFactor;

  for (int i = 0; i < 4; i++) {

    float phase = (i % 2 == 0) ? 0 : PI;

    // Opposite of left turn
    float direction = (i == 0 || i == 2) ? -1 : 1;

    float hip = 90 + direction * x_amp * sin(t + phase);
    float knee = 90 + z_amp * sin(t + phase + PI/2);

    int hipIndex = i;
    int kneeIndex = i + 4;

    if (i == 1 || i == 3) {
      hip = 180 - hip;
      knee = 180 - knee;
    }

    setServo(hipIndex, hip);
    setServo(kneeIndex, knee);
  }
}

// ================= STOP =================
void stopRobot() {
  for (int i = 0; i < 8; i++) {
    setServo(i, 90);
  }
}

// ================= LOOP =================
void loop() {

  // 🔵 Read Bluetooth CLEANLY
  while (BT.available()) {
    char incoming = BT.read();

    if (incoming == '\n' || incoming == '\r') continue;

    if (incoming == 'F' || incoming == 'B' || incoming == 'L' || incoming == 'R' || incoming == 'S') {
      cmd = incoming;
      Serial.print("CMD: ");
      Serial.println(cmd);
    }
  }

  // 🔴 Execute command continuously
  switch (cmd) {

    case 'F':
      gaitForward();
      break;

    case 'B':
      gaitBackward();
      break;

    case 'L':
      turnLeft();
      break;

    case 'R':
      turnRight();
      break;

    case 'S':
      stopRobot();
      break;
  }

  delay(5);  // smooth motion
}