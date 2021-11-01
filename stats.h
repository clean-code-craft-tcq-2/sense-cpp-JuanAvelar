#include <vector>
#include "math.h"

struct Stats {
  float average = NAN;
  float max = NAN;
  float min = NAN;
};
struct IAlerter{
  //leave empty
};
struct EmailAlert: public IAlerter{
  bool emailSent = false;
};
struct LEDAlert: public IAlerter{
  bool ledGlows = false;
};
class StatsAlerter{
public:
  void checkAndAlert(std::vector<float> localVector);
  StatsAlerter(const float Max_thresh, std::vector<IAlerter*> Alert_objects);
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& FloatingPointVector);
}
