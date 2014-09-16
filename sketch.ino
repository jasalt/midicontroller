#include <SoftwareSerial.h>
// todo http://arduino.cc/en/Tutorial/Midi?from=Tutorial.MIDI

// Multiplexer selector pins
int mpA = 2; // Yellow cable
int mpB = 3; // Red cable
int mpC = 4; // Gray cable
int mpIN = A1; // Purple COM OUT/IN

// Number of potentiometers
const int potCount = 8;
// Array for voltages of potentiometers
int potVoltagesArray [ potCount ];

SoftwareSerial midiSerial(2, 3);

// the setup routine runs once when you press reset:
void setup() {
  pinMode(mpA, OUTPUT);
  pinMode(mpB, OUTPUT);
  pinMode(mpC, OUTPUT);

  Serial.begin(9600);
  midiSerial.begin(31250);
}


int i;
int j;

void loop() {
  //testPin1();
  
  //noteOn(0x90, 30, 0x45);
  loopAll();

}


int value;
void testPin1() {
  digitalWrite(mpA, HIGH);
  digitalWrite(mpB, HIGH);
  digitalWrite(mpC, HIGH);

  delay(100);
  value = analogRead(mpIN);

  Serial.print("Pinni ");
  Serial.print(1);
  Serial.print(" ");
  Serial.println(value);
  delay(1000);
}

void loopAll() {
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

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
//
void noteOn(byte cmd, byte data1, byte data2) {
  midiSerial.write(cmd);
  midiSerial.write(data1);
  midiSerial.write(data2);

  //prints the values in the serial monitor so we can see what note we're playing
  Serial.print("cmd: ");
  Serial.print(cmd);
  Serial.print(", data1: ");
  Serial.print(data1);
  Serial.print(", data2: ");
  Serial.println(data2);
}
