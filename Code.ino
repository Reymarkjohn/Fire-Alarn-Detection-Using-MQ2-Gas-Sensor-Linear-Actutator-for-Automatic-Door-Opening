#define MQ2pin 0
#define Threshold 200

const int buzzer = 9;
const int ENA_PIN = 7;
const int IN1_PIN = 6;
const int IN2_PIN = 5;

int lock = 12;
float sensorValue;


void setup() {
  Serial.begin(9600);
  Serial.println("MQ2 warming up!");
  delay(20000);
  pinMode(lock, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  digitalWrite(ENA_PIN, HIGH);
  digitalWrite(lock,HIGH);

}

void loop() {
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if(sensorValue > Threshold)
  {
    Serial.print(" | Smoke detected!");
    tone(buzzer, 500);
    digitalWrite(lock, LOW);
    Function1();
  }
  else{
    Function2();
    noTone(buzzer);
    digitalWrite(lock, HIGH);
  }

  delay(2000); // wait 2s for next reading
}

void Function1(){

  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  delay(25000);
}

void Function2(){

  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);

}
