#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int minimum_squares(vector<vector<int> > &chocolate, int w, int h) {
    if (w == h) return 1;
    if (chocolate[h][w] < numeric_limits<int>::max()) return chocolate[h][w];

    int minHorizontal = numeric_limits<int>::max();
    for (int i = 1; i<=h/2; i++) {
        minHorizontal = min(minimum_squares(chocolate, w, h-i) + minimum_squares(chocolate, w, i), minHorizontal);
    }

    int minVertical = numeric_limits<int>::max();
    for (int i = 1; i<=w/2; i++) {
        minVertical = min(minimum_squares(chocolate, w-i, h) + minimum_squares(chocolate, i, h), minVertical);
    }

    int result = min(minHorizontal, minVertical);
    chocolate[h][w] = result;
    return result;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int> > chocolate(h+1, vector<int>(w+1, numeric_limits<int>::max()));
    cout << minimum_squares(chocolate, w, h) << endl;
    return 0;
}
