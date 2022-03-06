function solution(progresses, speeds) {
  let days = [];
  let stack = [];
  let ret = [];
  for (let i = 0; i < progresses.length; i++) {
    days[i] = Math.ceil((100 - progresses[i]) / speeds[i]);
  }
  // console.log(days);
  for (let i = 0; i < days.length; i++) {
    if (stack[0] < days[i]) {
      ret.push(stack.length);
      stack = [];
    }
    stack.push(days[i]);
  }
  ret.push(stack.length);
  return ret;
}
