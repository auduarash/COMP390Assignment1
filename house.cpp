#include <stdlib.h>
#include "house.hpp"


using namespace std;

House::House(float center_x, float center_y) {
    set_center(center_x, center_y);

    //default values 
    body_width = 0;
    body_height = 0;
    roof_height = 0;
    roof_width = 0;
}

void House::set_body_dimensions(float h, float w) {
    body_height = h;
    body_width = w;
}

void House::set_roof_dimensions(float h, float w) {
    roof_height = h;
    roof_width = w;
}

void House::set_center(float x, float y) {
    this->center_x = x;
    this->center_y = y;
    set_roof_points();
    set_body_points();
}


void House::set_roof_points() {
    roof_points.resize(3);
    
    //top of roof
    roof_points[0].x = center_x;
    roof_points[0].y = center_y + (body_height / 2) + roof_height;
    //right edge
    roof_points[1].x = roof_points[0].x + (roof_width / 2);
    roof_points[1].y = roof_points[0].y - roof_height;
    //left edge of roof
    roof_points[2].x = roof_points[0].x - (roof_width / 2);
    roof_points[2].y = roof_points[0].y - roof_height;
}
vector<wcPt2D> House::get_roof_points() {
    return roof_points;
}

void House::set_body_points() {
    body_points.resize(4);
    float half_height = body_height/2;
    float half_width = body_width/2;
    float mid_x = center_x;
    float mid_y = center_y;
    //bottom left
    body_points[0].x = mid_x - half_width;
    body_points[0].y = mid_y - half_height;
    //top left
    body_points[1].x = mid_x - half_width;
    body_points[1].y = mid_y + half_height;
    //top right
    body_points[2].x = mid_x + half_width;
    body_points[2].y = mid_y + half_height;
    //bottom right
    body_points[3].x = mid_x + half_width;
    body_points[3].y = mid_y - half_height;
}


vector<wcPt2D> House::get_body_points() {
    return body_points;
}