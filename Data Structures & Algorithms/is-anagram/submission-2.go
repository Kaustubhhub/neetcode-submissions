func isAnagram(s string, t string) bool {
	if len(s) != len(t){
		return false
	}
	freq := make([]int, 26)
	for i:=0; i<len(s); i++{
		freq[s[i] - 'a']++
		freq[t[i] - 'a']--
	}

	for i:=0; i<26; i++{
		if freq[i] != 0{
			return false
		}
	}

	return true
}
