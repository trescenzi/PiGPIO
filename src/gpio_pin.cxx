#include "gpio_pin.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const string GPIOPin::gpio_path = "/sys/class/gpio/";
GPIOPin::GPIOPin(const string& pin) : pin_num(pin) {
  export_pin();
}

GPIOPin::~GPIOPin() {
  set_value(Value::ZERO);
  unexport_pin();
}

bool GPIOPin::export_pin() const {
  const string export_path = gpio_path + "export";
  ofstream export_stream(export_path.c_str());
  if(!export_stream.is_open()) {
    return false;
  }
  export_stream << pin_num;
  export_stream.close();
  return true;
}
  
bool GPIOPin::unexport_pin() const {
  const string unexport_path = gpio_path + "unexport";
  ofstream unexport_stream(unexport_path.c_str());
  if(!unexport_stream.is_open()) {
    return false;
  }
  unexport_stream << pin_num;
  unexport_stream.close();
  return true;
}

bool GPIOPin::set_direction(Direction d) const { 
  const string direction_path = gpio_path + "gpio" + pin_num + "/direction";
  string direction;
  if(d == Direction::IN) {
    direction = "in";
  } else if(d == Direction::OUT) {
    direction = "out";
  }

  ofstream direction_stream(direction_path.c_str());
  if(!direction_stream.is_open()) {
    return false;
  }
  direction_stream << direction;
  direction_stream.close();
  return true;
}

bool GPIOPin::set_value(Value v) const {
  const string value_path = gpio_path + "gpio" + pin_num + "/value";
  string value;
  if(v == Value::ZERO) {
    value = "0";
  } else if(v == Value::ONE) {
    value = "1";
  }

  ofstream value_stream(value_path.c_str());
  if(!value_stream.is_open()) {
    return false;
  }
  value_stream << value;
  value_stream.close();
  return true;
}

bool GPIOPin::get_value(string& v) const {
  const string value_path = gpio_path + "gpio" + pin_num + "/value";
  ifstream value_stream(value_path.c_str());
  if(!value_stream.is_open())
   return false;
  v.clear();
  value_stream >> v;
  return true;
}

const string& GPIOPin::get_pin_num() const {
  return pin_num;
}
