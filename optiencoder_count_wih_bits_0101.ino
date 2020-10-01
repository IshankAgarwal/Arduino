
int encoderPin1 = 19;
int encoderPin2 = 18;
 
volatile int lastEncoded = 0;
 volatile int32_t encoderValue = 0;
 
long lastencoderValue = 0;
 
int lastMSB = 0;
int lastLSB = 0;
 
void setup() {
  Serial.begin (57600);
 
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);
 
 // digitalWrite(encoderPin1, HIGH); 
  //digitalWrite(encoderPin2, HIGH); 
 
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(encoderPin2), updateEncoder, CHANGE);
 
}
 
void loop(){ 
   
  Serial.println(encoderValue);
 
}
 
 
void updateEncoder(){
  
  volatile int MSB=digitalRead(encoderPin1); 
  volatile int LSB=digitalRead(encoderPin2); 
  
 
  volatile int encoded=(MSB << 1) | LSB; 
  volatile int sum=(lastEncoded << 2) | encoded;
 
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;
 
  lastEncoded = encoded; 
  
}
