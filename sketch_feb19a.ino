  // defines pins numbers
  const int trigPin = 9;
  const int echoPin = 10;
  int pin=2;
  int pin2=4;
  int pin3=6;
  // defines variables
  long duration;
  int distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(pin,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

    if(distance<5){
      digitalWrite(2,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(4,HIGH);
    }
    else if(distance<10){
      digitalWrite(4,HIGH);
      digitalWrite(2,HIGH);

      digitalWrite(6,LOW);
    }
    else if(distance<20){
          digitalWrite(6,HIGH);
          delay(1000);
          digitalWrite(6,LOW);
          digitalWrite(2,LOW);
          digitalWrite(4,LOW);
          delay(1000);    
    }
  
}
