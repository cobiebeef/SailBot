/*
 * filename: UMSB_NAV.hpp
 *
 * purpose: Library for use with GPS navigation
 *
 * use: Include this file and use the functions as described below
 *
 * version:
 * 		Version 0.2.0 - 3/8/20: restructured class, added destination function, and general fixes
 *		Version 0.1.0 : Initial Commit
 *
 * notes:
 *
 * contributors:
 *		Cobie Yung
 *		Malcolm Okaya
 */

#ifndef UMSB_NAV_h
#define UMSB_NAV_h

#include <math.h>

/* Useful constants for calculations */
static constexpr double pi = 3.141592653589793,
						EARTH_MAJOR_RADIUS = 6378137.0, 
						EARTH_MINOR_RADIUS = 6356752.3,
						deg_2_rad = pi / 180.0;

class UMSB_NAV {
	public:

		/* Initialize the class */
		UMSB_NAV();

		/* Take two coordinates and returns the distance between them in meters */
		double distance(double lat1, double lon1, double lat2, double lon2);

		/* Take two coordinates and retuns a bearing in degrees */
		double bearing(double lat1, double lon1, double lat2, double lon2);
		
		/* Take a pair of coordinates, a distance in meters, and a bearing, and calculates the resulting coordinates*/
		void destination(double lat, double lon, double distance, double bearing, double newLatLon[]);
		
};

#endif