
/*
 * Welcome to MultiWii.
 *
 * If you see this message, chances are you are using the Arduino IDE. That is ok.
 * To get the MultiWii program configured for your copter, you must switch to the tab named 'config.h'.
 * Maybe that tab is not visible in the list at the top, then you must use the drop down list at the right
 * to access that tab. In that tab you must enable your baord or sensors and optionally various features.
 * For more info go to http://www.multiwii.com/wiki/index.php?title=Main_Page
 *
 * Have fun, and do not forget MultiWii is made possible and brought to you under the GPL License.
 *
 */


// Tom's Change Log and Readme
// version number 2_4_1-3 is just my way of keeping track my changes...this is still MultiWii 2.4 just modified for the Runners
//
// Important: You will need to install the stk500v2 boot loader on the flight controller before you can load this code!
//
// for the most part where I have made changes I have inserted Walkera into the comments
// there are some debug statements that I left in the code but are commented out
// for the Basic Runners....go into def.h and comment out the GPS features
//
// Updated config.h
// Updated config.h to set UART to 2 for GPS
// define.h to update Mega types to remap radio channel pins 
//  negated the mag z value in config.h
// going back to add the walkera as a board in def.h
// mega board definition is still in use
// testing debug in config.h
// uncommented Motors stop on arm...means must use throttle hold and set trim to just short of quadcopter floating on bench
// moved pin 13 from LEDPIN to BUZZER PIN...this seems to work
// enabled TX deadband to test of motor speeds balance out
// Testing MPS on UART 3 in Serial.h/Serial.cpp
// updated MINCHECK and MAXCHECK for devo 7
// set Gyro LPF to 42Mhz in config.h
//
// 
//
//  Adding Right Wing and Left Wing LED Bars
//  Added definitions in def.h file

 //  MINTHROTTLE 1125 in config.h...might need to fine tune.

// Basic Runners may need GPS and Mag disabled as it causes I2C errors.  If the quadcopter flys erratic then they need to be disabled.


