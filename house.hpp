#include <vector>

class House {
    public:
        float roof_height;
        float roof_width;
        float body_height;
        float body_width;
        float center_x;
        float center_y;
        float angle;
};

class wcPt2D {
    public:
        float x;
        float y;
};

std::vector<wcPt2D> get_roof_points(House &house);
std::vector<wcPt2D> get_house_body_points(House &house);