void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
}

String rx_byte = "";

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    Serial.print("Select either H or L");
    // check if a number was received
    if (rx_byte.equals('H')){
      Serial.print("High was selected! ");
      digitalWrite(8,HIGH);
      delay(4000);
    }
    else{
      Serial.println("Revert to Low!");
      digitalWrite(8,LOW);
      delay(2000);
    }
  }
}
