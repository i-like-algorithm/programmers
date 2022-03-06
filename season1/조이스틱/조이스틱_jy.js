function solution(name) {
  let answer = 0;
  let aName = name
    .split("")
    .map((e) =>
      Math.min(
        e.charCodeAt(0) - "A".charCodeAt(0),
        "Z".charCodeAt(0) - e.charCodeAt(0) + 1
      )
    );
  let now_idx = 0;
  let next_idx = 0;
  while (1) {
    if (Math.max(...aName)) {
      next_idx = findDistance(aName, now_idx);
      answer += Math.abs(next_idx);
      if (now_idx + next_idx < 0) now_idx = now_idx + next_idx + aName.length;
      else if (now_idx + next_idx >= aName.length)
        now_idx = now_idx + next_idx - aName.length;
      else now_idx = now_idx + next_idx;
      answer += aName[now_idx];
      aName[now_idx] = 0;
    } else break;
  }
  return answer;
}

function findDistance(aName, now_idx) {
  let right = 0,
    left = 0;
  while (1) {
    if (
      now_idx + right >= aName.length &&
      aName[now_idx + right - aName.length]
    ) {
      break;
    }
    if (aName[now_idx + right]) break;
    right++;
  }
  while (1) {
    if (now_idx + left < 0 && aName[now_idx + left + aName.length]) break;
    if (aName[now_idx + left]) break;
    left--;
  }
  return left * -1 >= right ? right : left;
}
