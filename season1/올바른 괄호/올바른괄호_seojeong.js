function solution(s){
    // 스택 사용 ( "(" 이면 스택에 넣고 -> ")" 를 만나면 pop )
    let stk = [];
    let count = 0;
    for (let i = 0; i < s.length; i++){
        if (s[i] === '(') {
            stk.push(s[i]);
            count++;
        }
        else
            if (stk.length) stk.pop();
            else return (false);
    }
    if (stk.length === 0 && count !== 0) return (true);
    else return (false);
}
