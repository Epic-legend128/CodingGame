#include <iostream>
#include <vector>
#include <map>
using namespace std;

using length = long long;
using price = long long;

int solve(map<length, price> &rods, map<length, price> &bests, long long l) {
    if (l == 0) return 0;
    if (bests[l] != 0) return bests[l];
    long long mx = 0;
    for (auto x: rods) {
        if (x.first > l) continue;
        int current = x.second + solve(rods, bests, l-x.first);
        if (mx < current) {
            mx = current;
        }
    }
    bests[l] = mx;
    return mx;
}

int main() {
    long long l, n;
    cin >> l >> n;
    map<length, price> bests;
    map<length, price> rods;
    for (long long i = 0; i<n; i++) {
        long long key, value;
        cin >> key >> value;
        rods[key] = value;
        bests[key] = 0;
    }
    long long result = solve(rods, bests, l);
    cout << result<< endl;
    return 0;
}
