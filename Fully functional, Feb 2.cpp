int ScreenSource = 5;                       
int HotSource = 6;
int ColdSource = 7;
int ScreenReceive = 8;
int HotReceive = 9;
int ColdReceive = 10;
int ledPin = 13;
int Score = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(ScreenSource, OUTPUT);
pinMode(HotSource, OUTPUT);
pinMode(ColdSource, OUTPUT);
pinMode(ScreenReceive, INPUT);
pinMode(HotReceive, INPUT);
pinMode(ColdReceive, INPUT);
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
                                            
 (Score) = 0;                               //Resets score count to zero.

 digitalWrite(ScreenSource, HIGH);          //Inject signal onto output XLR pin 1
 if (digitalRead(ScreenReceive) == HIGH && digitalRead(HotReceive) == LOW && digitalRead(ColdReceive) == LOW)    // Check if signal is received on XLR input pin 1 and pin 1 only.
 {
  ++(Score);                                //Increment score count by one if above condition is true
 }
 digitalWrite(ScreenSource, LOW);           //Remove signal from output XLR pin 1
 

  digitalWrite(HotSource, HIGH);          //Inject signal onto output XLR pin 2
 if (digitalRead(HotReceive) == HIGH && digitalRead(ScreenReceive) == LOW && digitalRead(ColdReceive) == LOW)    // Check if signal is received on XLR input pin 2 and pin 2 only.
 {
  ++(Score);               //Increment score count by one if above condition is true
 }
 digitalWrite(HotSource, LOW);           //Remove signal from output XLR pin 2
 

  digitalWrite(ColdSource, HIGH);          //Inject signal onto output XLR pin 3
 if (digitalRead(ColdReceive) == HIGH && digitalRead(ScreenReceive) == LOW && digitalRead(HotReceive) == LOW)    // Check if signal is received on XLR input pin 3 and pin 3 only.
 {
  ++(Score);               //Increment score count by one if above condition is true
 } 
 digitalWrite(ColdSource, LOW);           //Remove signal from output XLR pin 3
 

 if ((Score) == 3)                       //Check if score is 3, which is only possible if all pins have passed.
 { digitalWrite(ledPin, HIGH); }         //Turn on LED if all pins have passed (score is 3).  
 else {digitalWrite(ledPin, LOW); }      //Turn LED off if score is not 3, necessary to cause "re-fail" after good cable removed.
 


}