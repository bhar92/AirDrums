void noteOn(byte channel, byte note, byte velocity)
{
  
  midiMsg(channel+0x90, note, velocity);
}
void midiMsg(byte cmd, byte data1, byte data2)
  {Serial.write(cmd);
  
  
  Serial.write(data1);
  Serial.write(data2);
  }  
const int numSnareReadings = 10;
const int numHighHatReadings = 2;
const int numKickReadings = 5;
const int numCrashReadings = 10;

int snareReadings[numSnareReadings];
int snareIndex = 0;
int snareTotal = 0;
int snareAverage = 0;
int currentSnareState;
int switchSnareState = 0;

int highHatReadings[numHighHatReadings];
int highHatIndex = 0;
int highHatTotal = 0;
int highHatAverage = 0;
int currentHighHatState; 
int switchHighHatState = 0;

int crashReadings[numCrashReadings];
int crashIndex = 0;
int crashTotal = 0;
int crashAverage = 0;
int currentCrashState; 
int switchCrashState = 0;

int kickReadings[numKickReadings];
int kickIndex = 0;
int kickTotal = 0;
int kickAverage = 0;
int currentKickState; 
int switchKickState = 0;

long previousMillis1 = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;
long previousMillis4 = 0;

long interval1 = 100;
long interval2 = 100;
long interval3 = 100;
long interval4 = 100;

void setup()
  {
    Serial.begin(36000);
    for (int thisReading = 0; thisReading < numSnareReadings; thisReading++)
    snareReadings[thisReading] = 0;
    
    for (int thisReading = 0; thisReading < numHighHatReadings; thisReading++)
    highHatReadings[thisReading] = 0;
    
    for (int thisReading = 0; thisReading < numKickReadings; thisReading++)
    kickReadings[thisReading] = 0;
    
    for (int thisReading = 0; thisReading < numKickReadings; thisReading++)
    crashReadings[thisReading] = 0;
  }

void loop()
{
   unsigned long currentMillis = millis();
  
  snareAverage = snareTotal / numSnareReadings;
  snareTotal = snareTotal - snareReadings[snareIndex];
  snareReadings[snareIndex] = analogRead(A0);
  snareTotal = snareTotal + snareReadings[snareIndex];
  snareIndex = snareIndex + 1;
  
  if(snareIndex >= numSnareReadings)
    snareIndex = 0;
    
    snareAverage = snareTotal / numSnareReadings;
   
   currentSnareState = snareAverage; 
     if( currentSnareState > 575 && (currentMillis - previousMillis1) > interval1)
       {
        
         previousMillis1 = currentMillis;
         noteOn(9, 38, 120);
       }
       
   
  highHatAverage = highHatTotal / numHighHatReadings;
  highHatTotal = highHatTotal - highHatReadings[highHatIndex];
  highHatReadings[highHatIndex] = analogRead(A1);
  highHatTotal = highHatTotal + highHatReadings[highHatIndex];
  highHatIndex = highHatIndex + 1;
  
  if(highHatIndex >= numHighHatReadings)
    highHatIndex = 0;
    
    highHatAverage = highHatTotal / numHighHatReadings;
   
   currentHighHatState = highHatAverage; 
     if( currentHighHatState > 550 && (currentMillis - previousMillis2) > interval2 )
       {
         previousMillis2 = currentMillis;
         noteOn(9, 46, 120);
         
         }    
      
       
  kickAverage = kickTotal / numKickReadings;
  kickTotal = kickTotal - kickReadings[kickIndex];
  kickReadings[kickIndex] = analogRead(A2);
  kickTotal = kickTotal + kickReadings[kickIndex];
  kickIndex = kickIndex + 1;
  
  if(kickIndex >= numKickReadings)
    kickIndex = 0;
    
    kickAverage = kickTotal / numKickReadings;
   
   currentKickState = kickAverage; 
     if( currentKickState > 360 && (currentMillis - previousMillis3) > interval3 )
       {
         previousMillis3 = currentMillis;
         noteOn(9, 35, 120);
         
         }   
   
  crashAverage = crashTotal / numCrashReadings;
  crashTotal = crashTotal - crashReadings[crashIndex];
  //crashReadings[crashIndex] = analogRead(A3);
  crashTotal = crashTotal + crashReadings[crashIndex];
  crashIndex = crashIndex + 1;
  
  if(crashIndex >= numCrashReadings)
    crashIndex = 0;
    
    crashAverage = crashTotal / numCrashReadings;
   
   currentCrashState = crashAverage; 
     if( currentCrashState < 10 && (currentMillis - previousMillis4) > interval2 )
       {
         previousMillis4 = currentMillis;
         //noteOn(9, 55, 120);
         
         }    
            
         
       
}       
       

