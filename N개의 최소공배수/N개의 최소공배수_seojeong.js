function solution(arr) {
  let okFlag = false;
  for (let i = Math.max(...arr); ; i++) {
    for (let el of arr) {
      if (i % el !== 0) {
        okFlag = false;
        break;
      }
      if (i % el === 0) okFlag = true;
    }
    if (okFlag === true) return i;
  }
}
