/*
Name: Abdul-Rasheed Audu
Student#: 3253834
Course: COMP390
Assignment: 1
Problem: 1, 2

Purpose: Store information about a house and 
*/

#include <vector>


class wcPt2D {
    public:
        float x;
        float y;
};

class House {
    public:
        House(float, float);
        float roof_height;
        float roof_width;
        float body_height;
        float body_width;
        float center_x;
        float center_y;
        std::vector<wcPt2D> get_roof_points();
        std::vector<wcPt2D> get_body_points();
        void set_center(float, float);
        void set_body_dimensions(float height, float width);
        void set_roof_dimensions(float height, float width);
    private:
        std::vector<wcPt2D> roof_points;
        std::vector<wcPt2D> body_points;
        void set_roof_points();
        void set_body_points();
};
