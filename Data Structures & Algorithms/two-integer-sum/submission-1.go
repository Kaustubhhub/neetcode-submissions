func twoSum(nums []int, target int) []int {
    mpp := make(map[int]int)

	for i := range nums{
		if v,ok := mpp[target - nums[i]]; ok{
			return []int{v,i}
		}
		mpp[nums[i]] = i
	}

	return nil
}
