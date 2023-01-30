const alignment = readline();
const N = parseInt(readline());
var whole = [];
var mx = -1;
for (let i = 0; i < N; i++) {
    const text = readline();
    if (alignment == "LEFT") {
        console.log(text);
    }
    else {
        whole.push(text);
    }
    mx = Math.max(mx, text.length);
}

if (alignment == "RIGHT") {
    for (var i = 0; i<N; i++) {
        var spaces = "";
        for (var j = whole[i].length; j<mx; j++) {
            spaces+=" ";
        }
        console.log(spaces+whole[i]);
    }
}
else if (alignment == "CENTER") {
    for (var i = 0; i<N; i++) {
        var spaces = "";
        for (var j = 0; j<Math.floor((mx-whole[i].length)/2); j++) {
            spaces+=" ";
        }
        console.log(spaces+whole[i]);
    }
}
else {
    for (var i = 0; i<N; i++) {
        var spacesNeeded = mx-whole[i].length;
        var n = whole[i].split(' ');
        var eachSpace = Math.floor(spacesNeeded/(n.length-1));
        var spaces = " ";
        for (var j = 0; j<eachSpace; j++) {
            spaces+=" ";
        }
        var final = n[0];
        for (var j = 1; j<n.length; j++) {
            final += spaces+n[j];
        }
        console.log(final);
    }
}
