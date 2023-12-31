using namespace std;

Point ballistic_coordinates_classic(double radian_angle, long double speed_module, long double time_moment) {
    long double x = cos(radian_angle) * speed_module * time_moment;
    long double y = sin(radian_angle) * speed_module * time_moment - FREE_FALL_ACCELERATION * pow(time_moment, 2) / 2;
    if (y < 0.0) {
        y = 0.0;
        x = cos(radian_angle) * speed_module * (speed_module * sin(radian_angle) / FREE_FALL_ACCELERATION * 2);
    }
    Point point = {x, y};
    return point;
}

vector<Point> classic_ballistic_problem(double radian_angle, long double speed_module, long double delta_time) {
    long double time_moment = 0;
    vector<Point> coord_mas;
    while (!(coord_mas.size() > 2 && coord_mas[coord_mas.size() - 3] == coord_mas.back())) {
        Point point = ballistic_coordinates_classic(radian_angle, speed_module, time_moment);
        coord_mas.push_back(point);
        time_moment += delta_time;
    }
    return coord_mas;
}