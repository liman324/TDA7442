// rcl-radio.ru liman324@yandex.ru 


#ifndef TDA7442_H
#define TDA7442_H

#define TDA7442_address 0x40

//Sub addresses
#define TDA7442_INPUT_ATT      0b00000000
#define TDA7442_SURR_OUT_EFF   0b00000001
#define TDA7442_REZ            0b00000010
#define TDA7442_BASS           0b00000011
#define TDA7442_TREBLE         0b00000100
#define TDA7442_ATT_L          0b00000101
#define TDA7442_ATT_R          0b00000110
#define TDA7442_INPUT_MULT     0b00001001

#include <Arduino.h>
class TDA7442
{
  public:
    TDA7442();
	void setInput_att(int in_att);  // int -63...0 = -31.5...0 dB step 0.5 dB
        void setSurr_sel(int surr, int out, int effect);/* int 0...2, int 0...1, int 0...15:
                                                           SIMULATED STEREO | MUSIC | OFF
                                                           VAR | FIX
                                                           EFFECT CONTROL -6...-21 dB  */
        void setRez(int rez);  // int 0...3 = 12, 14, 18, 37 kOm
        void setBass(int bass);   // int -7...7 = -14...+14 dB step 2 dB
        void setTreble(int treb); // int -7...7 = -14...+14 dB step 2 dB
        void setVol_L(int vol_l); // int -79...0 = -79...0 dB
        void setVol_R(int vol_r); // int -79...0 = -79...0 dB
        void setInput(int in);  // int 0...3 

  private:
	void writeWire(char a, char b);
};
	
#endif //TDA7442
