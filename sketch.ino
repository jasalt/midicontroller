// Multiplexer selector pins
int mpA = 2; // Yellow cable
int mpB = 3; // Red cable
int mpC = 4; // Gray cable
int mpIN = A1; // Purple COM OUT/IN

// Number of potentiometers
const int potCount = 8;
// Array for voltages of potentiometers
int potVoltagesArray [ potCount ];


// the setup routine runs once when you press reset:
void setup() {
  pinMode(mpA, OUTPUT);
  pinMode(mpB, OUTPUT);
  pinMode(mpC, OUTPUT);
  Serial.begin(9600);
}


int i;
int j;

void loop() {
  for (i = 0; i < potCount; i++) {
    potVoltagesArray[i] = readMultiplexerPin(i);
    delay(50);
  }

  for (j = 0; j < potCount; j++) {
    Serial.print("Pinni ");
    Serial.print(j + 1);
    Serial.print(" ");
    Serial.println(potVoltagesArray[j]);
  }

  delay(2000);
}


int readDelay = 50;
int readMultiplexerPin(int pinNumber) {
  switch (pinNumber)
    {
    case 0:
      {
        digitalWrite(mpA, LOW);
        digitalWrite(mpB, LOW);
        digitalWrite(mpC, LOW);
        delay(readDelay);
        return analogRead(mpIN);
      }
    case 1:
      {
        digitalWrite(mpA, HIGH);
        digitalWrite(mpB, LOW);
        digitalWrite(mpC, LOW);
        delay(readDelay);
        return analogRead(mpIN);
      }
    case 2:
      {
        digitalWrite(mpA, LOW);
        digitalWrite(mpB, HIGH);
        digitalWrite(mpC, LOW);
        delay(readDelay);
        return analogRead(mpIN);
      }
    case 3:
      {
        digitalWrite(mpA, HIGH);
        digitalWrite(mpB, HIGH);
        digitalWrite(mpC, LOW);
        delay(readDelay);
        return analogRead(mpIN);
      }
    case 4:
      {
        digitalWrite(mpA, LOW);
        digitalWrite(mpB, LOW);
        digitalWrite(mpC, HIGH);
        delay(readDelay);
        return analogRead(mpIN);
      }
    case 5:
      {
        digitalWrite(mpA, HIGH);
        digitalWrite(mpB, LOW);
        digitalWrite(mpC, HIGH);
        delay(readDelay);
        return analogRead(mpIN);
      }
    case 6:
      {
        digitalWrite(mpA, LOW);
        digitalWrite(mpB, HIGH);
        digitalWrite(mpC, HIGH);
        delay(readDelay);
        return analogRead(mpIN);
      }
    case 7:
      {
        digitalWrite(mpA, HIGH);
        digitalWrite(mpB, HIGH);
        digitalWrite(mpC, HIGH);
        delay(readDelay);
        return analogRead(mpIN);
      }
    }
}
