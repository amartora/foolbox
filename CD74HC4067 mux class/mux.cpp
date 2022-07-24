#include <Arduino.h>
#include "mux.h"

Mux::Mux(uint8_t sig, uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, bool activeLow, uint8_t del){
  _sig = sig;
  _s0 = s0;
  _s1 = s1;
  _s2 = s2;
  _s3 = s3;
  _activeLow = activeLow;
  _del = del;

  pinMode(_s0, OUTPUT);
  pinMode(_s1, OUTPUT);
  pinMode(_s2, OUTPUT);
  pinMode(_s3, OUTPUT);
  pinMode(_sig, INPUT);
}

void Mux::ScanMux(){
 for(int i = 0; i < 16; i++){
   ChannelStates[i] = !_activeLow;
   SetMux(i);
   delay(_del);
   if(_activeLow == 1){
    ChannelStates[i] = !digitalRead(_sig);
   }
   else{
    ChannelStates[i] = digitalRead(_sig);
   }
 }
 
}

void Mux::SetMux(uint8_t state){
  digitalWrite(_s0, bitRead(state, 0));
  digitalWrite(_s1, bitRead(state, 1));
  digitalWrite(_s2, bitRead(state, 2));
  digitalWrite(_s3, bitRead(state, 3));
}
