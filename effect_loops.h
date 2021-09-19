/*****************************************
********** Effect Pattern calls **********
*****************************************/

// All off to all on Sweep and Visa Versa
// Pattern change speed of 25mS
void effect1(){
      if(swState==0){                       //Back and forth index sweep for P1
          if(direction == UP){
            index++;
              if(index == 31){
                direction = DOWN;          
              }
          }else{
            index--;
              if(index < 1){
                direction = UP;
                  if(mode){
                    loopCount++;
                      if(loopCount > 2){
                        loopCount = 0;
                        swState = 1;
                        index = 0;
                      }        
                  }
              } 
          }
      }
      if(swState == 1){                   //Sweep index in ascending direction for P1
          index++;
            if(index == 31){
              index = 0;
                 if(mode){
                    loopCount++;
                      if(loopCount > 4){
                        loopCount = 0;
                        swState = 2;
                        index = 31;
                      }
                 }
            }
        }
      if(swState == 2){                   //Sweep index in descending direction for P1
          index--;
            if(index < 1){
              index = 31;
                 if(mode){
                    loopCount++;
                      if(loopCount > 4){
                        loopCount = 0;
                        swState = 3;
                        index = 0;
                      }
                 }
            }
        }
      ledState = p1[index];
      return;
}

// Two X 8 LED chase effect
// Pattern change speed of 50mS
void effect3(){                       //Back and forth index sweep for P2
      if(swState == 3){
          if(direction == UP){
            index++;
              if(index == 16){
                direction = DOWN;          
              }
          }else{
            index--;
              if(index < 1){
                direction = UP;
                  if(mode){
                    loopCount++;
                      if(loopCount > 2){
                        loopCount = 0;
                        swState = 4;
                        index = 0;
                      }        
                  }
              } 
          }
      }
      if(swState == 4){                   //Sweep index in ascending direction for P2
          index++;
            if(index == 16){
              index = 0;
                 if(mode){
                    loopCount++;
                      if(loopCount > 4){
                        loopCount = 0;
                        swState = 5;
                        index = 16;
                      }
                 }
            }
        }
      if(swState == 5){                   //Sweep index in descending direction for P1
          index--;
            if(index < 1){
              index = 16;
                 if(mode){
                    loopCount++;
                      if(loopCount > 4){
                        loopCount = 0;
                        swState = 6;
                        index = 0;
                      }
                 }
            }
        }
      ledState = p2[index];
      return;
}

// Inverse chase with 2 LEDS
// Pattern change speed of 75mS
void effect4(){                       //Back and forth index sweep for P3
      if(swState == 6){
          if(direction == UP){
            index++;
              if(index == 18){
                direction = DOWN;          
              }
          }else{
            index--;
              if(index < 1){
                direction = UP;
                  if(mode){
                    loopCount++;
                      if(loopCount > 2){
                        loopCount = 0;
                        swState = 7;
                        index = 0;
                      }        
                  }
              } 
          }
      }
      if(swState == 7){                   //Sweep index in ascending direction for P3
          index++;
            if(index == 18){
              index = 0;
                 if(mode){
                    loopCount++;
                      if(loopCount > 4){
                        loopCount = 0;
                        swState = 8;
                        index = 18;
                      }
                 }
            }
        }
      if(swState == 8){                   //Sweep index in descending direction for P3
          index--;
            if(index < 1){
              index = 18;
                 if(mode){
                    loopCount++;
                      if(loopCount > 4){
                        loopCount = 0;
                        swState = 9;
                        index = 0;
                      }
                 }
            }
        }
      ledState = p3[index];
      return;
}

// Every second LED chase with a 
// Pattern change speed of 75mS
void effect5(){
      if(swState == 9){                       //Back and forth index sweep for P4
          if(direction == UP){
            index++;
              if(index == 31){
                direction = DOWN;          
              }
          }else{
            index--;
              if(index < 1){
                direction = UP;
                  if(mode){
                    loopCount++;
                      if(loopCount > 2){
                        loopCount = 0;
                        swState = 10;
                        index = 0;
                      }        
                  }
              } 
          }
      }
      if(swState == 10){                   //Sweep index in ascending direction for P4
          index++;
            if(index == 31){
              index = 0;
                 if(mode){
                    loopCount++;
                      if(loopCount > 4){
                        loopCount = 0;
                        swState = 11;
                        index = 31;
                      }
                 }
            }
        }
      if(swState == 11){                   //Sweep index in descending direction for P4
         index--;
            if(index < 1){
              index = 31;
                if(mode){
                  loopCount++;
                      if(loopCount > 4){
                        loopCount = 0;
                        swState = 12;
                        index = 0;
                        return;
                      }
                }
            }
      }
      ledState = p4[index];
      return;
}

void effect2(){                           // Single LED Larson Style chase using
    if (direction==UP) {                  // "<< or >>" bit shift method
      ledState = ledState << 1;           // Pattern change speed is 50mS
        if (ledState == 0x10000) {
          ledState = 0x4000;
          direction = DOWN;
        }
    }else{
      ledState = ledState >> 1;
        if (ledState == 0x00) {
          ledState = 0x02;
          direction = UP;
            if(mode){
              loopCount++;
                if(loopCount > 4){
                  swState = 13;
                  index = 0;
                  loopCount=0;
                  ledState = LOW;
                }
            }   
        }
    }
    return;
}

void effect6(){                             //250mS On/Off Blink Effect 
     ledState = !ledState;                  //runs for 5 seconds in Auto mode
    for(int i = 0; i < LED_COUNT; i++){
        digitalWrite(leds[i], ledState);    //The only effect that doesn't use bitRead
    }
    if(mode){
          loopCount++;
            if(loopCount > 19){
                swState = 0;
                index = 0;
                loopCount=0;
                direction = UP;
                ledState = 0x0;
                }
        }
}

/* Tried using random like this......
 * "String ledString = String(random(0x8aa2, 0x10000), HEX);
 * ledState = ledString.toInt();"
 * 
 * It works but the LEDs are too sparse so I think it
 * may be better to use a pattern array built with eye catching 
 * patterns then randomize the arrays index value.
 */
