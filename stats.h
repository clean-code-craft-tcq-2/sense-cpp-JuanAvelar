#include <vector>
#include "math.h"

struct Stats {
  float average = NAN;
  float max = NAN;
  float min = NAN;
};
struct IAlerter{
  virtual void please_alert(void) = 0;//pure virtual
};
struct EmailAlert: public IAlerter{
  bool emailSent = false;
  void please_alert(void) override;
};
struct LEDAlert: public IAlerter{
  bool ledGlows = false;
  void please_alert(void) override;
};
class StatsAlerter{
public:
  void checkAndAlert(std::vector<float> localVector);
  StatsAlerter(const float Max_thresh, std::vector<IAlerter*> Alert_objects);
private:
  std::vector<IAlerter*>  _private_alert_objects;
  const float             _private_max_threshold;
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& FloatingPointVector);
}
