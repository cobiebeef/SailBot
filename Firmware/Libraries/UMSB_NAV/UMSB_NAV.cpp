/*!
 * filename: "UMSB_NAV.cpp"
 *
 * purpose: to provide basic navigation functions
 *
 * use: include "UMSB_NAV.hpp" and use the functions as described below
 *
 * version:
 *		Alpha 0.00.1
 *
 * notes:
 *		November 12, 2019: need to create a function that takes in a bearing,
 *			a distance and, an initial cordinate and returns the final cordinate
 *
 * contributors:
 *		Cobie Yung
 */
#include "UMSB_NAV.hpp"

namespace UMSB_NAV {
	/** takes two chordinates and retuns a bearing in degrees **/
	double bearing(double lat1, double long1, double lat2, double long2) {
		double dlong = (long2 - long1) * deg_2_rad;
		lat1 *= deg_2_rad;
		lat2 *= deg_2_rad;
		double y = sin(dlong) * cos(lat2);
		double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlong);
		return atan2(y, x) / deg_2_rad;
	}

	/** takes a latitude and returns the earth's radius in meters at that point **/
	double earth_radius(double lat) {
		lat *= deg_2_rad;
		return sqrt(
			(pow(pow(EARTH_MAJOR_RADIUS, 2) * cos(lat), 2) + pow(pow(EARTH_MINOR_RADIUS, 2) * sin(lat), 2)) / 
			(pow(EARTH_MAJOR_RADIUS * cos(lat), 2) + pow(EARTH_MINOR_RADIUS * sin(lat), 2))
		);
	}

	/** takes two chordinates and returns the distance between them in meters **/
	double distance(double lat1, double long1, double lat2, double long2) {
		double erad = earth_radius((lat1 + lat2) / 2.0);
		double dlong = (long2 - long1) * deg_2_rad;
		double dlat = (lat2 - lat1) * deg_2_rad;
		double a = pow(sin(dlat / 2.0), 2) + cos(lat1 * deg_2_rad) * cos(lat2 * deg_2_rad) * pow(sin(dlong / 2.0), 2);
		double c = 2 * atan2(sqrt(a), sqrt(1 - a));
		double d = erad * c;

		return d;
	}
}
