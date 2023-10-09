function get_character_cnt(str : string, pattern) { 
    let position : number;
    let cnt : number = 0;
    const not_found : number = -1;

    while (1) {
        position = str.search(pattern);
        if (position == not_found)
            break ;
        str = str.substring(position + 1);
        ++cnt;
    }
    return cnt;
}

let lines : string[] = require('fs').readFileSync(0).toString().trim().split('\n');
let pattern = /[aeiou]/i;

for (let i : number = 0; i < lines.length - 1; ++i) {
    console.log(get_character_cnt(lines[i], pattern));
}
