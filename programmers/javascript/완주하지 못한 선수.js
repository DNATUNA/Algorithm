const participant = ['mislav', 'stanko', 'mislav', 'ana'];
const completion = ['stanko', 'ana', 'mislav'];

let answer;
const list = new Map();

for(let i=0; i<participant.length; ++i) list.set(participant[i], list.get(participant[i]) ?  list.get(participant[i]) + 1 : 1);
for(let i=0; i<completion.length; ++i) {
    if(list.get(completion[i]) == 1) list.delete(completion[i]);
    else list.set(completion[i], list.get(completion[i] - 1));
}

for(const [key, value] of list.entries()) answer = key;
console.log(answer);