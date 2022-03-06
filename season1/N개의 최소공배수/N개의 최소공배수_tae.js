function solution(arr) {
    let Max = arr.reduce( (Max, curVal) => Math.max(Max,curVal))
    // console.log(Max)
    for (let i = 1;; i++)
    {
        if ( arr.every( el => (Max * i) % el == 0))
            return Max * i
    }
    
}