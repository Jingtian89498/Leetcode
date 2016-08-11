class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        long mid; // 需要注意mid * mid 会造成溢出
        while( (right - left) != 1 )
        {
            mid = (left + right) / 2;
        	if (mid * mid == x)
	        	return mid;
        	else if (mid * mid > x)
        		right = mid;
        	else
        		left = mid;
        }
        if (right * right == x)
            return right;
        else
            return left;
    }
};