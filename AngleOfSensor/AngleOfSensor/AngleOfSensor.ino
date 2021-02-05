
// where the flex sensors are plugged into the arduino
const int FLEX_PIN_0 = A0;
const int FLEX_PIN_1 = A1;
const int FLEX_PIN_2 = A2;

// constants
const float VCC = 4.96; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

void setup() 
{
  // establish the sensors input data rather than output.
  Serial.begin(9600);
  pinMode(FLEX_PIN_0, INPUT);
  pinMode(FLEX_PIN_1, INPUT);
  pinMode(FLEX_PIN_2, INPUT);
  
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC_0 = analogRead(FLEX_PIN_0);
  int flexADC_1 = analogRead(FLEX_PIN_1);
  int flexADC_2 = analogRead(FLEX_PIN_2);
  
  float flexV_0 = flexADC_0 * VCC / 1023.0;
  float flexV_1 = flexADC_1 * VCC / 1023.0;
  float flexV_2 = flexADC_2 * VCC / 1023.0;
  
  float flexR_0 = R_DIV * (VCC / flexV_0 - 1.0);
  float flexR_1 = R_DIV * (VCC / flexV_1 - 1.0);
  float flexR_2 = R_DIV * (VCC / flexV_2 - 1.0);

  // calculated angle of each finger
  float angle_0 = map(flexR_0, STRAIGHT_RESISTANCE, BEND_RESISTANCE,0, 90.0);
  float angle_1 = map(flexR_1, STRAIGHT_RESISTANCE, BEND_RESISTANCE,0, 90.0);
  float angle_2 = map(flexR_2, STRAIGHT_RESISTANCE, BEND_RESISTANCE,0, 90.0);
  delay(500);

  /* The angles of each finger is measured, and if the finger is bent
  more than 50 degrees, the finger is considered bent. */
  // no fingers are bent
  if (angle_0 <= 50   &&   angle_1 <= 50   &   angle_2 <=50){
      Serial.println();
  }
  // The first two fingers are bent.
  else if (angle_0 > 50   &&   angle_1 > 50   &&   angle_2 <= 50){
      Serial.println("c2");
      delay (3000);
    }
  // The last two fingers are bent.
  else if (angle_0 <= 50   &&   angle_1 > 50   &&   angle_2 > 50){
      Serial.println("c3");
      delay(3000);
    }
  // All three fingers are bent.
  else if (angle_0 > 50   &&   angle_1 > 50   &&   angle_2 > 50){
      Serial.println("c6");
      delay(3000);
    }
  // Only the first finger is bent.
  else if (angle_0 > 50   &&   angle_1 <= 50   &&   angle_2 <= 50){
      Serial.println("c4");
      delay(3000);
    }
  // Only the seccond finger is bent.
  else if (angle_0 <= 50   &&   angle_1 > 50   &&   angle_2 <= 50)
  {
      Serial.println("c1");
      delay (3000);
  }
  // Only the third finger is bent.  
  else if (angle_0 <= 50   &&   angle_1 <= 50   &&   angle_2 > 60)
  {
      Serial.println("c5");
      delay(3000);
  }
}
