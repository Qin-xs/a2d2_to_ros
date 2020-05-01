# FAQ for interpreting the A2D2 data set

This document contains a set of questions that might be unclear after examining readme file data at this page:

https://www.a2d2.audi/a2d2/en/download.html

And the technical description of the data set at this page:

https://arxiv.org/abs/2004.06320

Answers, where available, are given directly below the questions. If a question has no answer below it, then it remains an open question.

## General

1. Are all timestamps Unix Epoch time with microsecond units?
1. What is the precision of real-valued data (e.g., 32-bit, 64-bit, etc.)?

## Frame conventions

1. For the reference frame ***g*** (described in [Section 3.1](https://arxiv.org/pdf/2004.06320.pdf)):
    1. Is the position of the origin fixed with respect to the vehicle?
    1. Is the z-axis is aligned to the gravity vector?
    1. Is the x-axis is aligned to vehicle heading?

## Sensor fusion bus signal data

1. What are the `distance_pulse_*` fields and what do the values represent?
1. What are the `latitude_direction` and `longitude_direction` fields and what do the values represent?
1. What are the conventions for the `steering_angle_calculated` values (i.e., what are min and max, and what is centered)?
1. What are the conventions for the `*_sign` fields (e.g., does it follow [std::signbit](https://www.cplusplus.com/reference/cmath/signbit/) conventions)?
1. Is `vehicle_speed` allowed to be negative? If not, how is driving in reverse indicated, or is it guaranteed that the vehicle never drives in reverse?
1. What is the convention for `accelerator_pedal` percent values (i.e., is 0 or 100 fully depressed)?

## Semantic segmentation bus signal data

1. What is the `driving_direction` field and what do the values represent?
1. What do the values for the `gear` field represent?
1. Are `steering_angle` and `steering_angle_sign` ground truth with respect to `steering_angle_calculated` and `steering_angle_calculated_sign`?