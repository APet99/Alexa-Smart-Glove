/* Alexa and Arduino at your fingertips
 *  Created by: Alex Peterson on 10/2/2018
 *  
 *  This program reads data input from flexible potentiometers to calculate
 *  an angle, which is used to output a Serial Port message to an awaiting program
 *  which executes auditory output.
*/

const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg
// index finger
const int FLEX_PIN0 = A0;
// middle finger
const int FLEX_PIN1 = A1;
// ring finger
const int FLEX_PIN2 = A2;

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN0, INPUT);
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
}

void loop() 
{
  // associates the flex sensor with the pin it's connected to
  int flexADC_0 = analogRead(FLEX_PIN0);
  int flexADC_1 = analogRead(FLEX_PIN1);
  int flexADC_2 = analogRead(FLEX_PIN2);

  // calculates resistance and ohms. (used to find angle of bend)
  float flexV_0 = flexADC_0 * VCC / 1023.0; // resistance
  float flexR_0 = R_DIV * (VCC / flexV_0 - 1.0); // __ ohms
  
  float flexV_1 = flexADC_1 * VCC / 1023.0; // resistance
  float flexR_1 = R_DIV * (VCC / flexV_1 - 1.0); // __ ohms

  float flexV_2 = flexADC_2 * VCC / 1023.0; // resistance
  float flexR_2 = R_DIV * (VCC / flexV_2 - 1.0); // __ ohms

  
  // Calculated resistance estimating bend angle:
  float angle_0 = map(flexR_0, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
  float angle_1 = map(flexR_1, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
  float angle_2 = map(flexR_2, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);     

  // output messages based on finger bend combinations:     
  // None fingers are bent.
  if (angle_0 <= 50   &&   angle_1 <= 50   &   angle_2 <=50){
      Serial.println();
      delay(1000);
  }
  
  // Only the first finger is bent.
  else if (angle_0 > 50   &&   angle_1 <= 50   &&   angle_2 <= 50){
      Serial.println("time");
      delay(2000);
    }

  // Only the seccond finger is bent.
  else if (angle_0 <= 50   &&   angle_1 > 50   &&   angle_2 <= 50){
      Serial.println("coinFlip");
      delay (2000);
    }

  // Only the third finger is bent.  
  else if (angle_0 <= 50   &&   angle_1 <= 50   &&   angle_2 > 50){
      Serial.println("tellWeather");
      delay(2000);
    }

  // Only the first two fingers are bent.
  else if (angle_0 > 50   &&   angle_1 > 50   &&   angle_2 <= 50){
      Serial.println("tellFact");
      delay (2000);
    }

  // Only the last two fingers are bent.
  else if (angle_0 <= 50   &&   angle_1 > 50   &&   angle_2 > 50){
      Serial.println("tellQuote");
      delay(2000);
    }

  // All three fingers are bent.
  else if (angle_0 > 50   &&   angle_1 > 50   &&   angle_2 > 50){
      Serial.println("playSong");
      delay(2000);
    }

  // re-sets the angle value as 0. The next iteration will calculate a new angle.
  angle_0 = 0;
  angle_1 = 0;
  angle_2 = 0;
}
