#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; cin.ignore();
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());
    int sum = nums[0]+nums[1];
    nums.push_back(sum);
    sort(nums.begin()+1, nums.end());
    int current = sum;
    for (int i = 2; i<nums.size()-1; i+=2) {
        current = nums[i]+nums[i+1];
        sum += current;
        nums.push_back(current);
        sort(nums.begin(), nums.end());
    }

    cout << sum << endl;
}
