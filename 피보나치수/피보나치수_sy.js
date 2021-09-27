function solution(n) {
  //BigInt형 사용
  let n0 = 0n; //F(n)
  let n1 = 1n; //F(n-1)
  let n2 = 0n; //F(n-2)

  for (let i = 2; i <= n; i++) {
    n0 = n1 + n2;
    if (i === n) return n0 % 1234567n;
    n2 = n1;
    n1 = n0;
  }
}
