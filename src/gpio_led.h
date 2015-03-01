#ifndef GPIO_LED_H
#define GPIO_LED_H

#include "gpio_pin.h"
#include <chrono>
#include <string>

using namespace std;

class GPIOSimpleLed {
  public:
    GPIOSimpleLed(string power_pin_num);
    ~GPIOSimpleLed();

    bool blink(const chrono::duration<double, std::milli>& blink_duration, int num_blinks) const;
    bool on() const;
    bool off() const;
  private:
    GPIOSimpleLed();
    const GPIOPin power_pin;
};

#endif
