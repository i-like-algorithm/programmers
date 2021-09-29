function solution(arr1, arr2) {
    let answer = [];
    
    for (let arr of arr1)
    {
        let tmp = [];
        for(let i = 0; i < arr2[0].length; i++)
        {
            tmp.push(arr.reduce((acc, curVal, curIndex) => { return acc + curVal*arr2[curIndex][i]} , 0))
        }
        answer.push(tmp);
    }
    return answer;
}
/*
a11 a12   b11 b12 b13
a21 a22   b21 b22 b23
a31 a32   
*/