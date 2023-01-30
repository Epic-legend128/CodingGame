const w = parseInt(readline());
const h = parseInt(readline());
var map = []
var visited = [];
for (let i = 0; i < h; i++) {
    const row = readline();
    map.push(row);
    var temp = [];
    for (var j = 0; j<w; j++) {
        temp.push([-1]);
    }
    visited.push(temp);
}

const n = parseInt(readline());
for (let i = 0; i < n; i++) {
    var inputs = readline().split(' ');
    const X = parseInt(inputs[0]);
    const Y = parseInt(inputs[1]);

    if (visited[Y][X][0] != -1) {
        console.log(visited[visited[Y][X][0]][visited[Y][X][1]][2]);
    }
    else if (map[Y][X] == '#') {
        console.log(0);
    }
    else {
        var oX = X;
        var oY = Y;
        var cX = oX;
        var cY = oY;
        var lower = 0;
        var queue = [];
        var total = 1;
        visited[oY][oX] = [oY, oX];
        while (true) {
            if (cY > 0) {
                if (map[cY-1][cX] == 'O' && visited[cY-1][cX][0] == -1) {
                    queue.push([cY-1, cX]);
                    visited[cY-1][cX] = [oY, oX];
                    total++;
                }
            }
            if (cY+1 < h) {
                if (map[cY+1][cX] == 'O' && visited[cY+1][cX][0] == -1) {
                    queue.push([cY+1, cX]);
                    visited[cY+1][cX] = [oY, oX];
                    total++;
                }
            }
            if (cX > 0) {
                if (map[cY][cX-1] == 'O' && visited[cY][cX-1][0] == -1) {
                    queue.push([cY, cX-1]);
                    visited[cY][cX-1] = [oY, oX];
                    total++;
                }
            }
            if (cX+1 < w) {
                if (map[cY][cX+1] == 'O' && visited[cY][cX+1][0] == -1) {
                    queue.push([cY, cX+1]);
                    visited[cY][cX+1] = [oY, oX];
                    total++;
                }
            }

            if (queue.length > lower) {
                cX = queue[lower][1];
                cY = queue[lower][0];
            }
            else {
                break;
            }
            lower++;
        }
        visited[oY][oX].push(total);
        console.log(total);
    }
}
