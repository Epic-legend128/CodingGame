function convertToNumber(plate) {
    var first = (plate.charCodeAt(0)-65)*999*26*26*26;
    var second = (plate.charCodeAt(1)-65)*999*26*26;
    var num = parseInt(plate[3]+plate[4]+plate[5]);
    var third = (plate.charCodeAt(7)-65)*999*26;
    var fourth = (plate.charCodeAt(8)-65)*999;
    var result = first+second+num+third+fourth;
    return result;
}

function convertToPlate(num) {
    var result = "";
    var mult;
    var allMult = [999*26*26*26, 999*26*26, 999*26, 999];
    var results = ["", "", "", ""];
    var current = num;
    for (var i = 0; i<allMult.length; i++) {
        mult = allMult[i];
        var amount;
        if (current != mult) amount = Math.floor(current/mult);
        else amount = Math.floor(current/(mult+1));
        results[i] = String.fromCharCode(65+amount);
        current -= (amount*mult);
    }
    var num = current.toString();
    if (num.length == 1) num = "00"+num;
    else if (num.length==2) num = '0'+num;
    result = results[0]+results[1]+'-'+num+'-'+results[2]+results[3];
    return result;
}

const x = readline();
const n = parseInt(readline());
var num = convertToNumber(x);
var result = convertToPlate(num+n);
console.log(result);
