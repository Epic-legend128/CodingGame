#include <iostream>

using namespace std;

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    int mn = 10005;
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        if (abs(mn) > abs(t)) {
            mn = t;
        }
        else if (abs(mn) == abs(t) && t > mn) {
            mn = t;
        }
    }
    if (n == 0) mn = 0;

    cout << mn << endl;
}
