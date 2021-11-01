#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& FloatingPointVector) {
    //Implement statistics here
    Stats stat_instance;
    if(!FloatingPointVector.empty()){
      //populate the first number of vector to get rid of initial value NaN.
      stat_instance = {FloatingPointVector.front(),FloatingPointVector.front(),FloatingPointVector.front()};
      for(auto&& FPV : FloatingPointVector){
        stat_instance.average += FPV;//Add all values of vector
        if(FPV > stat_instance.max) stat_instance.max = FPV;//get maximum number in vector
        if(FPV < stat_instance.min) stat_instance.min = FPV;//get minimum number in vector
      }
      stat_instance.average = stat_instance.average / FloatingPointVector.size();
    }

    return stat_instance;//return by copy
}

void StatsAlerter::checkAndAlert(std::vector<float> localVector){
  //Implement
}

StatsAlerter::StatsAlerter(const float Max_thresh, std::vector<IAlerter*> Alert_objects){
  //Implement
}
