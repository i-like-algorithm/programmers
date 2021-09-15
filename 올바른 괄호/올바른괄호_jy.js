function solution(s) {
  let stk = [],
    s_arr = s.split("");
  for (let e of s) {
    let stkEl = stk[stk.length - 1];
    //index값에 음수 들어가도 err안나네? 개꿀
    if (stkEl === "(" && e === ")") stk.pop();
    else stk.push(e);
  }
  return stk.length ? false : true;
}

// function solution(s){
//     let stk = [],
//         s_arr = s.split('');
//     for (let e of s){
//         if (stk.length===0)
//             stk.push(e);
//         else{
//             let stkEl = stk.pop();
//             if(stkEl === "(" && e === ")");
//             else{
//                 stk.push(stkEl);
//                 stk.push(e);
//             }
//         }
//     }
//     return stk.length ? false : true;
// }
