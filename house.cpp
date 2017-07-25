#include <stdlib.h>
#include "house.hpp"


using namespace std;
vector<POINT2D> get_roof_points(HOUSE &house) {
    vector<POINT2D> points;
    points.resize(3);
    
    //top of roof
    points[0].x = house.center_x;
    points[0].y = house.center_y + (house.body_height / 2) + house.roof_height;
    //right edge
    points[1].x = points[0].x + (house.roof_width / 2);
    points[1].y = points[0].y - house.roof_height;
    //left edge of roof
    points[2].x = points[0].x - (house.roof_width / 2);
    points[2].y = points[0].y - house.roof_height;
    return points;
}

vector<POINT2D> get_house_body_points(HOUSE &house) {
    vector<POINT2D> points;
    points.resize(4);
    #define half_height house.body_height/2
    #define half_width house.body_width/2
    #define mid_x house.center_x
    #define mid_y house.center_y
    //bottom left
    points[0].x = mid_x - half_width;
    points[0].y = mid_y - half_height;
    //top left
    points[1].x = mid_x - half_width;
    points[1].y = mid_y + half_height;
    //top right
    points[2].x = mid_x + half_width;
    points[2].y = mid_y + half_height;
    //bottom right
    points[3].x = mid_x + half_width;
    points[3].y = mid_y - half_height;

    return points;
}