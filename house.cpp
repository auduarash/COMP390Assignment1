#include <stdlib.h>
#include "house.hpp"



ROOF_POINTS get_roof_points(HOUSE &house) {
    ROOF_POINTS rf;
    rf.points.resize(3);
    
    //right edge of roof
    rf.points[0].x = house.roof.roof_top_x + (house.roof.roof_width/2);
    rf.points[0].y = house.roof.roof_top_y - (house.roof.roof_height);
    //top of roof
    rf.points[1].x = house.roof.roof_top_x;
    rf.points[1].y = house.roof.roof_top_y;
    //left edge of roof
    rf.points[2].x = house.roof.roof_top_x - (house.roof.roof_width/2);
    rf.points[2].y = rf.points[0].y;
    return rf;
}

HB_POINTS get_house_body_points(HOUSE &house) {
    HB_POINTS hb;
    hb.points.resize(4);
    #define half_height house.body.height/2
    #define half_width house.body.width/2
    #define mid_x house.body.center_x
    #define mid_y house.body.center_y
    //bottom left
    hb.points[0].x = mid_x - half_height;
    hb.points[0].y = mid_y - half_height;
    //top left
    hb.points[1].x = mid_x - half_height;
    hb.points[1].y = mid_y + half_height;
    //top right
    hb.points[2].x = mid_x + half_height;
    hb.points[2].y = mid_y + half_height;
    //bottom right
    hb.points[3].x = mid_x + half_height;
    hb.points[3].y = mid_y - half_height;

    return hb;
}