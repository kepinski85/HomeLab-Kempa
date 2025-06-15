#include <Wire.h>
#include <Adafruit_BME280.h>

#define MQ135_PIN A0
#define TRIG_PIN 9
#define ECHO_PIN 8

Adafruit_BME280 bme;
bool bmeOK = false;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  bmeOK = bme.begin(0x76);  // lub 0x77 je?li Twï¿½j BME280 ma inny adres
}

String airQualityStatus(float voltage) {
  if (voltage < 1.0) return "Dobre";
  else if (voltage < 2.0) return "Umiark.";
  else return "Zle";
}

void loop() {
  if (!bmeOK) return;

  // MQ135 ? napi?cie
  int raw = analogRead(MQ135_PIN);
  float voltage = raw * (5.0 / 1023.0);

  // HC-SR04 ? odleg?o??
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2.0;

  // BME280 ? temp/wilg/ci?nienie
  float temp = bme.readTemperature();
  float hum = bme.readHumidity();
  float press = bme.readPressure() / 100.0;

  // JSON przez USB
  Serial.print("{\"temp\":");
  Serial.print(temp);
  Serial.print(",\"hum\":");
  Serial.print(hum);
  Serial.print(",\"press\":");
  Serial.print(press);
  Serial.print(",\"gas\":");
  Serial.print(voltage, 2);
  Serial.print(",\"dist\":");
  Serial.print(distance);
  Serial.print(",\"air_status\":\"");
  Serial.print(airQualityStatus(voltage));
  Serial.println("\"}");

  delay(3000);
}
