/*
  ==============================================================================

    Addr.h
    Created: 25 Dec 2023 5:31:22pm
    Author:  sean wayland

  ==============================================================================
*/

#pragma once
/*
  ==============================================================================

    Addr.h
    Created: 24 Dec 2023 7:31:39pm
    Author:  sean wayland

  ==============================================================================
*/

#pragma once

#include "Addr.h"

class Addr
{
public:
  Addr();
  ~Addr();
  void setup(double sampleRate);
  void setFallRateChangeVolume(double vol);
  void SetFallRate1Secs(double secs);
  void SetFallRate2Secs(double secs);
  void SetAttackRateSecs(double secs);
  void SetReleaseRateSecs(double secs);
  void SetAttack_rate_secs(double secs);
  void setSampleRate(double sampleRate);
  void setRateScale(double rateScale);
  void setState(int newState);
  void setPosition(double newPosition);
  void reset();
  void killVol();
  void setRelease();
    void noteOn();
    void noteOff();
  float process();


private:
  double sample_rate = 96000;
  double vol = 0.0;
  double position = 0;
  double max_volume = 1.0;

  double fall_rate_change_volume = .8;
  double attack_rate_secs = 5;
  double fall_rate_1_secs = 15;
  double fall_rate_2_secs = 0.2;
  double release_rate_secs = 1.0;
  double rate_scale = 1.0; // 1 is one sec , 2 is 2 secs
  int state = 1;           // 0 is idle , 1 is attack, 2 is decay one , 3 is decay 2 , 4 is release
};
