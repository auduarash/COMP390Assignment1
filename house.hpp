#include <vector>

using namespace std;
struct ROOF {
    float roof_top_x;
    float roof_top_y;
    float roof_height;
    float roof_width;
};

struct HOUSE_BODY {
    float center_x;
    float center_y;
    float width;
    float height;
};

struct HOUSE {
    HOUSE_BODY body;
    ROOF roof;
    int angle;
};

struct POINT2D {
    float x;
    float y;
};

struct ROOF_POINTS {
    vector<POINT2D> points;
};

struct HB_POINTS {
    vector<POINT2D> points;
};

ROOF_POINTS get_roof_points(HOUSE &house);
HB_POINTS get_house_body_points(HOUSE &house);