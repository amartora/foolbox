#ifndef mux_h
#define mux_h
#include <Arduino.h>

class Mux{
  public: 
  Mux(uint8_t sig, uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, bool activeLow = true, uint8_t del = 1);
  void SetMux(uint8_t state);
  void ScanMux();
  bool ChannelStates[16];

  private:
  uint8_t _sig;
  uint8_t _s0;
  uint8_t _s1;
  uint8_t _s2;
  uint8_t _s3;
  bool _activeLow;
  uint8_t _del;
};

#endif
