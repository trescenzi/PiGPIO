#ifndef GPIO_PIN_H
#define GPIO_PIN_H
#include <string>
using namespace std;

enum class Direction { IN, OUT };
enum class Value     { ZERO, ONE};

class GPIOPin {
public:
  GPIOPin(const string& pin);
  ~GPIOPin();

  bool export_pin() const;
  bool unexport_pin() const;
  bool set_direction(Direction d) const;
  bool set_value(Value v) const;
  const string& get_pin_num() const;
  bool get_value(string& v) const;

private:
  GPIOPin();
  const string pin_num;
  static const string gpio_path;
};

#endif
