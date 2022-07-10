func longestPalindrome(s string) string {
	size := len(s)
	if size < 2 {
		return s
	}
	maxLen := 1
	begin := 0
	dp := make([][]bool, size)
	for i := 0; i < size; i++ {
		dp[i] = make([]bool, size)
		dp[i][i] = true
	}
	for L := 2; L <= size; L++ {
		for i := 0; i < size; i++ {
			j := L + i - 1
			if j >= size {
				continue
			}
			if s[i] != s[j] {
				dp[i][j] = false
			} else {
				if j-i < 3 {
					dp[i][j] = true
				} else {
					dp[i][j] = dp[i+1][j-1]
				}
			}
			if dp[i][j] && j-i+1 > maxLen {
				maxLen = j - i + 1
				begin = i
			}
		}
	}
	return s[begin : begin+maxLen]
}
