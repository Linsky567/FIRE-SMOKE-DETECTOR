// C++ code
//
int gas_sensor = 0;

int tempsensor = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  gas_sensor = analogRead(A0);
  tempsensor = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -20, 120);
  Serial.println(tempsensor);
  Serial.println(gas_sensor);
  if (gas_sensor >= 400) {
    tone(7, 5274, 100); // play tone 100 (E8 = 5274 Hz)
  } else {
    digitalWrite(7, LOW);
  }
  if (tempsensor <= 30) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}