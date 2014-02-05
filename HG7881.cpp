/*
  HG7881.cpp - Library for controlling stepper motors on HG7881 (L9110) H-bridges

  Inherits from Stepper library

  Created by Daniel Tang <tangrs@tangrs.id.au>
  Released into the public domain.
*/
#include <Arduino.h>
#include <Stepper.h>

#include "HG7881.h"

HG7881::HG7881(int steps, int pin1, int pin2)
: Stepper(steps, pin1, pin2)
{
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->pin_count = 2;
}

HG7881::HG7881(int steps, int pin1, int pin2, int pin3, int pin4)
: Stepper(steps, pin1, pin2, pin3, pin4)
{
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->pin3 = pin3;
  this->pin4 = pin4;
  this->pin_count = 4;
}

void HG7881::step(int steps)
{
  Stepper::step(steps);

  // put controller into idle
  // this will cause shoot-through on normal H-bridges but the HG7881
  // needs this to not drive the motor unnecessarily
  digitalWrite(this->pin1, LOW);
  digitalWrite(this->pin2, LOW);

  if (this->pin_count == 4) {
    digitalWrite(this->pin3, LOW);
    digitalWrite(this->pin4, LOW);
  }
}
