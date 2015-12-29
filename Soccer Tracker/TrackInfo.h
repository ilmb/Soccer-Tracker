#pragma once

#include <cv.h>
#include <opencv2\opencv.hpp>
#include <vector>

namespace st {

//*************************************************************************************************
// ----- This structure wrappers all the information that is sent from
// ----- camera-threads to the handler-thread
//*************************************************************************************************
struct TrackInfo {

	//_____________________________________________________________________________________________
	public:

		/********************************************************************************
										Ball Information
		*********************************************************************************/

		int ballCandID;
		Rect rect;
		Point coord, predCoord, GTcoord; // measured coordinate, predicted coordinate, ground truth coordinate
		bool allowTracking;
		bool current;

		vector<pair<Point, Point>> results;


		//=========================================================================================
		void set (int ballID = -1, Rect rect = Rect(), Point coord = Point(-1,-1), Point predCoord = Point(), Point GTcoord = Point(-1, -1), vector<pair<Point,Point>> results = vector<pair<Point,Point>>()) {
			this->ballCandID = ballID;
			this->coord = coord;
			this->predCoord = predCoord;
			this->rect = rect;

			this->GTcoord = GTcoord;
			this->results = results;
		}

		//=========================================================================================
		TrackInfo(void) {}

		//=========================================================================================
		~TrackInfo(void) {}
};

}