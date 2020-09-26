class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if(n < 3) {
        	return 0;
        }
        /*
        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        for(int i = 1;i<n;i++) {
        	left[i] = max(left[i-1],height[i]);
        }

        right[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--) {
        	right[i] = max(right[i+1],height[i]);
        }

        int ans = 0;
        for(int i = 0;i<n;i++) {
        	ans = ans + min(right[i],left[i]) - height[i];
        }

        return ans;
        */

        int leftMax = 0;
        int rightMax = 0;

        int left = 0;
        int right = n - 1;
        int ans = 0;

        while(left < right) {
        	if(height[left] <= height[right]) {
        		if(height[left] >= leftMax) {
        			leftMax = height[left];
        		} else {
        			ans += (leftMax-height[left]);
        		}
        		left++;
        	} else {
        		if(height[right] >= rightMax) {
        			rightMax = height[right];
        		} else {
        			ans += (rightMax - height[right]);
        		}

        		right--;
        	}
        }

        return ans;
    }
};