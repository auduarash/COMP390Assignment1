#include <vector>

struct HOUSE {
    float roof_height;
    float roof_width;
    float body_height;
    float body_width;
    float center_x;
    float center_y;
    float angle;
};

struct POINT2D {
    float x;
    float y;
};

std::vector<POINT2D> get_roof_points(HOUSE &house);
std::vector<POINT2D> get_house_body_points(HOUSE &house);