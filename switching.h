/*
 * This call creates the "timer" variable counters. 
 */
void change(){
    if(swState == 13){                          //Blink timer
        timer++;
            if(timer > 9){
                timer=0;
                effect6();
            }
    }else if(swState == 12){                    //Single LED Larson effect Timer
        timer++;
            if(timer > 1){
                timer=0;
                effect2();
            }
    }else if(swState >= 9 && swState < 12){     //Timer for Pattern 4
        timer++;
            if(timer > 2){
                timer=0;
                effect5();
            }
    }else if(swState >= 6 && swState < 9){     //Timer for Pattern 3
        timer++;
            if(timer > 2){
                timer=0;
                effect4();
            }
    }else if(swState >= 3 && swState < 6){     //Timer for Pattern 2
        timer++;
            if(timer > 1){
                timer=0;
                effect3();
            }
    }else if(swState < 3){                    //No timer needed for Pattern 1 
        effect1();                            //the 25mS duty cycle gives a good look
    }
    
}
