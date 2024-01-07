pair<Point, Point> classic_fixed_blocks_coordinates(Block block1, Block block2, long double block_mas, long double time_moment) {

    long double acceleration = FREE_FALL_ACCELERATION * (block1.weight - block2.weight) / (block1.weight + block2.weight + block_mas);
    long double diff = acceleration * pow(time_moment, 2) / 2;
    Point point1 = {block1.x, block1.y - diff};
    Point point2 = {block2.x, block2.y + diff};

    pair<Point, Point> points = {point1 , point2};
    return points;
}

vector<pair<Point, Point>> classic_fixed_block(Block block1, Block block2, long double max_y, long double block_mas, long double delta_time) {
    long double time_moment = 0;
    vector<pair<Point, Point>> coord_mas;
    do {
        coord_mas.push_back(classic_fixed_blocks_coordinates(block1, block2, block_mas, time_moment));
        time_moment += delta_time;
        if (coord_mas.size() > 2 && coord_mas.back().second == coord_mas[coord_mas.size() - 3].second) break;
    } while (coord_mas.back().first.y < max_y && coord_mas.back().second.y < max_y);
    return coord_mas;
}
