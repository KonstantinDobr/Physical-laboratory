vector<Point> fixed_blocks_coordinates(long double coefficient,
                               Block block1, Block block2, Block block3,
                               long double time_moment) {

    long double acceleration = FREE_FALL_ACCELERATION * (block3.weight - coefficient * block2.weight - block1.weight) / (block1.weight + block2.weight + block3.weight);
    Point point1 = {block1.x, block1.y + acceleration * pow(time_moment, 2) / 2};
    Point point2 = {block2.x + acceleration * pow(time_moment, 2) / 2, block2.y};
    Point point3 = {block3.x, block3.y - acceleration * pow(time_moment, 2) / 2};

    vector<Point> points = {point1 , point2, point3};
    return points;
}

vector<vector<Point>> three_loads_two_fixed_blocks(long double coefficient,
                                                   Block block1, Block block2, Block block3,
                                                   long double delta_time) {
    long double time_moment = 0;
    vector<vector<Point>> coord_mas;
    vector<Point> points;
    do {
        points = fixed_blocks_coordinates(coefficient, block1, block2, block3, time_moment);
        coord_mas.push_back(points);
        time_moment += delta_time;
        if (coord_mas.size() > 2 && coord_mas.back()[0] == coord_mas[coord_mas.size() - 3][0]) break;
    } while (points[0].y < block2.y - block2.height && points[2].y < block2.y - block2.height &&
             points[1].x > block1.x && points[1].x + block2.width < block3.x);
    return coord_mas;
}
