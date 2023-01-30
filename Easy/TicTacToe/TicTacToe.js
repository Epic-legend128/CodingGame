function winning(board) {
    if (board[0] == "OOO" || board[1] == "OOO" || board[2] == "OOO") {
        return true;
    }
    else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
        return true;
    }
    else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
        return true;
    }
    else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
        return true;
    }
    else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
        return true;
    }
    else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
        return true;
    }
    return false;
}

var board = [];
for (let i = 0; i < 3; i++) {
    var line = readline();
    board.push(line);
}

var found = false;
for (var i = 0; i<3; i++) {
    for (var j = 0; j<3; j++) {
        if (board[i][j] == '.') {
            var temp = "";
            var previous = board[i];
            for (var k = 0; k<j; k++) {
                temp+=board[i][k];
            }
            temp+="O";
            for (var k = j+1; k<3; k++) {
                temp+=board[i][k];
            }

            board[i] = temp;
            if (winning(board)) {
                found = true;
                break;
            }
            else {
                board[i] = previous;
            }
        }
    }
    if (found) break;
}

if (found) {
    for (var i = 0; i<3; i++) {
        console.log(board[i]);
    }
}
else {
    console.log("false");
}
