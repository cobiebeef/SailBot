/*
 * filename: UMSB_EMS22A30.h
 *
 * purpose: library for the EMS22A30 rotary encoder
 *
 * use: include this file and use the functions as described below
 *
 * version:
 *     version 0.1.1: Renamed file and namespaces
 *     version 0.1.0: Initial Commit
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

	/* initializes the class with a default ss value */
	UMSB_EMS22A30(int ss = 0);

	/* start everything necessary for rotary encoder operation */
	void begin();

	/* return the current angle */
	uint16_t getAngle();

	/* read data from the sensor */
	uint16_t read();

	/* check for errors in the data */
	bool parityCheck(uint16_t data);
};
