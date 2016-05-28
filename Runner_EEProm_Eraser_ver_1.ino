
/*----Runner EEProm Eraser--------
 * 
 *  Run This before uploading multiwii code to ensure  
 *  no lingering parameters are left in the EEprom.
 *  
 *  This code will set all the bytes in EEProm to Zero
 *  
 *  
 */
 #include <EEPROM.h>
 
#define   BUZZERPIN_ON              PORTB |= (1<<7);PORTC |= 1<<5;
#define   BUZZERPIN_OFF             PORTB &= ~(1<<7);PORTC &= ~(1<<5);
#define  BUZZERPIN_TOGGLE          PINB  |= (1<<7);
#define  LEDPIN_TOGGLE              PINC  |= (1<<7);
#define   LEDPIN_ON                 PORTC |= (1<<7);
#define   LEDPIN_OFF                PORTC &= ~(1<<7);


#define STABLEPIN_ON               PORTC |= 1<<6;
#define STABLEPIN_OFF              PORTC &= ~(1<<6);

unsigned long previousMillis = 0;

void setup() {
  
  
  // put your setup code here, to run once:
  Serial.begin(115200);  
  Serial.println("Run this program before updating Runner firmware.\n");
  

  pinMode(31, OUTPUT);  // Stable Pin Left LED
  pinMode(30, OUTPUT);   //LED Pin  - Right LED
  pinMode(32, OUTPUT); //Buzzer  --needs Pin 13 enabled with it!!!
  pinMode(13, OUTPUT);  //Relay

//  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//  digitalWrite(31, LOW);    // turn the LED off by making the voltage LOW
//  digitalWrite(30, LOW);
//  digitalWrite(32, LOW);
  STABLEPIN_ON;
   
Serial.println("Enter y to erase eeprom");
   

   
}

void loop() {
int charRecieved;
int charCount = 0;  
  // put your main code here, to run repeatedly:
 
 if (Serial.available() > 0) {
  charRecieved = Serial.read();
  Serial.println(char(charRecieved));
   Serial.print("\n"); 
    if (charRecieved == 'y' | charRecieved == 'Y') {
        Serial.println("Beginning EEProm Erase\n");
        LEDPIN_ON;
        BUZZERPIN_ON;
        for (int i = 0 ; i < EEPROM.length() ; i++) {
          EEPROM.write(i, 0);
           Serial.print("!");
          BUZZERPIN_TOGGLE;
          LEDPIN_TOGGLE;
          charCount++;
          if (charCount > 80) {
            Serial.print("\n");
            charCount = 0;
          }
          delay(10);
       } //end for look
        LEDPIN_OFF;
        BUZZERPIN_OFF;
    Serial.println("\nFinished EEProm Erase");
 }  // end if charRecieved

 
  } //end if SerialAvailable

} //end loop
