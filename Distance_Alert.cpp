int gled = 12;
int rled = 10;
int buzzer = 2;
int trigPin = 7;
int echoPin = 8;

void setup() {
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(buzzer, OUTPUT);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration / 58;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance > 30) {
    digitalWrite(gled, HIGH);
    digitalWrite(rled, LOW);
    digitalWrite(buzzer, LOW);
  }
  else if (distance <= 30 && distance > 15) {
    
    digitalWrite(rled, HIGH);
    digitalWrite(gled, LOW);
    digitalWrite(buzzer, LOW);
    delay(400);
    digitalWrite(rled, LOW);
    digitalWrite(gled, LOW);
    digitalWrite(buzzer, LOW);
    delay(400);
  }
  else if (distance <= 15) {
    digitalWrite(rled, HIGH);
    digitalWrite(gled, LOW);
    digitalWrite(buzzer, HIGH);
  }
  
  delay(50);  
}

