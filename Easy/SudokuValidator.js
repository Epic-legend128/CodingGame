function includesAll(str, str2) {
    var foundAll = true;
    for (var i = 0; i<str2.length; i++) {
        if (!str.includes(str2[i])) {
            foundAll = false;
            break;
        }
    }
    return foundAll;
}


var whole = [];
var nums = "123456789";
var end = true;
for (let i = 0; i < 9; i++) {
    var inputs = readline();
    if (!includesAll(inputs, nums)) {
        end = false;
        break;
    }
    whole.push(inputs);
}

if (end) {
    for (var i = 0; i<17; i+=2) {
        var col = "";
        for (var j =0; j<9; j++) {
            col+=whole[j][i];
        }

        if (!includesAll(col, nums)) {
            end = false;
            break;
        }
    }

    if (end) {
        for (var i2 = 0; i2<3; i2++) {
            for (var j2 = 0; j2<3; j2++) {
                var block = "";
                for (var i = 0; i<3; i++) {
                    for (var j = 0; j<5; j+=2) {
                        block+=whole[i+i2*3][j+j2*6];
                    }
                }
                if (!includesAll(block, nums)) {
                    end = false;
                    break;
                }
            }
            if (!end) break;
        }
    }
}
if (end) console.log("true");
else console.log("false");
