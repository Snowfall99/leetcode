impl Solution {
    pub fn calculate(s: String) -> i32 {
        let mut st = Vec::new();
        let mut num: i32 = 0;
        let mut operator = '+';
        for c in (s+".").chars() {
            if c == ' ' {
                continue;
            }
            if c >= '0' && c <= '9' {
                num = num * 10 + (c as u8 - b'0') as i32;
            } else {
                match operator {
                    '+' => st.push(num),
                    '-' => st.push(-num),
                    '*' => *st.last_mut().unwrap() *= num,
                    '/' => *st.last_mut().unwrap() /= num,
                    _ => {},
                }
                operator = c;
                num = 0;
            }
        }
        st.iter().sum()
    }
}
