/*
 * filename: UMSB_EMS22A30.cpp
 *
 * purpose: Library for using the EMS22A30 rotary encoder
 *
 * use: Include "UMSB_EMS22A30.hpp" and use the functions as described below
 *
 * version:
 *	Version 0.1.1:　Renamed Files and Namespaces
 *      Version 0.1.0:　Initia--l Commit
 *
 * notes:
 *
 * contributors:
 *      Cobie Yung
 * 	Malcolm Okaya
 */

#include "Arduino.h"
#include <SPI.h>
#include "UMSB_EMS22A30.h"

/* Constructor for creating new instances of class */
UMSB_EMS22A30::UMSB_EMS22A30(int pin) {
	ss = pin;
}

/* Read the data from the rotatry encoder */
uint16_t UMSB_EMS22A30::read() {
	digitalWrite(ss, LOW);
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));
	uint16_t data = SPI.transfer(0x00);
	data = data << 8;
	data |= SPI.transfer(0x00);
	digitalWrite(ss, HIGH);
	return data; 
}

/* Get the angle from the EMS22A30 */
uint16_t UMSB_EMS22A30::getAngle() {
	uint16_t angle = 0;
	uint16_t data = read();
	
	/* Check for even parity */
	if(!parityCheck(data)) {
		/* Grab the first 10 bits */
		angle = data >> 6;
	}
	
	return angle;
}

/* Check for parity
 * Return 1 for odd parity, return 0 for even parity */
bool UMSB_EMS22A30::parityCheck(uint16_t data) {
	bool parity = 0; 
	
    while(data) {
        parity = !parity; 
        data = data & (data - 1); 
    }
	
    return parity;
}

/* Start up the SPI commuinication protocol */
void UMSB_EMS22A30::begin() {
	SPI.begin();
	pinMode(ss, OUTPUT);
	digitalWrite(ss, HIGH);
}
