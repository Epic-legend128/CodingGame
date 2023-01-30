#include <iostream>
#include <vector>

using namespace std;

using Value = int;

int main() {
    int start, n;
    cin >> start >> n;
    vector<Value> memoization(1000005, -1);
    Value term = start;
    for (int i = 0; i<n-1; i++) {
        if (memoization[term] == -1) {
            memoization[term] = i;
            term = 0;
        }
        else {
            int prev = memoization[term];
            memoization[term] = i;
            term = i - prev;
        }
    }
    cout << term<< endl;
    return 0;
}
