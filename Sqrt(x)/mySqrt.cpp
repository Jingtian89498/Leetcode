class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        long mid; // ��Ҫע��mid * mid ��������
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