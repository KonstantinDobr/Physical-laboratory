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

struct Block {
    long double x;
    long double y;
    long double width;
    long double height;
    long double weight;
};