function addOne(a) {
    var result = "";
    var carry = 1;
    for (var i = a.length-1; i>=0; i--) {
        if (a[i] == '9' && carry == 1) {
            result = '0'+result;
            carry = 1;
        }
        else {
            result = (parseInt(a[i])+carry).toString()+result;
            carry = 0;
        }
    }
    if (carry==1) result = '1'+result;
    return result;
}

function transform(num) {
    var mx = num[0];
    var result = "";
    var becameBigger = false;
    for (var i = 0; i<num.length; i++) {
        if (parseInt(num[i]) > mx && !becameBigger) {
            mx = parseInt(num[i]);
        }
        else if (parseInt(num[i]) < mx) {
            becameBigger = true;
        }
        result = result+mx;
    }
    return result;
}

const n = readline();
console.log(transform(addOne(n)));
