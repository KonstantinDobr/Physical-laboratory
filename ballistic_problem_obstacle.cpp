vector<Point> ballistic_problem_obstacle(double radian_angle, long double speed_module, long double delta_time,
                                         long double distance, long double height) {
    long double time_moment = 0;
    vector<Point> coord_mas;

    if (speed_module * speed_module * sin(radian_angle * 2) / FREE_FALL_ACCELERATION <= distance) {
        while (!(coord_mas.size() > 2 && coord_mas[coord_mas.size() - 3] == coord_mas.back())) {
            Point point = ballistic_coordinates_classic(radian_angle, speed_module, time_moment);
            coord_mas.push_back(point);
            time_moment += delta_time;
        }
        return coord_mas;
    } else if (distance / cos(radian_angle) * sin(radian_angle) - FREE_FALL_ACCELERATION * pow(distance / (speed_module * cos(radian_angle)), 2) / 2 <= height) {
        while (!(coord_mas.size() > 2 && coord_mas[coord_mas.size() - 3] == coord_mas.back())) {
            Point point = ballistic_coordinates_classic(radian_angle, speed_module, time_moment);
            if (distance / (speed_module * cos(radian_angle)) < time_moment) {
                point.x = 2 * distance - point.x;
            }
            coord_mas.push_back(point);
            time_moment += delta_time;
        }
        return coord_mas;
    } else {
        while (
                sqrt(2 * ((speed_module * sin(radian_angle)) * (speed_module * sin(radian_angle))
                / FREE_FALL_ACCELERATION / 2 - height) / FREE_FALL_ACCELERATION) +
                speed_module * sin(radian_angle) / FREE_FALL_ACCELERATION
                > time_moment
                ) {
            Point point = ballistic_coordinates_classic(radian_angle, speed_module, time_moment);
            coord_mas.push_back(point);
            time_moment += delta_time;
        }
        return coord_mas;
    }
}