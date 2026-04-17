const readline = require("readline");
 
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
    input = line.split(' ').map(el => parseInt(el));
    rl.close();
});

rl.on('close', () => {
    // input.forEach(el => {
    //     console.log(el);
    // });
    if (input[0] == '0') {
        console.log("YONSEI");
    }
    else if (input[0] == '1') {
        console.log("Leading the Way to the Future");
    }
    process.exit();
})
