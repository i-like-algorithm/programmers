function solution(n) {
    
    let answer = [];
    
    while (1){
        if (n % 3 == 0){
            answer.unshift(4)
            n = parseInt((n / 3) - 1)
        } 
        else {
            answer.unshift(n % 3)
            n = parseInt(n / 3)
        } 
        if (n == 0) break;
    }
    return answer.join('');
    
}