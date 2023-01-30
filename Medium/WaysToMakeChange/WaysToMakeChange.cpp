#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int possibleCombinations(vector<int> &coins, int amount, int coinIndex, vector<vector<int> > &bests) {
    if (amount > 0 && coinIndex >= coins.size()) return 0;
    if (amount <= 0) return 1;
    if (bests[amount][coinIndex] > 0) return bests[amount][coinIndex];

    int startingCoinIndex = coinIndex;
    int ways = 0;
    int coin;
    while (coinIndex < coins.size()) {
        coin = coins[coinIndex];
        if (coin <= amount) {
            for (int i = 1; i*coin <= amount; i++) {
                ways += possibleCombinations(coins, amount-(i*coin), coinIndex+1, bests);
            }
        }
        coinIndex++;
    }
    bests[amount][startingCoinIndex] = ways;
    return ways;
}

int main() {
    int targetValue, amount;
    cin >> targetValue >> amount;
    vector<int> coins;
    coins.reserve(amount);
    for (int i = 0; i<amount; i++) {
        int current;
        cin >> current;
        coins.push_back(current);
    }
    sort(coins.begin(), coins.end(), comp);
    vector<vector<int> > bests(targetValue+1, vector<int>(amount+1, 0));
    int result = possibleCombinations(coins, targetValue, 0, bests);
    cout << result<< endl;
    return 0;
}
