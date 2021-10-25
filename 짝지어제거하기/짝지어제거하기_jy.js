function solution(s) {
  let stk = [];
  for (let e of s) {
    if (stk[stk.length - 1] === e) stk.pop();
    else stk.push(e);
  }
  return stk.length ? 0 : 1;
}
