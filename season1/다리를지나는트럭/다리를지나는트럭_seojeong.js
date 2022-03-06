function solution(bridge_length, weight, truck_weights) {
  let answer = 0;
  let on_bridge = Array(bridge_length).fill(0);
  let tot_weight = 0;

  while (truck_weights.length || tot_weight) {
    if (
      truck_weights[0] &&
      tot_weight - on_bridge[0] + truck_weights[0] <= weight
    ) {
      on_bridge.shift();
      on_bridge.push(truck_weights[0]);
      truck_weights.shift();
    } else {
      on_bridge.shift();
      on_bridge.push(0);
    }
    tot_weight = on_bridge.reduce((sum, curr) => sum + curr);
    answer++;
    console.log(`on_bridge = ${on_bridge} truck_weights= ${truck_weights}`);
  }
  return answer;
}
