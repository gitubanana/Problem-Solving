function getIntervalDays(startDate, endDate) {
    return Math.floor((endDate.getTime() - startDate.getTime()) / (1000 * 60 * 60 * 24));
}

let lines = require('fs').readFileSync(0).toString().trim().split('\n');
let startDate = new Date(lines[0].split(' ').map(Number));
let endDate = new Date(lines[1].split(' ').map(Number));

let intervalDays = getIntervalDays(startDate, endDate);
startDate.setFullYear(startDate.getFullYear() + 1000);
if (startDate <= endDate)
    console.log('gg');
else
    console.log('D-' + intervalDays);
