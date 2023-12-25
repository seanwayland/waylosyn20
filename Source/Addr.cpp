/*
  ==============================================================================

    Addr.cpp
    Created: 24 Dec 2023 7:31:48pm
    Author:  sean wayland

  ==============================================================================
*/

#include "Addr.h"

Addr::Addr() {}

Addr::~Addr() {}

void Addr::setup(double sampleRate) {
    vol = 0.0;
    state = 0;
    sample_rate = sampleRate;

}

void Addr::noteOn(){
    
    vol = 0.0;
    state = 1;
}

void Addr::noteOff(){
    state = 4;
}

void Addr::reset() {
    vol = 0.0;
    state = 0.0;
}

  void Addr::setFallRateChangeVolume(double vol){
    fall_rate_change_volume = vol;
  }
  void Addr::SetFallRate1Secs(double secs){
    fall_rate_1_secs = secs;
  }
  void Addr::SetFallRate2Secs(double secs){
    fall_rate_2_secs = secs;
  }
  void Addr::SetAttackRateSecs(double secs){
    attack_rate_secs = secs;
  }
  void Addr::SetReleaseRateSecs(double secs){
    release_rate_secs = secs;
  }
  void Addr::SetAttack_rate_secs(double secs){
    attack_rate_secs = secs;
  }
  void Addr::setSampleRate(double sampleRate){
    sample_rate = sampleRate;
  }
  void Addr::setRateScale(double rateScale){
    rate_scale = rateScale;
  }
  void Addr::setState(int newState){
    state = newState;
  }
  void Addr::setPosition(double newPosition){
    position = newPosition;
  }
  void Addr::killVol(){
      vol = 0.0;
}

void Addr::setRelease(){
    state = 4;
}
  float Addr::process(){

               switch(state){
                case 1:
                       if ( vol < 0.0){
                           vol = 0.0;
                           return (vol);
                       }
                    vol = vol + attack_rate_secs/(float(sample_rate)*rate_scale);
                    if (vol >= max_volume){
                        state = 2;
                        return(vol);
                        }
                    else{
                        return(vol);}

                case 2:
                    vol = vol - fall_rate_1_secs/(float(sample_rate)*rate_scale);
                    if (vol <= fall_rate_change_volume){
                        state = 3;
                        return(vol);}
                        
                    else{
                        return(vol);}
                case 3:
                    vol = vol - fall_rate_2_secs/(float(sample_rate)*rate_scale);
                    if (vol <= 0){
                        state = 0;
                        vol = 0.0;
                        return(vol);}
                        
                    else{
                        return(vol);}
                case 4:
                    if (vol > 0.0){
                           vol = vol - release_rate_secs/(float(sample_rate)*rate_scale);}
                    
                    if (vol <= 0){
                        state = 0;
                        vol = 0.0;
                        return(vol); }   
                    else{
                        return(vol); }
                       
                case 0:
                       vol = 0.0;
                        return(0.0);
               }

  }


