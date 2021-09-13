function solution(n) {
    let set = [1,2,4]; // index (나머지가 1일 때 0, 2일때 1, 0일때 2)
    let remainder = [];
    let idx;
    
    while (n) {
        if (n % 3 === 0) {
            idx = 2;
            n--;
        }
        else
            idx = n % 3 - 1;
        remainder.unshift(set[idx]);
        n = parseInt(n / 3);
    }
    return (remainder.join(''));   
}
