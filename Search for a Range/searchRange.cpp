vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i;
        vector<int> result = {-1, -1};
        for (i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                result[0] = i;
                result[1] = i;
                break;
            }
        }
        for (i = i + 1; i < n; i++)
        {
            if (nums[i] == target)
                result[1]++;
            else
                break;
        }
        return result;
    }