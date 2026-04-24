func hasDuplicate(nums []int) bool {
    mpp := make(map[int]int)

    for i := range nums{
        if _, ok := mpp[nums[i]]; ok{
            return true
        }
        mpp[nums[i]]++
    }
    return false
}
