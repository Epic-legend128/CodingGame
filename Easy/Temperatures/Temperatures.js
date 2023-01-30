const n = parseInt(readline());
var inputs = readline().split(' ');
var mn = 10005;
if (n > 0)
    for (let i = 0; i < n; i++) {
        const t = parseInt(inputs[i]);
        if ((Math.abs(mn) > Math.abs(t)) || (Math.abs(mn) == Math.abs(t) && t > mn))
            mn = t
    }
else
    mn = 0
console.log(mn);
