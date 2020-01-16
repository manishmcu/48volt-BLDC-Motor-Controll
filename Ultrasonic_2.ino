 
 /* Ultrasonic Sensor HC-SR04 and Arduino */

 // defines pins numbers
 const int trigPin = 10;
 const int echoPin = 11;
 int led=4; 
 int mtr2=6;
 int brk=7;
 int rev=8;

 //defines variables
 long duration;
 int distance;

 void setup() {
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 Serial.begin(9600); // Starts the serial communication
 pinMode(led,OUTPUT);
  pinMode(mtr1,OUTPUT);
  pinMode(mtr2,OUTPUT);
 }

 void loop() {
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

 // Prints the distance on the Serial Monitor35. Serial.print(&quot;Distance: &quot;);
Serial.println(distance);
  if(distance<=100 && distance >40)                  //Slow down
  {
     analogWrite(mtr1,LOW);
     digitalWrite(mtr2,150);
     Serial.println("OBSTACLE !!!");
 /* digitalWrite(led,HIGH);
  delay(200);
      analogWrite(mtr1,LOW);
      digitalWrite(mtr2,150);
      Serial.println("OBSTACLE !!!");
  digitalWrite(led,LOW);
  delay(200);*/}
 
  if(distance<=40 && distance>10)                  //Motor Off
  {
      digitalWrite(mtr1,LOW);
      digitalWrite(mtr2,HIGH);
      Serial.println("Ride Slow <<<");
  digitalWrite(led,HIGH);
  delay (2000);
      digitalWrite(mtr1,LOW);
      digitalWrite(mtr2,HIGH);
      Serial.println("Ride Slow <<<");
  digitalWrite(led,LOW);
  delay(2);
  }

  if(distance<=10)
  { 
    digitalWrite(brk,HIGH);}                    //Apply break
  else                                          //Normal Break
  { digitalWrite(led,LOW);
  digitalWrite(mtr1,HIGH);
  digitalWrite(mtr2,HIGH);}  
 }
