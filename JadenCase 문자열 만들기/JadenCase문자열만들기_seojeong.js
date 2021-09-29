function solution(s) {
  return s.toLowerCase().replace(/(^|\s)[a-z]/g, (x) => x.toUpperCase());
}
