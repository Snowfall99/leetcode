impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let (mut p0, mut p1) = (0, s.len() as i32 - 1);
        while p0 < p1 {
            s.swap(p0 as usize, p1 as usize);
            p0 += 1;
            p1 -= 1;
        }
    }
}