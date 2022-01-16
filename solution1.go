func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, num := range nums {
		p, ok := m[target-num]
		if ok {
			return []int{p, i}
		}
		m[num] = i
	}
	return []int{}
}
