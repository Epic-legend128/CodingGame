#include <iostream>
#include <vector>
#include <utility>

#define F first
#define S second

using namespace std;

using Line = string;
using Cell = char;

string allowed = "SENW @$BIT";
string directionsChangers = "SENW#X";

bool breaker = false;
bool inverted = false;
bool prevent = false;
vector<string> moves;

void changeDir(vector<Line> &map, pair<int, int> &pos, int &dir, Cell wall) {
    switch (wall) {
        case 'N':
            dir = 2;
            break;
        case 'S':
            dir = 0;
            break;
        case 'E':
            dir = 3;
            break;
        case 'W':
            dir = 1;
            break;
        default:
            if (!inverted) {
                if (allowed.find(map[pos.F+1][pos.S]) != string::npos) {
                    dir = 0;
                    pos.F++;
                    prevent = true;
                    moves.push_back("SOUTH");
                }
                else if (allowed.find(map[pos.F][pos.S+1]) != string::npos) {
                    dir = 3;
                    pos.S++;
                    prevent = true;
                    moves.push_back("EAST");
                }
                else if (allowed.find(map[pos.F-1][pos.S]) != string::npos) {
                    dir = 2;
                    pos.F--;
                    prevent = true;
                    moves.push_back("NORTH");
                }
                else {
                    dir = 1;
                    pos.S--;
                    prevent = true;
                    moves.push_back("WEST");
                }
            }
            else {
                if (allowed.find(map[pos.F][pos.S-1]) != string::npos) {
                    dir = 1;
                    pos.S--;
                    prevent = true;
                    moves.push_back("WEST");
                }
                else if (allowed.find(map[pos.F-1][pos.S]) != string::npos) {
                    dir = 2;
                    pos.F--;
                    prevent = true;
                    moves.push_back("NORTH");
                }
                else if (allowed.find(map[pos.F][pos.S+1]) != string::npos) {
                    dir = 3;
                    pos.S++;
                    prevent = true;
                    moves.push_back("EAST");
                }
                else {
                    dir = 0;
                    pos.F++;
                    prevent = true;
                    moves.push_back("SOUTH");
                }
            }
            if (directionsChangers.find(map[pos.F][pos.S]) != string::npos) {
                if ((map[pos.F][pos.S] == 'X' && !breaker) || map[pos.F][pos.S] != 'X') {
                    changeDir(map, pos, dir, map[pos.F][pos.S]);
                }
            }
            break;
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    cin.ignore();
    vector<Line> map;
    pair<int, int> pos;
    map.reserve(r);
    bool found = false;
    pair<pair<int, int>, pair<int, int> > teleporters;
    bool hasTeleport = false;
    for (int i = 0; i<r; i++) {
        Line l;
        getline(cin, l);
        
        map.push_back(l);
        for (int j = 0; j<l.length(); j++) {
            if (l[j] == '@') {
                found = true;
                pos.F = i;
                pos.S = j;
            }
            else if (l[j] == 'T') {
                if (hasTeleport) {
                    teleporters.S.F = i;
                    teleporters.S.S = j;
                }
                else {
                    teleporters.F.F = i;
                    teleporters.F.S = j;
                }
                hasTeleport = true;
            }
        }
    }

    Cell current = '@';
    int dir = 0; // 0==south, 1==west, 2==north, 3==east
    int count = 0;
    while (current != '$' && count < 100000) {
        if (map[pos.F][pos.S] == 'I') {
            inverted = (inverted+1)%2;
        }
        else if (map[pos.F][pos.S] == 'B') {
            breaker = (breaker+1)%2;
        }
        switch (dir) {
            case 0:
                if (directionsChangers.find(map[pos.F+1][pos.S]) != string::npos) {
                    if ((map[pos.F+1][pos.S] == 'X' && !breaker) || map[pos.F+1][pos.S] != 'X')
                        changeDir(map, pos, dir, map[pos.F+1][pos.S]);
                    else {
                        map[pos.F+1][pos.S] = ' ';
                    }
                }
                if (allowed.find(map[pos.F+1][pos.S]) != string::npos && !prevent) {
                    pos.F++;
                    moves.push_back("SOUTH");
                }
                break;
            case 1:
                if (directionsChangers.find(map[pos.F][pos.S-1]) != string::npos) {
                    if ((map[pos.F][pos.S-1] == 'X' && !breaker) || map[pos.F][pos.S-1] != 'X')
                        changeDir(map, pos, dir, map[pos.F][pos.S-1]);
                    else {
                        map[pos.F][pos.S-1] = ' ';
                    }
                }
                if (allowed.find(map[pos.F][pos.S-1]) != string::npos && !prevent) {
                    pos.S--;
                    moves.push_back("WEST");
                }
                break;
            case 2:
                if (directionsChangers.find(map[pos.F-1][pos.S]) != string::npos) {
                    if ((map[pos.F-1][pos.S] == 'X' && !breaker) || map[pos.F-1][pos.S] != 'X') {
                        //moves.push_back("Changing direction at "+to_string(pos.F-1)+" "+to_string(pos.S));
                        changeDir(map, pos, dir, map[pos.F-1][pos.S]);
                    }
                    else {
                        map[pos.F-1][pos.S] = ' ';
                    }
                }
                if (allowed.find(map[pos.F-1][pos.S]) != string::npos && !prevent) {
                    pos.F--;
                    moves.push_back("NORTH");
                }
                break;
            case 3:
                if (directionsChangers.find(map[pos.F][pos.S+1]) != string::npos) {
                    if ((map[pos.F][pos.S+1] == 'X' && !breaker) || map[pos.F][pos.S+1] != 'X')
                        changeDir(map, pos, dir, map[pos.F][pos.S+1]);
                    else {
                        map[pos.F][pos.S+1] = ' ';
                    }
                }
                if (allowed.find(map[pos.F][pos.S+1]) != string::npos && !prevent) {
                    pos.S++;
                    moves.push_back("EAST");
                }
                break;
        }
        if (map[pos.F][pos.S] == 'T') {
            if (pos.F == teleporters.F.F && pos.S == teleporters.F.S) {
                pos.F = teleporters.S.F;
                pos.S = teleporters.S.S;
            }
            else {
                pos.F = teleporters.F.F;
                pos.S = teleporters.F.S;
            }
        }
        count++;
        current = map[pos.F][pos.S];
        prevent = false;
    }
    if (count < 100000) {
        for (auto x: moves) {
            cout << x<< "\n";
        }
    }
    else {
        cout << "LOOP\n";
    }
    return 0;
}
