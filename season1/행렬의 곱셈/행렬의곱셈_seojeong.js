function solution(arr1, arr2) {
  let ans = [];

  for (let row = 0; row < arr1.length; row++) {
    ans.push([]);
    for (let col = 0; col < arr2[0].length; col++) {
      ans[row][col] = 0;
      for (let i = 0; i < arr2.length; i++) {
        ans[row][col] += arr1[row][i] * arr2[i][col];
      }
    }
  }
  return ans;
}
