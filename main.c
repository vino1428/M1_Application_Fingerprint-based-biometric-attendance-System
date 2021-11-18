#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
 
int getFingerprintIDez();
char data ;
 
// pin #4 is IN from sensor (GREEN wire)
// pin #5 is OUT from arduino  (WHITE wire)
SoftwareSerial mySerial(4, 5);
 
 
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
 
 
void setup()  
{
  Serial.begin(9600);
     // Bits per sec
 
  Serial.println("fingertest");
 
  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
 
  Serial.println("Waiting for valid finger...");
 
}
 
void loop()                     // run over and over again
{
 
 
  
    getFingerprintIDez();
}
 
uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
 
  // OK success!
 
  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
}
 
// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;
 
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;
 
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
 
  // found a match!
//  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
//  Serial.print(" with confidence of "); Serial.println(finger.confidence);
 
   if(finger.fingerID == 11) 
  {
 
Serial.println("stu1"); 
 
  delay(1000);
 
 }
  if(finger.fingerID == 2) 
  {
 
Serial.println("stu2"); 
 
  delay(1000);
 
 }
   if(finger.fingerID == 3) 
  {
 
Serial.println("stu3");
 
  delay(1000); 
 }
 
   
 else
  return finger.fingerID; 
 
 // Serial.println("Invalid User\n");
 
  
 
}
