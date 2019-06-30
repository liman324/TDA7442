#include <Wire.h>
#include <TDA7442.h>
  TDA7442 tda;
  
void setup(){ 
  Serial.begin(9600);Wire.begin();
  audio();
}

void loop(){}

void audio(){
 tda.setInput_att(0);  // int -63...0 = -31.5...0 dB step 0.5 dB
 tda.setSurr_sel(0, 0, 0);/* int 0...2, int 0...1, int 0...15:
                                                           SIMULATED STEREO | MUSIC | OFF
                                                           VAR | FIX
                                                           EFFECT CONTROL -6...-21 dB  */
 tda.setRez(0);  // int 0...3 = 12, 14, 18, 37 kOm
 tda.setBass(0);   // int -7...7 = -14...+14 dB step 2 dB
 tda.setTreble(0); // int -7...7 = -14...+14 dB step 2 dB
 tda.setVol_L(-20); // int -79...0 = -79...0 dB
 tda.setVol_R(-20); // int -79...0 = -79...0 dB
 tda.setInput(0);
 }
