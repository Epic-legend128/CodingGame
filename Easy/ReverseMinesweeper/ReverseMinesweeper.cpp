#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w;
    cin >> w; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    vector<string> map;
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        map.push_back(line);
    }
    vector<int> result(h*w, 0);
    for (int i = 0; i<h; i++) {
        for (int j = 0; j<w; j++) {
            int current = 0;
            if (map[i][j] == '.') {
                if (i+1<h) {
                    if (map[i+1][j] == 'x') {
                        current++;
                    }
                }
                if (i>0) {
                    if (map[i-1][j] == 'x') {
                        current++;
                    }
                }

                if (j<w) {
                    if (map[i][j+1] == 'x') {
                        current++;
                    }
                }
                if (j>0) {
                    if (map[i][j-1] == 'x') {
                        current++;
                    }
                }

                if (i+1<h && j<w) {
                    if (map[i+1][j+1] == 'x') {
                        current++;
                    }
                }
                if (i>0 && j>0) {
                    if (map[i-1][j-1] == 'x') {
                        current++;
                    }
                }
                if (i+1<h && j>0) {
                    if (map[i+1][j-1] == 'x') {
                        current++;
                    }
                }
                if (i>0 && j<w) {
                    if (map[i-1][j+1] == 'x') {
                        current++;
                    }
                }
                //cerr << i*w+j<<endl;
                //cerr << i<< " "<<j<< endl;
                result[i*w+j] = current;
            }
        }
    }
    int lines = 0;
    for (int i = 0; i<w*h; i++) {
        if ((i-(lines*w)) == w) {
            cout << "\n";
            lines++;
        }
        if (result[i] == 0) {
            cout << '.';
        }
        else {
            cout << result[i];
        }
    }
}
