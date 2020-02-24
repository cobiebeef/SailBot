/*!
 * filename: "UMSB_NAV.hpp"
 *
 * purpose: to provide basic navigation functions
 *
 * use: include this file and use the functions as described below
 *
 * version:
 *		Alpha 0.00.1
 *
 * notes:
 *
 * contributors:
 *		Cobie Yung
 */

#ifndef UMSB_NAV
#define UMSB_NAV

#include <math.h>

namespace UMSB_NAV {
	static constexpr double pi = 3.141592653589793,
		EARTH_MAJOR_RADIUS = 6378137.0, EARTH_MINOR_RADIUS = 6356752.3,
		deg_2_rad = pi / 180.0;

	/** takes two chordinates and returns the distance between them in meters **/
	double distance(double lat1, double long1, double lat2, double long2);

	/** takes two chordinates and retuns a bearing in degrees **/
	double bearing(double lat1, double long1, double lat2, double long2);
}

#endif 
