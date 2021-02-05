
// These constants won't change:
const int sensorPinONE = A0;    // pin that the THUMB flex sensor is attached to
int sensorValueONE = 0;  
int sensorMaxONE;
int sensorMinONE;
// the sensor value
void setup() {
Serial.begin (9600);
 // calibrate during the first five seconds 
 while (millis() < 5000) {
     sensorValueONE = analogRead(sensorPinONE);
   
   // record the maximum sensor value
   if (sensorValueONE > sensorMaxONE) {
     sensorMaxONE = sensorValueONE;
   }
   // record the minimum sensor value
   if (sensorValueONE < sensorMinONE) {
      sensorMinONE = sensorValueONE;
   }

Serial.print ("LowTHUMB = ");
 Serial.println (sensorMinONE);
 Serial.print ("HighONE = ");
 Serial.println (sensorMaxONE);
 Serial.println ("             ");
 delay (1000);
}
void loop() {
// read the sensor:
 sensorValueONE = analogRead(sensorPinONE);
 
 // apply the calibration to the sensor reading
 sensorValueONE = map(sensorValueONE, sensorMinONE, sensorMaxONE, 1, 255);

 sensorValueONE = constrain(sensorValueONE, 1, 255);
 
 Serial.println ("-------------------");
 Serial.print ("sensorValue-ONE = ");
/*if (sensorValueTHUMB <50 && sensorValueINDEX <50  && sensorValueMIDDLE <50 && sensorValueRING <50 ) {
   Serial.println  ("\n");
   Serial.println ("Hey Alexa"); 
   Serial.println  ("        ");
 }
 */
 delay (1000);
}
