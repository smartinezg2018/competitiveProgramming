#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int nums = 4;
    vector<int> ls(nums), pos(nums);
    int count = 0;

    // Seed random number generator
    srand(time(0));

    // Function to fill a vector with random numbers from 1 to 50
    auto fill_random = [](vector<int> &v) {
        for (int &x : v) {
            x = rand() % 9;
        }
    };

    fill_random(ls);
    fill_random(pos);

    while (ls != pos) {
        count++;
        fill_random(ls);
        // fill_random(pos);
    }
    for(int i = 0; i <ls.size();i++){
        cout<<ls[i]<<" ";
    }
    cout<<endl;

    cout << rand() << endl;

    return 0;
}