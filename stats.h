#include <vector>

struct Stats {
  float average;
  float max;
  float min;
};
struct IAlerter{
  //leave empty
};
struct EmailAlert: public IAlerter{
  bool emailSent = 0;
};
struct LEDAlert: public IAlerter{
  bool ledGlows = 0;
};
class StatsAlerter{
public:
  void checkAndAlert(std::vector<float> localVector);
  StatsAlerter(const float Max_thresh, std::vector<IAlerter*> Alert_objects);
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& FloatingPointVector);
}
