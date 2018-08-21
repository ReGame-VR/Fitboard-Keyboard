# Fitboard Keyboard

Proximity sensors, which operated on sonar detection, were determined to be not viable. This is due to a significant delay between readings--approximately 2.7s for all of the four sensors to collect data. The delay is a result of a unique signal needing to be sent and read for each of the four sensors. 

This repository contains the Arduino code for Fitboard. Emulates a 4 button keyboard. Can choose 'WASD' or arrow keys as the 4 buttons. 

Repository also includes an arduino sketch, Proximity_Sensors.io, which demonstrates how four sonar sensors can be used as four buttons with an arduino uno.
