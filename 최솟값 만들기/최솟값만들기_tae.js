function solution(A,B){
    let sortA = A.sort((a,b) => {return a-b})
    let sortB = B.sort((a,b) => {return b-a})
    return sortA.reduce((acc, curVal, curIndex) => { return acc + curVal*sortB[curIndex]},0)
}