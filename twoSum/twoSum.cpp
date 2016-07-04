vector<int> twoSum(vector<int>& nums, int target) {
	for (int i = 0; i < int(nums.size()) - 1; i++)
        	for(int j = i + 1; j < int(nums.size()); j++ )
        	{
        		if (nums[i] + nums[j] == target)
        			return {i,j};
        	}
    cout << "Can't find the target!" << endl;
    return {0};        
}