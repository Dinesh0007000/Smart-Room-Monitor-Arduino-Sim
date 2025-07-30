#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;       
const int humidityPin = A1;   
const int buzzerPin = 8;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 6;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Temperature from TMP36
  int sensorVal = analogRead(tempPin);
  float voltage = sensorVal * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  // Simulated Humidity from potentiometer
  int humidityVal = analogRead(humidityPin);
  float humidity = map(humidityVal, 0, 1023, 0, 100);  // % humidity

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatureC, 1);
  lcd.print("C H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  // RGB and Buzzer logic
  if (temperatureC > 30) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, HIGH);
  } else if (temperatureC < 20) {
    digitalWrite(bluePin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(buzzerPin, LOW);
  } else {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);
}
