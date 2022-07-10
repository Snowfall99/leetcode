func numberOfArithmeticSlices(nums []int) int {
	n := len(nums)
	if n == 1 {
		return 0
	}
	count := 0
	d, t := nums[1]-nums[0], 0
	for i := 2; i < n; i++ {
		if nums[i]-nums[i-1] == d {
			t++
		} else {
			d, t = nums[i]-nums[i-1], 0
		}
		count += t
	}
	return count
}
