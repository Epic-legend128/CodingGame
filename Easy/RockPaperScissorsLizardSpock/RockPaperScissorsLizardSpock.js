class Player {
    constructor(num, sign) {
        this.num = num;
        this.sign = sign;
        this.won = [];
    }
};

function winner(player1, player2) {
    var getBeaten = {
        "P": "CL",
        "R": "PS",
        "C": "RS",
        "L": "RC",
        "S": "PL"
    };
    
    if (getBeaten[player1.sign].includes(player2.sign)) {
        player2.won.push(player1.num);
        return player2;
    }
    else if (getBeaten[player2.sign].includes(player1.sign)) {
        player1.won.push(player2.num);
        return player1;
    }
    else {
        if (player1.num > player2.num) {
            player2.won.push(player1.num);
        }
        else {
            player1.won.push(player2.num);
        }
        return player1.num > player2.num ? player2 : player1;
    }
}

function nextRounds(rounds) {
    var newRounds = [];
    for (var i = 0; i<rounds.length; i+=2) {
        newRounds.push(winner(rounds[i], rounds[i+1]));
    }
    return newRounds;
}

const N = parseInt(readline());
var players = [];

for (let i = 0; i < N; i++) {
    var inputs = readline().split(' ');
    const NUMPLAYER = parseInt(inputs[0]);
    const SIGNPLAYER = inputs[1];
    players.push(new Player(NUMPLAYER, SIGNPLAYER));
}

var done = false;
var current = players;
while(current.length > 1) {
    current = nextRounds(current);
}

console.log(current[0].num);
var path = current[0].won[0];
for (var i = 1; i<current[0].won.length; i++) {
    path += " "+current[0].won[i];
}
console.log(path);
