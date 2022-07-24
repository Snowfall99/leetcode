impl Solution {
  pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
      if start > destination {
          return Solution::distance_between_bus_stops(distance,  destination, start)
      }
      let start = start as usize;
      let end = destination as usize;
      let a= (&distance[start..end]).iter().sum::<i32>();
      let b = (&distance[0..start]).iter().sum::<i32>() + (&distance[end..distance.len()]).iter().sum::<i32>();
      a.min(b)
  }
}
