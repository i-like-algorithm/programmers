function solution(progresses, speeds) {

    let answer = [];
    
    let arr = progresses.map( el => 100 - el).map( (el, index) => Math.ceil(el / speeds[index]));
    // console.log(arr);
    
    let cnt = 1;
    arr.reduce( (max, curVal) => {
        if (max < curVal)
        {
            answer.push(cnt);
            cnt = 1;
            return curVal;
        }
        cnt++;
        return max;
    });
    answer.push(cnt);
    return answer;
}