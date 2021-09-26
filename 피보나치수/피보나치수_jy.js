//시간초과
// function solution(n) {
//     function pibo(n){
//         if (n <= 1)
//             return n;
//         return pibo(n-1)%1234567 + pibo(n-2)%1234567;
//     }
//     return pibo(n)%1234567;
// }

function solution(num) {
  let arr = [0, 1];

  for (let i = 2; i <= num; i++) {
    arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567;
  }
  return arr[num];
}
