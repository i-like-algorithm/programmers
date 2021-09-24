function solution(s) {
    return Math.min(...(s.split(' ').map(x => +x)))+ " " + Math.max(...(s.split(' ').map(x => +x)))
}