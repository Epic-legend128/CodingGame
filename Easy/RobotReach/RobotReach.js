function sum(num) {
    var a = num.toString();
    var result = 0;
    for (var i = 0; i<a.length; i++) {
        result+=parseInt(a[i]);
    }
    return result;
}

const R = parseInt(readline());
const C = parseInt(readline());
const T = parseInt(readline());
var amount = 0;

var whole = [];
for (var i = 0; i<R; i++) {
    var temp = [];
    for (var j = 0; j<C; j++) {
        temp.push([sum(i)+sum(j), 0]);
    }
    whole.push(temp);
}

var queue = [[0, 0]];
whole[0][0][1] = 1;
var index = 0;
while (queue.length > index) {
    amount++;
    var current = queue[index];
    if (current[0]+1 < R) {
        if (whole[current[0]+1][current[1]][0] <= T && whole[current[0]+1][current[1]][1] == 0) {
            whole[current[0]+1][current[1]][1] = 1;
            queue.push([current[0]+1, current[1]]);
        }
    }
    if (current[0] > 0) {
        if (whole[current[0]-1][current[1]][0] <= T && whole[current[0]-1][current[1]][1] == 0) {
            whole[current[0]-1][current[1]][1] = 1;
            queue.push([current[0]-1, current[1]]);
        }
    }
    if (current[1]+1 < C) {
        if (whole[current[0]][current[1]+1][0] <= T && whole[current[0]][current[1]+1][1] == 0) {
            whole[current[0]][current[1]+1][1] = 1;
            queue.push([current[0], current[1]+1]);
        }
    }
    if (current[1] > 0) {
        if (whole[current[0]][current[1]-1][0] <= T && whole[current[0]][current[1]-1][1] == 0) {
            whole[current[0]][current[1]-1][1] = 1;
            queue.push([current[0], current[1]-1]);
        }
    }
    index++;
}

console.log(amount);
