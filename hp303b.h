#include "esphome.h"
#include "LOLIN_HP303B.h"

static const char *TAGhp = "hp303b";

using namespace esphome;

class HP303BSensor : public PollingComponent, public Sensor {
 public:
  LOLIN_HP303B hp;
  int32_t pressure;

  HP303BSensor() : PollingComponent(100000) { }

  void setup() override {
    ESP_LOGCONFIG(TAGhp, "Setting up HP303B...");
    hp.begin();
  }

  void dump_config() override {
    ESP_LOGCONFIG(TAGhp, "HP303B:");
    ESP_LOGCONFIG(TAGhp, "  Custom Sensor Active");
  }

  void update() override {
    hp.measurePressureOnce(pressure); // library returns value in in Pa, which equals 1/100 hPa
    float hPa = pressure / 100.0;

    ESP_LOGD(TAGhp, "Got pressure=%.1f hPa", hPa);
    publish_state(hPa); 
  }
};
