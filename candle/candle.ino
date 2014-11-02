/*
  This is a fake candle script running on Arduino Uno or an ATTiny 13 or the like.
  Two LEDs. One red, one yellow.

  Autor: Rene Schwietzke
  Date: 2014-11-02
  Version: 0.1
  License: MIT License
*/

// ***********************************************************************
// Constants
// ***********************************************************************
// ports
#include <math.h>

const int YELLOW = 0;
const int RED = 1;

void setup() {
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

// An example of a simple pseudo-random number generator is the
// Multiply-with-carry method invented by George Marsaglia.
// two initializers (not null)
unsigned long m_w = 1;
unsigned long m_z = 2;

/**
 * Random numbers without using the controller random function because
 * the tinys do not have random.
 *
 * Source: http://forum.arduino.cc/index.php/topic,52502.0.html
 */
unsigned long getRandom(int min, int max)
{
  m_z = 36969L * (m_z & 65535L) + (m_z >> 16);
  m_w = 18000L * (m_w & 65535L) + (m_w >> 16);
  long returnValue = (m_z << 16) + m_w;  /* 32-bit result */

  // map it to the desired range  
  return abs(returnValue % (max - min)) + min;
}

void loop()
{
  // unsigned long currentTimeMillis = millis();

  // make it flicker a little more once in a while, so it is less
  // nervous, but has its moments
  if (getRandom(0,19) == 1)
  {
    long y = getRandom(100,150);

    analogWrite(YELLOW, y);
    analogWrite(RED, max(50, y - 30));
  }
  else
  {
    // the normal flicker, less intense and red is not really bright to 
    // avoid the light being too red
    long y = getRandom(180,210);

    analogWrite(YELLOW, y);
    analogWrite(RED, y - 80);
    
  } 

  // just to see the flickering
  delay(getRandom(70, 120));
}
