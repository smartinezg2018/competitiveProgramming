#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int nums = 3;
    vector<int> ls(nums), pos(nums);
    int count = 0;

    // Seed random number generator
    srand(time(0));

    // Function to fill a vector with random numbers from 1 to 50
    auto fill_random = [](vector<int> &v) {
        for (int &x : v) {
            x = rand() % 50 + 1;
        }
    };

    fill_random(ls);
    fill_random(pos);

    while (ls != pos) {
        count++;
        fill_random(ls);
        fill_random(pos);
    }

    cout << count << endl;

    return 0;
}