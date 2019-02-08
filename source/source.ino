// Ivan Pavao Lozancic 02/05/2019
// RasHAWK Arduino source code

//Pin defintions
//To RPi
#define DF_MODE_PIN 2
#define ANT_SEL0    3
#define ANT_SEL1    4
#define ANT_SEL2    5
//RF Switch
#define A0          20
#define A1          21
#define SWITCH_FREQ 500 //In Hz

//SWITCHING PINS STATES
/*******************************
 * [A0]     [A1]    = [ANTENNA]
 * [0]      [0]     = [1] 
 * [0]      [1]     = [2]
 * [1]      [1]     = [3]
 * [1]      [0]     = [4]
 * ****************************/
uint8_t combinationsToSwitch[4][2] =    {0, 0}, //ANTENNA_1 = 0
                                        {0, 1}, //ANTENNA_2 = 1
                                        {1, 1}, //ANTENNA_3 = 2
                                        {1, 0}; //ANTENNA_4 = 3

uint8_t combinationsToRpi[4][3] =       {0, 0, 1},  //ANTENNA 1 -> 2
                                        {0, 1, 0},  //ANTENNA 2 -> 3        
                                        {0, 1, 1},  //ANTENNA 3 -> 4        
                                        {1, 1, 1},  //ANTENNA 4 -> 1                    

uint32_t switchingPeriod = 1000000 / SWITCH_FREQ;   // 0 - > 1 - > 2 - > 3 - > 0
                                                    // |-----------------------|
                                                    //          PERIOD[us]
uint32_t delayTime = switchingPeriod / 4; //[microseconds]

void antennaSwitching(){

    uint8_t COUNTER;

    //Start switching process with defined frequency
    for(COUNTER = 0; COUNTER < 4; COUNTER++){

        digitalWrite(A0, combinationsToSwitch[COUNTER][1]);
        digitalWrite(A1, combinationsToSwitch[COUNTER][0]);

        poolRpi(COUNTER);

        digitalWrite(ANT_SEL0, combinationsToRpi[COUNTER][2]);
        digitalWrite(ANT_SEL0, combinationsToRpi[COUNTER][1]);
        digitalWrite(ANT_SEL0, combinationsToRpi[COUNTER][0]);

        delayMicroseconds(delayTime);
    }
}

void hardwareInit(){

    //RPi pins
    pinMode(DF_MODE_PIN, INPUT);
    pinMode(ANT_SEL0, OUTPUT);
    pinMode(ANT_SEl1, OUTPUT);
    pinMode(ANT_SEL2, OUTPUT);

    //RF Switch
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
}

void setup(){
    hardwareInit();
}

void loop(){
    while(DF_MODE_PIN){
        antennaSwitching();
    }
}