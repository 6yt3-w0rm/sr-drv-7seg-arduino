/*  0-99 digit 7-segment display using x2 CD4511 7-segment binary decoder per 8bit shift register 74HC595n
 *   21-09-2019
 *   AUTHOR : LIM WIKY
 *   
 *   ICs : CD4511     x2
 *         74HC595n   x1
 *         
 *   Parts
 *   Arduino board                        (obviously)
 *   7-segment display common cathode     x2
 *   1k resistor                          x2
*/




int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int pot = 0;
int raw = 0;
byte a = 0b0000;
byte b = 0b0000;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);   
  
}

void loop() {  
    raw = analogRead(A0);
    pot = map(analogRead(A0), 0, 1023, 0, 99);
     Serial.print("raw : ");
     Serial.println(raw);
     Serial.print("pot : ");
     Serial.println(pot);
     a = pot/10; 
     b = pot%10;
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, a*10000+b); 
    digitalWrite(latchPin, HIGH);
    delay(100);


  }
