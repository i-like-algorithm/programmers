function solution(n) {
    let countOne = n.toString(2).replace(/0/g,'').length;
    
    for (let x = n+1;;x++)
        {
            if (countOne == x.toString(2).replace(/0/g,'').length)
                return x;
        }
}