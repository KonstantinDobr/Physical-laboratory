#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

const long double FREE_FALL_ACCELERATION = 9.80665;

struct Point {
    long double x = 0.0;
    long double y = 0.0;
    bool operator == (const Point& other) {
        return tie(x, y) == tie(other.x, other.y);
    }
};

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
    while (true) {
        Point point = ballistic_coordinates_classic(radian_angle, speed_module, time_moment);
        coord_mas.push_back(point);
        time_moment += delta_time;

        if (coord_mas.size() > 2 && coord_mas[coord_mas.size() - 3] == coord_mas.back()) {
            break;
        }
    }
    return coord_mas;
}

string convert(long double myLongDouble) {
    stringstream blah;
    blah << myLongDouble;

    return blah.str();
}

int main() {
    // checking the function operation
    /*
    FILE *gpipe = _popen("\"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\gnuplot\\gnuplot 5.4 patchlevel 8 - console version.lnk\" -persist","w");
    if(!gpipe)
        return -1;

    fprintf(gpipe, "set terminal win\n");
    for (const auto& row : classic_ballistic_problem(M_PI_4, 10, 0.0015)) {
        fprintf(gpipe, "plot '-'\n");
        string text = convert(row.x) + " " + convert(row.y) + "\n";
        fprintf(gpipe, "%s", text.c_str());
    }
    fprintf(gpipe, "pause -1 \"hit enter to exit\"\n");
    fprintf(gpipe, "exit\n");
    pclose(gpipe);
    */
    return 0;
}
