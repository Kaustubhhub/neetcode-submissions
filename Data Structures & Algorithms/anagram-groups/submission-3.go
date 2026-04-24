func groupAnagrams(strs []string) [][]string {
	mpp := make(map[string][]string,0)
	result := make([][]string,0)

	for _, str := range strs{
		freq := make([]int, 26)
		temp := ""
		for _, ch := range str{
			freq[ch-'a']++
		}
		for _, f := range freq{
			temp += string(f) + ","
		} 
		
		if _, ok := mpp[temp]; ok{
			mpp[temp] = append(mpp[temp], str)
		}else{
			mpp[temp] = append(mpp[temp],str)
		}
	}

	for _ , value := range mpp {
		temp := make([]string, 0)
		for _, str := range value{
			temp = append(temp, str)
		}
		result = append(result, temp)
	}

	return result
}
