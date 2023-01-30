const N = parseInt(readline());
var strengths = [];
for (let i = 0; i < N; i++) {
    const pi = parseInt(readline());
    strengths.push(pi);
}
strengths = strengths.sort((a, b) => {
    return a-b;
});

var mn = strengths[strengths.length-1];
for (var i = 0; i<strengths.length-1; i++) {
    mn = Math.min(mn, strengths[i+1]-strengths[i]);
}

console.log(mn);
