function solution(priorities, location) {
  let printOrder = [];
  let finalLoc = [];
  let printStack = priorities.slice(); // priorities의 복사본
  let locations = Array.from({ length: priorities.length }, (v, i) => i); // index로 배열 한번에 초기화
  // console.log(locations);

  while (printStack[0]) {
    // printStack에 요소 있는 동안 반복
    let e = printStack.splice(0, 1)[0]; // e = printStack의 0번째 요소 제거
    let l = locations.splice(0, 1)[0];

    if (printStack.find((element) => element > e)) {
      // printStack에 e보다 큰 값이 있을 때
      printStack.push(e); // 제거한 e를 다시 끝에 붙여줌
      locations.push(l);
    } else {
      // e보다 큰 값이 없을 때 printOrder의 끝에 붙여줌
      printOrder.push(e);
      finalLoc.push(l);
    }
    // console.log(`printOrder = ${printOrder}, printStack = ${printStack}`);
    // console.log(`locations = ${locations}, finalLoc = ${finalLoc}`);
  }
  return finalLoc.indexOf(location) + 1;
}
