int alarmPin = 4;
int sensorPin = A0;
int startCheckCount = 10;

void setup() {
  //Serial.begin(115200);
  pinMode(alarmPin, OUTPUT);

  int check  = 0;
  do {
    delay(2000);
    if (CheckSensor()) {
      check = 0;
    } else {
      check++;
    }
  } while (check < startCheckCount);
}

bool CheckSensor() {
  // double check
  if (analogRead(sensorPin) > 450) {
    delay(50);
    return analogRead(sensorPin) > 450;
  }

  return false;
}

void loop() {
  //Serial.println("--------------------------------");
  if (CheckSensor()) {
    digitalWrite(alarmPin, HIGH);
  } else {
    digitalWrite(alarmPin, LOW);
  }

  delay(50);
}
