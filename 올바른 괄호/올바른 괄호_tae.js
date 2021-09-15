function solution(s){
    
    let 왼쪽괄호개수 = 0,
        arrayS = [...s];
    
    if (s[s.length - 1] == '(') return false; //"()()("
    
    for (let i = 0; i < s.length; i++)
    {
        if (s[i] == '(') 왼쪽괄호개수 += 1;
        else if (s[i] == ')' && 왼쪽괄호개수 == 0) return false; //")()", "()())"
        else if (s[i] == ')') 왼쪽괄호개수 -= 1;
    }
    return 왼쪽괄호개수 == 0 ? true : false 
    
}