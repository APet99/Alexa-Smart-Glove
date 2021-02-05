
// These constants won't change:
const int sensorPinTHUMB = A0;    // pin that the THUMB flex sensor is attached to

// variables:
int sensorValueTHUMB = 0;  
int sensorMaxTHUMB = 0;
int sensorMinTHUMB = 0;

// the sensor value
void setup() {
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
Serial.begin (9600);
 // calibrate during the first five seconds 
 while (millis() < 5000) {
     sensorValueTHUMB = analogRead(sensorPinTHUMB);
//--------------------------------------------------
   // record the maximum sensor value
   if (sensorValueTHUMB > sensorMaxTHUMB) {
    sensorMaxTHUMB = sensorValueTHUMB;
   }
   
   //--------------------------------------------------------
   // record the minimum sensor value
   if (sensorValueTHUMB < sensorMinTHUMB) {
     sensorMinTHUMB = sensorValueTHUMB;
   }
  
 }
 //Serial.print ("LowTHUMB = ");
 //Serial.println (sensorMinTHUMB);
 //Serial.print ("HighTHUMB = ");
 //Serial.println (sensorMaxTHUMB);
 //Serial.println ("             ");
 
 delay (1000);
}
void loop() {
// read the sensor:
 sensorValueTHUMB = analogRead(sensorPinTHUMB);

 // apply the calibration to the sensor reading
 sensorValueTHUMB = map(sensorValueTHUMB, sensorMinTHUMB, sensorMaxTHUMB, 1, 255);
 // in case the sensor value is outside the range seen during calibration
 sensorValueTHUMB = constrain(sensorValueTHUMB, 1, 255);
 Serial.println ("-------------------");
 Serial.print ("sensorValue-THUMB = ");
 Serial.println (sensorValueTHUMB);
 
if (sensorValueTHUMB <50) {
      digitalWrite(13,HIGH);
      digitalWrite(8,LOW);
 }
 else {
 } 
 if (sensorValueTHUMB > 180) {
         digitalWrite(8,HIGH);
         digitalWrite(13,LOW);
 }
 else {
 }
// delay (1000);
}
