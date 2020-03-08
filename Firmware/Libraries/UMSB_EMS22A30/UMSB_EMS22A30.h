/*
 * filename: UMSB_EMS22A30.h
 *
 * purpose: Library for the EMS22A30 rotary encoder
 *
 * use: Include this file and use the functions as described below
 *
 * version:
 * 		Version 0.1.1: Renamed file and namespaces
 *      Version 0.1.0: Initial Commit
 *
 * notes:
 *
 * contributors:
 *      Cobie Yung
 * 		Malcolm Okaya
 */

#include "Arduino.h"
#include <SPI.h>

class UMSB_EMS22A30 {
public:

	/* pin being used for ss with SPI */
	int ss;

	/* Initializes the class with a default ss value */
	UMSB_EMS22A30(int ss = 0);

	/* Start everything necessary for rotary encoder operation */
	void begin();

	/* Return the current angle */
	uint16_t getAngle();

	/* Read data from the sensor */
	uint16_t read();

	/* Check for errors in the data */
	bool parityCheck(uint16_t data);
};
