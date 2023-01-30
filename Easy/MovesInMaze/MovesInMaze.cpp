#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define F first
#define S second

using namespace std;
using X = int;
using Y = int;

bool notVisited(vector<vector<bool> > visited, pair<Y, X> pos) {
    return !visited[pos.F][pos.S];
}

int mod(int a, int b) {
    return (b+(a%b))%b;
}

void distances(vector<string> &maze, pair<Y, X> pos) {
    maze[pos.F][pos.S] = '0';
    vector<vector<bool> > visited(maze.size(), vector<bool>(maze[0].length(), false));
    queue<pair<pair<Y, X>, int> > toDo;
    visited[pos.F][pos.S] = true;
    if (maze[mod(pos.F+1, maze.size())][pos.S] != '#' && notVisited(visited, make_pair(mod(pos.F+1, maze.size()), pos.S)))
        toDo.push(make_pair(make_pair((pos.F+1)%maze.size(), pos.S), 1));
    if (maze[mod(pos.F-1, maze.size())][pos.S] != '#' && notVisited(visited, make_pair(mod(pos.F-1, maze.size()), pos.S)))
        toDo.push(make_pair(make_pair(mod(pos.F-1, maze.size()), pos.S), 1));
    if (maze[pos.F][mod(pos.S-1, maze[0].length())] != '#' && notVisited(visited, make_pair(pos.F, mod(pos.S-1, maze[0].length()))))
        toDo.push(make_pair(make_pair(pos.F, mod(pos.S-1, maze[0].length())), 1));
    if (maze[pos.F][mod(pos.S+1, maze[0].length())] != '#' && notVisited(visited, make_pair(pos.F, mod(pos.S+1, maze[0].length()))))
        toDo.push(make_pair(make_pair(pos.F, mod(pos.S+1, maze[0].length())), 1));
    
    while (!toDo.empty()) {
        pos = toDo.front().F;
        int value = toDo.front().S+1;
        toDo.pop();
        if (!visited[pos.F][pos.S]) {
            visited[pos.F][pos.S] = true;

            char current;
            if (value <= 10) {
                current = to_string(value-1)[0];
            }
            else {
                current = 'A' + (value-11);
            }
            maze[pos.F][pos.S] = current;
            
            if (maze[mod(pos.F+1, maze.size())][pos.S] != '#' && notVisited(visited, make_pair(mod(pos.F+1, maze.size()), pos.S)))
                toDo.push(make_pair(make_pair((pos.F+1)%maze.size(), pos.S), value));
            if (maze[mod(pos.F-1, maze.size())][pos.S] != '#' && notVisited(visited, make_pair(mod(pos.F-1, maze.size()), pos.S)))
                toDo.push(make_pair(make_pair(mod(pos.F-1, maze.size()), pos.S), value));
            if (maze[pos.F][mod(pos.S-1, maze[0].length())] != '#' && notVisited(visited, make_pair(pos.F, mod(pos.S-1, maze[0].length()))))
                toDo.push(make_pair(make_pair(pos.F, mod(pos.S-1, maze[0].length())), value));
            if (maze[pos.F][mod(pos.S+1, maze[0].length())] != '#' && notVisited(visited, make_pair(pos.F, mod(pos.S+1, maze[0].length()))))
                toDo.push(make_pair(make_pair(pos.F, mod(pos.S+1, maze[0].length())), value));
        }
    }
}

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    vector<string> maze;
    bool found;
    pair<Y, X> pos;
    maze.reserve(h);
    for (int i = 0; i < h; i++) {
        string row;
        getline(cin, row);
        maze.push_back(row);
        if (!found) {
            for (int j = 0; j<row.length(); j++) {
                if (row[j] == 'S') {
                    pos.F = i;
                    pos.S = j;
                    found = true;
                    break;
                }
            }
        }
    }
    distances(maze, pos);

    for (auto x: maze) {
        cout << x<< endl;
    }
}
