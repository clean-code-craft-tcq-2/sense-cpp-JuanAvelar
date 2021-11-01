#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& FloatingPointVector) {
    //Implement statistics here
    Stats stat_instance;
    if(!FloatingPointVector.empty()){
      //populate the first number of vector to get rid of initial value NaN.
      stat_instance = {FloatingPointVector.front(),FloatingPointVector.front(),FloatingPointVector.front()};
      for(auto&& FPV : FloatingPointVector){//iterate over all vector components
        stat_instance.average += FPV;//Add all values of vector
        if(FPV > stat_instance.max) stat_instance.max = FPV;//get maximum number in vector
        if(FPV < stat_instance.min) stat_instance.min = FPV;//get minimum number in vector
      }
      stat_instance.average = stat_instance.average / FloatingPointVector.size();
    }
    return stat_instance;//return by copy
}

StatsAlerter::StatsAlerter(const float Max_thresh, std::vector<IAlerter*> Alert_objects)
  :_private_max_threshold(Max_thresh), _private_alert_objects(Alert_objects){
  //Implementation not needed, initializer list used instead
}

void StatsAlerter::checkAndAlert(std::vector<float> localVector){
  //Implement alerts here
  auto computedStats = Statistics::ComputeStatistics(localVector);
  if(computedStats.max > _private_max_threshold){
    for(auto&& SingleAlert : _private_alert_objects){
      SingleAlert->please_alert();
    }
  }
}

void EmailAlert::please_alert(void){
  emailSent = true;
}
void LEDAlert::please_alert(void){
  ledGlows = true;
}
