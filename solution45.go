func jump(nums []int) int {
	end := 0
	rightmost := 0
	step := 0
	size := len(nums)

	for i := 0; i < size-1; i++ {
		if i <= rightmost {
			if i+nums[i] > rightmost {
				rightmost = i + nums[i]
			}
			if i == end {
				end = rightmost
				step++
			}
		}
	}

	return step
}
