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
#define A0          21

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

}