#include <iostream>
#include <vector>
#include <limits>

using namespace std;

long long bestCombination(vector<long long> &values, vector<long long> &bests, int house) {
    if (house >= values.size()) return 0;
    if (bests[house] < numeric_limits<long long int>::max()) return bests[house];
    long long mx = numeric_limits<long long int>::min();
    for (int i = house; i<values.size(); i++) {
        long long current = bestCombination(values, bests, i+2)+values[i];
        mx = current > mx ? current : mx;
    }
    if (mx < 0) mx = 0;
    bests[house] = mx;
    return mx;
}

int main() {
    int n;
    cin >> n;
    vector<long long> values;
    for (int i = 0; i<n; i++) {
        long long current;
        cin >> current;
        values.push_back(current);
    }
    vector<long long> bests(n, numeric_limits<long long int>::max());
    long long result = bestCombination(values, bests, 0);
    cout << result<< endl;
    return 0;
}
