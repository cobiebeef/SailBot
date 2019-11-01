/*!
 * @file Yung_EMS22A30.cpp
 *
 *	This is a library for the EMS22A30 rotary encoder
 *
 * Revision History:
 * 	Version 0.0.01 Initil Commit
 *
 * Notes:
 */

// include files for ease of use
#include "Arduino.h"

#include <SPI.h>

#include "Yung_EMS22A30.h"

/*!
*/
Yung_EMS22A30::Yung_EMS22A30(int pin) 
{
	ss = pin;
}

/*!
*/
uint16_t Yung_EMS22A30::read()
{
	digitalWrite(ss, LOW);
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));
	uint16_t data = SPI.transfer(0x00);
	data = data << 8;
	data |= SPI.transfer(0x00);
	digitalWrite(ss, HIGH);
	
	return data; 
}

/*!
*/
uint16_t Yung_EMS22A30::getAngle()
{
	uint16_t angle = 0;
	uint16_t data = read();
	
	if(!parityCheck(data))
	{
		angle = data >> 6;
	}
	
	return angle;
}

/*!
*/
bool Yung_EMS22A30::parityCheck(uint16_t data)
{
	bool parity = 0; 
	
    while(data) 
    {
        parity = !parity; 
        data = data & (data - 1); 
    }
	
    return parity;
}

/*!
*/
void Yung_EMS22A30::begin()
{
	SPI.begin();
	pinMode(ss, OUTPUT);
	digitalWrite(ss, HIGH);
}
