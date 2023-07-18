#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup() {
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);

}

  void loop(){
  //digitalWrite(4, HIGH);
  if(analogRead(0) < 750){
  digitalWrite(13, HIGH);
  Serial.read= 's';
} 
else{
  digitalWrite(13, LOW);
}
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
   /* case 'r':
      RecieveMessage();
      break;*/
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}







 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\">Phone number<\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("INTRUDER ALERT!!!!!!");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
 
