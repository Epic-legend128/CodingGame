function reverse(symbol) {
    switch(symbol) {
        case '*':
            return '~';
        default:
            return '*';
    }
}

function reverseAround(b, place) {
    var board = b;
    switch(place) {
        case 1:
            board[0][0] = reverse(board[0][0]);
            board[1][0] = reverse(board[1][0]);
            board[0][1] = reverse(board[0][1]);
            board[1][1] = reverse(board[1][1]);
            break;
        case 2:
            board[0][0] = reverse(board[0][0]);
            board[0][1] = reverse(board[0][1]);
            board[0][2] = reverse(board[0][2]);
            break;
        case 3:
            board[0][1] = reverse(board[0][1]);
            board[0][2] = reverse(board[0][2]);
            board[1][1] = reverse(board[1][1]);
            board[1][2] = reverse(board[1][2]);
            break;
        case 4:
            board[0][0] = reverse(board[0][0]);
            board[1][0] = reverse(board[1][0]);
            board[2][0] = reverse(board[2][0]);
            break;
        case 5:
            board[0][1] = reverse(board[0][1]);
            board[1][1] = reverse(board[1][1]);
            board[1][0] = reverse(board[1][0]);
            board[1][2] = reverse(board[1][2]);
            board[2][1] = reverse(board[2][1]);
            break;
        case 6:
            board[2][2] = reverse(board[2][2]);
            board[1][2] = reverse(board[1][2]);
            board[0][2] = reverse(board[0][2]);
            break;
        case 7:
            board[1][0] = reverse(board[1][0]);
            board[2][0] = reverse(board[2][0]);
            board[1][1] = reverse(board[1][1]);
            board[2][1] = reverse(board[2][1]);
            break;
        case 8:
            board[2][2] = reverse(board[2][2]);
            board[2][1] = reverse(board[2][1]);
            board[2][0] = reverse(board[2][0]);
            break;
        case 9:
            board[2][2] = reverse(board[2][2]);
            board[2][1] = reverse(board[2][1]);
            board[1][1] = reverse(board[1][1]);
            board[1][2] = reverse(board[1][2]);
            break;
    }
    return board;
}

function complete(board, x, y) {
    board = reverseAround(board, x+1+y*3);
    var okay = true;
    for (var i = 0; i<3; i++) {
        for (var j = 0; j<3; j++) {
            if (board[i][j] != '*' && i != 1 && j != 1) {
                okay = false;
                break;
            }
            else if (i == 1 && j == 1 && board[i][j] == '*') {
                okay = false;
                break;
            }
        }
    }
    if (!okay) {
        board = reverseAround(board, x+1+y*3);
        return false;
    }
    return true;
}

var row1 = readline().split(' ');
var row2 = readline().split(' ');
var row3 = readline().split(' ');
const allButtonsPressed = readline();

board = [row1, row2, row3]

for (var i = 0; i<allButtonsPressed.length; i++) {
    board = reverseAround(board, parseInt(allButtonsPressed[i]));
}

var i;
var toBreak = false;
for (var i = 0; i<3; i++) {
    for (var j = 0; j<3; j++) {
        var isDone = complete(board, j, i);
        if (isDone) {
            toBreak = true;
            break;
        }
    }
    if (toBreak)
        break;
}

console.log(j+1+i*3);
