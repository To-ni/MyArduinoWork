/*
  This is a fake candle script running on Arduino Uno or an ATTiny 13 or the like.
  It just runs against a single LED for now.

  Autor: Rene Schwietzke
  Date: 2014-09-15
  Version: 0.1
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
  unsigned long currentTimeMillis = millis();

  /*if (currentTimeMillis - lastSensorReadTime > 1000) 
  {
  }
    *//*Serial.print(lastSensorReadTime); Serial.print(" ");
    Serial.print(light); Serial.print(" ");
    Serial.print(smallestLight); Serial.print(" ");
    Serial.print(largestLight); Serial.print(" ");
    Serial.println(mappedLight);*/

  //}

  if (getRandom(0,19) == 1)
  {
    long y = getRandom(100,150);

    analogWrite(YELLOW, y);
    analogWrite(RED, max(50, y - 30));
  }
  else
  {
    long y = getRandom(180,210);

    analogWrite(YELLOW, y);
    analogWrite(RED, y - 80);
    
  } 
  delay(getRandom(70, 120));
}
