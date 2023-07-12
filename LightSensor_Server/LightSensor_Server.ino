//beacuse the relay doen not work:
#define green_led D6// green led = relay is on/off
#define LDR A0


    
unsigned long duration ,
              onHold = 0,
              currentTime,
              lastTime=0;     
float lightLvl;
int   heat,
      cnt ;     

bool R_LedIsOn;

bool G_LedIsOn; 

#define STAGE 
int HT=1,
    ON=2,
    PWM=3,
    HLD=4;

void setup() {
  Serial.begin(9600);
  
   pinMode(LDR, OUTPUT);
   pinMode(green_led, OUTPUT);
  
   G_LedIsOn = false;
   digitalWrite(green_led,LOW);
   
   Serial.print("start");
   
}
//--------------------------------//
void loop() {
  
  switch(STAGE){
    case 1:
    Serial.println("stage 1 HT");
     Serial.println("check temperature...");
     heat = map((LDR),0,1023,0,255);     
     if(heat > 0){
        STAGE = ON;          
      }      
    break;
    
    case 2:
      Serial.println("stage 2 ON");
      Serial.println("check Light Level avarage:");
      
      currentTime = millis();      
      lightLvl = map((LDR),0,1023,0,255);
      float avrg = checkLightAvrg(lightLvl);
      
       if(currentTime - millis()){
        
        
        }
    Serial.println(lightLvl);
      
    break;
    
    case 3:
      Serial.println("stage PWM");
      Serial.println("wait for input...");
      if(duration*1000>2000){
        STAGE = ON;
        }else{
          Serial.println("stage 4");
          }
      
    break;
    
    case 4:
      Serial.println("stage 4");
      Serial.println("on hold...");
      Serial.println("wait for input...");
      currentTime = millis();
      if(currentTime - lastTime >= duration)){
        cnt = 0;        
        STAGE = HT;
        }else{
           Serial.println("duration must be greater then 2 seconds...");
          }
    break;
    
    
    }
  
}
//--------------------------------//

//---------G-LED-------------------------// 
void G_ledOff() {
      digitalWrite(green_led, LOW);
      G_LedIsOn = false;
}
void G_ledOn() {
      digitalWrite(green_led, HIGH);
      G_LedIsOn = true;
}


//----------production-stages-managment-------------------------// 

float checkLightAvrg(float lt){
  currentTime = millis();
  if(currentTime - lastTime >= duration*1000)))
    float avrg =lt;
    if(lt>2){
      avrg+=
      cnt++;
      }      
      return avrg/lt;      
}




















  
