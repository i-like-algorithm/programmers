function solution(citations) {
  let cit_sort = citations.sort((a, b) => b - a);
  for (let i = cit_sort.length; i > -1; i--) {
    let cit_rest = cit_sort.filter((e) => e >= i);
    if (i <= cit_rest.length) return i;
  }
}
