/*
 * filename: UMSB_NAV.cpp
 *
 * purpose: Library for use with GPS navigation
 *
 * use: Include "UMSB_NAV.hpp" and use the functions as described below
 *
 * version:
 * 		Version 0.2.0 - 3/8/20: restructured class, added destination function, and general fixes
 *		Version 0.1.0
 *
 * notes:
 *
 * contributors:
 *		Cobie Yung
 *		Malcolm Okaya
 */

#include "UMSB_NAV.hpp"

/* Constructor for creating new instances of class */
UMSB_NAV::UMSB_NAV() {

}

/* Take two coordinates and retuns a bearing in degrees */
double UMSB_NAV::bearing(double lat1, double lon1, double lat2, double lon2) {
	double dlon = (lon2 - lon1) * deg_2_rad;
	lat1 *= deg_2_rad;
	lat2 *= deg_2_rad;
	double y = sin(dlon) * cos(lat2);
	double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon);
	return atan2(y, x) / deg_2_rad;
}

/* Take a latitude and returns the earth's radius in meters at that point */
double earth_radius(double lat) {
	lat *= deg_2_rad;
	return sqrt(
		(pow(pow(EARTH_MAJOR_RADIUS, 2) * cos(lat), 2) + pow(pow(EARTH_MINOR_RADIUS, 2) * sin(lat), 2)) / 
		(pow(EARTH_MAJOR_RADIUS * cos(lat), 2) + pow(EARTH_MINOR_RADIUS * sin(lat), 2))
	);
}

/* Take two coordinates and returns the distance between them in meters */
double UMSB_NAV::distance(double lat1, double lon1, double lat2, double lon2) {
	double erad = earth_radius((lat1 + lat2) / 2.0);
	double dlon = (lon2 - lon1) * deg_2_rad;
	double dlat = (lat2 - lat1) * deg_2_rad;
	double a = pow(sin(dlat / 2.0), 2) + cos(lat1 * deg_2_rad) * cos(lat2 * deg_2_rad) * pow(sin(dlon / 2.0), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double d = erad * c;
	return d;
}
		
/* Take a pair of coordinates, a distance in meters, and a bearing, and calculates the resulting coordinates*/
void UMSB_NAV::destination(double lat, double lon, double distance, double bearing, double newLatLon[]) {
	double aDist = 1000*distance / earth_radius(lat);
	newLatLon[0] = (asin(sin(lat*deg_2_rad)*cos(aDist)+cos(lat*deg_2_rad)*sin(aDist)*cos(bearing*deg_2_rad))) / deg_2_rad;
	newLatLon[1] = (lon*deg_2_rad + atan2(sin(bearing*deg_2_rad)*sin(aDist)*cos(lat*deg_2_rad), cos(aDist) - sin(lat*deg_2_rad)*sin(newLatLon[0] / deg_2_rad))) / deg_2_rad;
}
