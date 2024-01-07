#include "constants_and_structures.cpp"
#include "classic_ballistic_problem.cpp"
#include "ballistic_problem_obstacle.cpp"
#include "three_loads_two_fixed_blocks.cpp"
#include "classic_fixed_block.cpp"

using namespace std;

string convert(long double myLongDouble) {
    stringstream blah;
    blah << myLongDouble;

    return blah.str();
}

int main() {
    // checking the function operation

    /* FILE *gpipe = _popen("\"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\gnuplot\\gnuplot 5.4 patchlevel 8 - console version.lnk\" -persist","w");
    if(!gpipe) return -1;

    fprintf(gpipe, "set terminal win\n");

    for (const auto& row : ballistic_problem_obstacle(M_PI_4, 10, 0.001, 7, 600)) {
        fprintf(gpipe, "plot '-'\n");
        string text = convert(row.x) + " " + convert(row.y) + "\n";
        fprintf(gpipe, "%s", text.c_str());
    }

    fprintf(gpipe, "pause -1 \"hit enter to exit\"\n");
    fprintf(gpipe, "exit\n");

    pclose(gpipe); */

    /* Block block1 = {0, 0, 1, 1, 1};
    Block block2 = {5, 10, 1, 1, 2};
    Block block3 = {11, 0, 1, 1, 3};

    for (const auto& row : three_loads_two_fixed_blocks(0.5,
                                                        block1, block2, block3, 0.15)) {
        cout << "{" << row[0].x << "; " << row[0].y << "}" << " " << "{" << row[1].x << "; " << row[1].y << "}" << " " << "{" << row[2].x << "; " << row[2].y << "}" << "\n";
    } */

    /* Block block1 = {0, -12, 1, 1, 3};
    Block block2 = {5, 3, 1, 1, 5};

    for (const auto& row : classic_fixed_block(block1, block2, 10, 5, 0.015)) {
        cout << "{" << row.first.x << "; " << row.first.y << "}" << " " << "{" << row.second.x << "; " << row.second.y
             << "}" << "\n";
    } */
}
