function solution(numbers) {
  let num_arr = numbers.split("");
  let all_num = [];
  let answer = 0;
  function dfs(num_arr, size) {
    let tot_list = [];
    if (size === 1) tot_list.push(...num_arr);
    else {
      num_arr.forEach((e, idx) => {
        let rest_arr = num_arr.filter((_, i) => i !== idx);
        let sub_arr = dfs(rest_arr, size - 1);
        sub_arr.forEach((ee) => {
          tot_list.push(e + ee);
        });
      });
    }
    return tot_list;
  }
  for (let i = 1; i <= num_arr.length; i++) all_num.push(...dfs(num_arr, i));
  all_num = [...new Set(all_num.map((e) => +e))];
  all_num.forEach((e) => {
    let cnt = 2;
    while (cnt < e) {
      if (e % cnt === 0) break;
      cnt++;
    }
    if (cnt === e) answer++;
  });
  return answer;
}
