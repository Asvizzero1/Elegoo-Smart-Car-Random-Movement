// TB6612 Pin Definitions
#define PWMA 5     // Speed control for left motors
#define AIN1 8     // Direction control for left motors
#define PWMB 6     // Speed control for right motors
#define BIN1 7     // Direction control for right motors
#define STBY 3     // Standby pin (must be HIGH to operate)

// Speed settings
#define MAX_SPEED 200 // Maximum speed (0-255)

void setup() {
  // Initialize motor driver pins
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(STBY, OUTPUT);

  // Enable motor driver
  digitalWrite(STBY, HIGH);

  // Seed random number generator
  randomSeed(analogRead(A0));
}

void loop() {
  int action = random(0, 4);       // Random action: 0 = forward, 1 = backward, 2 = left, 3 = right
  int speed = random(100, MAX_SPEED); // Random speed (100 to MAX_SPEED)
  int duration = random(1000, 3000);  // Random duration (1-3 seconds)

  // Execute random movement
  switch (action) {
    case 0:
      moveForward(speed, duration);
      break;
    case 1:
      moveBackward(speed, duration);
      break;
    case 2:
      turnLeft(speed, duration);
      break;
    case 3:
      turnRight(speed, duration);
      break;
  }

  stopMotors(); // Stop after each movement
  delay(500);   // Pause between movements
}

// Function to move forward
void moveForward(int speed, int duration) {
  analogWrite(PWMA, speed);
  digitalWrite(AIN1, HIGH);
  analogWrite(PWMB, speed);
  digitalWrite(BIN1, HIGH);
  delay(duration);
}

// Function to move backward
void moveBackward(int speed, int duration) {
  analogWrite(PWMA, speed);
  digitalWrite(AIN1, LOW);
  analogWrite(PWMB, speed);
  digitalWrite(BIN1, LOW);
  delay(duration);
}

// Function to turn left
void turnLeft(int speed, int duration) {
  analogWrite(PWMA, speed / 2); // Reduce left motor speed
  digitalWrite(AIN1, HIGH);
  analogWrite(PWMB, speed);
  digitalWrite(BIN1, HIGH);
  delay(duration);
}

// Function to turn right
void turnRight(int speed, int duration) {
  analogWrite(PWMA, speed);
  digitalWrite(AIN1, HIGH);
  analogWrite(PWMB, speed / 2); // Reduce right motor speed
  digitalWrite(BIN1, HIGH);
  delay(duration);
}

// Function to stop all motors
void stopMotors() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

