struct MyQueue {
    st1: Vec<i32>,
    st2: Vec<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    fn new() -> Self {
        Self {
            st1: Vec::new(),
            st2: Vec::new(),
        }
    }
    
    fn push(&mut self, x: i32) {
        self.st1.push(x);
    }
    
    fn pop(&mut self) -> i32 {
        if self.st2.is_empty() {
            while let Some(val) = self.st1.pop() {
                self.st2.push(val);
            }
        }
        self.st2.pop().unwrap()
    }
    
    fn peek(&mut self) -> i32 {
        if self.st2.is_empty() {
            while let Some(val) = self.st1.pop() {
                self.st2.push(val);
            }
        }
        *self.st2.last().unwrap()
    }
    
    fn empty(&self) -> bool {
        self.st1.is_empty() && self.st2.is_empty()
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */