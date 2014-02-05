# Arduino Library for HG7881 (L9110) H-bridges

This is a wrapper around the Stepper library for use with HG7881 or L9110 H-bridges.

This is required because these chips have poor thermal management and thus overheat easily.

When using the regular Stepper library, they are not put into idle mode after stepping (and keep needlessly drawing huge amounts of current). I had two go up in smoke before I realised this.

Idle mode is when inputs A and B are either both HIGH or both LOW. This wrapper drives them both LOW after stepping.

