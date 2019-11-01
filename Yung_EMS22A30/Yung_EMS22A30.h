/*!
 * YUNG_EMS22A30.h
 * By Cobie Yung
 *
 * Headder file for using the EMS22A30 rotary encoder.
 *
 * Revision History:
 * 	Version 0.0.01 Initil Commit
 *
 * Notes:
 */

/** include files for ease of use **/ 
#include "Arduino.h"
#include <SPI.h>

class Yung_EMS22A30
{
public:
	int ss;
	Yung_EMS22A30(int ss = 0);
	void begin();
	uint16_t getAngle();
	uint16_t read();
	bool parityCheck(uint16_t data);
};