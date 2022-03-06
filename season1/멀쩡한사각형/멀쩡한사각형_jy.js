function solution(w, h) {
  let cnt = 0;

  for (let i = 1; i <= w; i++) {
    let y1 = Math.floor(((i - 1) * h) / w);
    let y = Math.ceil((i * h) / w);
    cnt += y - y1;
  }
  return w * h - cnt;
}
