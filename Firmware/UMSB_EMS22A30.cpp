/*!
 * @file UMSB_EMS22A30.cpp
 *
 * This is a library for the EMS22A30 rotary encoder
 *
 * Revision History:
 *     Version 0.0.01 Initil Commit
 *
 * Notes:
 */

#include "Arduino.h"

#include <SPI.h>

#include "UMSB_EMS22A30.h"

/*!
 * Initializarion
 */
UMSB_EMS22A30::UMSB_EMS22A30(int pin) 
{
	ss = pin;
}

/*!
 * Read the data from the rotatry encoder
 */
uint16_t UMSB_EMS22A30::read()
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
 * Get the angle from the EMS22A30
 */
uint16_t UMSB_EMS22A30::getAngle()
{
	uint16_t angle = 0;
	uint16_t data = read();
	
	/** Check for even parity **/
	if(!parityCheck(data))
	{
		/** Grab the first 10 bits **/
		angle = data >> 6;
	}
	
	return angle;
}

/*!
 * Check for parity
 * Returns 1 for odd parity, returns 0 for even parity
 */
bool UMSB_EMS22A30::parityCheck(uint16_t data)
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
 * Start up the SPI commuinication protocall
 */
void UMSB_EMS22A30::begin()
{
	SPI.begin();
	pinMode(ss, OUTPUT);
	digitalWrite(ss, HIGH);
}
