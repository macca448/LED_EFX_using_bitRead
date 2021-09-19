/*
 * In this sketch we use "bitRead" to create a LED array state
 * Sketch is uses a single 25mS millis() duty cycle.
 * Different effect sweep speeds using variables 
 */

#define     LED_COUNT 16
#define     DUTY_CYCLE 25
#define     UP true
#define     DOWN false
#define     MODEPIN A5
#define     BUTTONPIN A4
const byte  leds[] = {2,3,4,5,6,7,8,9,10,11,12,13,A0,A1,A2,A3};
int8_t      index=0, loopCount=0, timer=0, swState=0, buttonState,
            deBounce=0, lastButtonState=HIGH, lastSwState=0,
            modeState, lastModeState = HIGH;
uint32_t    ledState;
String      modeStr;
long        previousMillis=0;
bool        direction=UP, mode=true, push=false;
#include    "patterns.h"
#include    "effect_loops.h"
#include    "switching.h"

void setup() {
    Serial.begin(115200);
      for(int i = 0; i < LED_COUNT; i++){
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], LOW);
      }
    pinMode(MODEPIN, INPUT_PULLUP);
    pinMode(BUTTONPIN, INPUT_PULLUP);
      if(digitalRead(MODEPIN)==HIGH){
        modeStr = ("Auto");
      }else{
        modeStr = ("Manual");
      }
}

void loop(){
    uint8_t val = digitalRead(BUTTONPIN);
        if( val != lastButtonState){                      // Only when Manual "mode" enabled
          push = true;                                    // a button push moves to next effect
        }
    if(millis() - previousMillis > DUTY_CYCLE){           // Single loop duty cycle timer
        previousMillis = millis();
        modeState = digitalRead(MODEPIN);
            if(modeState == LOW){                         // Manual effect change if statement true
                mode = false;
                    if(push){                             // Button has heed pushed
                        deBounce++;
                           if(deBounce > 1){              // Button deBounce
                                deBounce = 0;                                
                                    if(val != buttonState){
                                        buttonState = val;
                                            if(buttonState == LOW){
                                                swState++;              //Advance to next effect
                                                push = false;
                                                index = 0;
                                                ledState = 0x00;
                                                direction = UP;
                                                  if(swState == 12){
                                                    ledState = 0x01;
                                                  }
                                                  if(swState > 13){   //Resets count
                                                    swState = 0; 
                                                  }
                                            }
                                    }
                            }
                            
                    }
                    change();
            }else{                       //Auto effect change
                    mode = true;
                    change();                
            }
            if(swState < 13){
                for(int i = 0; i < LED_COUNT; i++){
                  digitalWrite(leds[i], bitRead(ledState,i));       //Where the magic happens
                }
            }
            if(swState != lastSwState || modeState != lastModeState){
              if(modeState==HIGH){
                modeStr = ("Auto");
              }else{
                modeStr = ("Manual");
              }
              Serial.print("Current Effect = ");Serial.print(swState +1);
              Serial.print("\t Curren mode = ");Serial.println(modeStr);
              Serial.println("");
           }
           lastModeState = modeState;
           lastSwState = swState;
           lastButtonState = buttonState;
    }
}
