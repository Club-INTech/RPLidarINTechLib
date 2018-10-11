#include "RPLidar.hpp"
#include <unistd.h>
#include <cmath>

using namespace data_wrappers;



int main(int argc, char** argv){
	/* ************************************
	*    			SETUP PROGRAM  				 *
	**************************************/


	/* ************************************
	*    SETUP LIDAR & CHECK STATUS  *
	**************************************/
	RPLidar lidar(argv[argc-1]); //Connects to lidar,

	lidar.print_status(); // Print model, health, sampling rates

	lidar.stop_motor(); //Stop motor if already running

	/* ************************************
	 *                   START SCAN                    *
	 **************************************/
	lidar.start_motor();
	lidar.start_express_scan();
//	lidar.start_scan();

	/* ************************************
 	*                   TEST MAIN LOOP             *
 	**************************************/
	lidar.process_express_scans();
//	lidar.process_regular_scans();


	/*
	 * STOP ALL
	 */
	printf("Stopping LiDAR\n");
	lidar.stop_scan();
	lidar.stop_motor();
	return 0;
}