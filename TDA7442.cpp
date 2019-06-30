#include <Arduino.h>
#include <Wire.h>
#include "TDA7442.h"

TDA7442::TDA7442(){
	Wire.begin();
}

void TDA7442::setInput_att(int in_att){
          in_att = 0b01000000 + in_att;
      writeWire(TDA7442_INPUT_ATT, in_att);
}

void TDA7442::setSurr_sel(int surr, int out, int effect){
      switch(surr){
         case 0: surr = 0b00000000;break;
         case 1: surr = 0b00000001;break; 
         case 2: surr = 0b00000010;break;
}
      switch(out){
         case 0: out = 0b00000000;break;
         case 1: out = 0b00000100;break; 
}
      switch(effect){
         case 0:  effect = 0b00000000;break;
         case 1:  effect = 0b00001000;break; 
         case 2:  effect = 0b00010000;break; 
         case 3:  effect = 0b00011000;break; 
         case 4:  effect = 0b00100000;break; 
         case 5:  effect = 0b00101000;break; 
         case 6:  effect = 0b00110000;break; 
         case 7:  effect = 0b00111000;break; 
         case 8:  effect = 0b01000000;break; 
         case 9:  effect = 0b01001000;break; 
         case 10: effect = 0b01010000;break; 
         case 11: effect = 0b01011000;break; 
         case 12: effect = 0b01100000;break; 
         case 13: effect = 0b01101000;break; 
         case 14: effect = 0b01110000;break; 
         case 15: effect = 0b01111000;break; 
}
         int sum = surr + out + effect;
      writeWire(TDA7442_SURR_OUT_EFF, sum);
}

void TDA7442::setRez(int rez){
      switch(rez){
         case 0: rez = 0b00000000;break;
         case 1: rez = 0b00000001;break; 
         case 2: rez = 0b00000010;break;
         case 3: rez = 0b00000011;break;
}
     writeWire(TDA7442_REZ, rez);
}

void TDA7442::setBass(int bass){
      switch(bass){
         case -7: bass = 0b00010000;break;
         case -6: bass = 0b00010001;break; 
         case -5: bass = 0b00010010;break;
         case -4: bass = 0b00010011;break;
         case -3: bass = 0b00010100;break;
         case -2: bass = 0b00010101;break;
         case -1: bass = 0b00010110;break;

         case 0:  bass = 0b00011111;break;

         case 1:  bass = 0b00011110;break;
         case 2:  bass = 0b00011101;break;
         case 3:  bass = 0b00011100;break;
         case 4:  bass = 0b00011011;break;
         case 5:  bass = 0b00011010;break;
         case 6:  bass = 0b00011001;break;
         case 7:  bass = 0b00011000;break;
}
     writeWire(TDA7442_BASS, bass);
}

void TDA7442::setTreble(int treb){
      switch(treb){
         case -7: treb = 0b00001110;break;
         case -6: treb = 0b00011110;break; 
         case -5: treb = 0b00101110;break;
         case -4: treb = 0b00111110;break;
         case -3: treb = 0b01001110;break;
         case -2: treb = 0b01011110;break;
         case -1: treb = 0b01101110;break;

         case 0:  treb = 0b11111110;break;

         case 1:  treb = 0b11101110;break;
         case 2:  treb = 0b11011110;break;
         case 3:  treb = 0b11001110;break;
         case 4:  treb = 0b10111110;break;
         case 5:  treb = 0b10101110;break;
         case 6:  treb = 0b10011110;break;
         case 7:  treb = 0b10001110;break;
}
     writeWire(TDA7442_TREBLE, treb);
}

void TDA7442::setVol_L(int vol_l){     
      writeWire(TDA7442_ATT_L, vol_l);
}

void TDA7442::setVol_R(int vol_r){     
      writeWire(TDA7442_ATT_R, vol_r);
}

void TDA7442::setInput(int in){
      switch(in){
         case 0: in = 0b00000000;break;
         case 1: in = 0b00000010;break; 
         case 2: in = 0b00000100;break;
         case 3: in = 0b00000110;break;
}
     writeWire(TDA7442_INPUT_MULT, in);
}

void TDA7442::writeWire(char a, char b){
  Wire.beginTransmission(TDA7442_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
