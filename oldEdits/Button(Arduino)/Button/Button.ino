

void setup() {
  const int lightPin = 10;
  const int buttonPin1 = 2;
  const int buttonPin2 = 12;
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin,OUTPUT);
  //pinMode(buttonPin1,INPUT);
  //pinMode(buttonPin2,INPUT);

  pinMode(A1,INPUT);
}

void loop() {
 int buttonState1 = digitalRead(2);
 int buttonState2 = digitalRead(12);
 //int buttonStateSensor = analogRead(A1);

 Serial.println(analogRead(A0));
if(buttonState1 == 1 && buttonState2 == 0){
  Serial.print("lights");
  delay(1000);
} 
if(buttonState1 == 0 && buttonState2 == 1){
  Serial.print("joke");
  delay(1000);
}
if(buttonState1 == 1 && buttonState2 == 1){
  Serial.print("time");
  delay(1000);
}
//if(buttonState1 == 0 && buttonState2 == 0){
  //Serial.println();
  //delay(1000);
//}


 /*// put your main code here, to run repeatedly:
  if(Serial.available()){
    String info;
    info = Serial.readStringUntil('\n');
    if(info.equals("ON")){
      digitalWrite(10,HIGH);
      delay(2000);
      Serial.println("1");
      }
    else if (info.equals("OFF")){
      digitalWrite(10,LOW);
      Serial.println("The LED is OFF");
      }
    
    }
*/
}
