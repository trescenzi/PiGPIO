#include "gpio.h"
#include "gpio_led.h"
#include <chrono>
#include <string>
#include <thread>

using namespace std;

GPIOSimpleLed::GPIOSimpleLed(string power_pin_num) : power_pin(power_pin_num) {}
GPIOSimpleLed::~GPIOSimpleLed() {}

bool GPIOSimpleLed::on() const {
  return power_pin.set_value(Value::ONE);
}

bool GPIOSimpleLed::off() const {
  return power_pin.set_value(Value::ZERO);
}

bool GPIOSimpleLed::blink(const chrono::duration<double, std::milli>& blink_duration, int num_blinks) const {
  for(int i=0; i<num_blinks; ++i) {
    if(!on()) {
      return false;
    }
    this_thread::sleep_for(blink_duration);
    if(!off()) {
      return false;
    }
    this_thread::sleep_for(blink_duration);
  }
  return true;
}


