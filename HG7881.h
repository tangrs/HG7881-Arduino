/*
  HG7881.h - Library for controlling stepper motors on HG7881 (L9110) H-bridges

  Inherits from Stepper library.

  Created by Daniel Tang <tangrs@tangrs.id.au>
  Released into the public domain.
*/
#ifndef HG7881_h
#define HG7881_h

#ifndef Stepper_h
  #warn Include the Stepper library header
#endif

class HG7881 : public Stepper
{
  public:
    HG7881(int steps, int pin1, int pin2, int pin3, int pin4);
    HG7881(int steps, int pin1, int pin2);

    void step(int steps);
  private:
    // some required class variables are marked private in the Stepper class
    // keep track of them separately
    int pin1, pin2, pin3, pin4;
    int pin_count;
};

#endif
