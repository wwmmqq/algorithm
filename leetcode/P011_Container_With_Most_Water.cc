#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::vector;

class Solution {
public:
	// time out O(n^2)
    int maxArea_0(vector<int>& height) {
    	int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
        	for(int j = i + 1; j < height.size(); ++j) {
        		int h_min = height[i] < height[j] ? height[i] : height[j];
        		int s = h_min * (j - i);
        		if (s > ans)
        			ans = s;
        	}
        }
        return ans;
    }

    //Runtime: 24 ms O(n)
    int maxArea_1(vector<int>& height) {
    	int left = 0;
    	int right = height.size() - 1;
    	int ans = 0;
    	while(left < right) {
    		int h_min = height[left] < height[right] ? height[left] : height[right];
    		int s = (right - left) * h_min;
    		if (s > ans) {
    			ans = s;
    		}

    		if(height[left] < height[right])
    			left++;
    		else
    			right++;
    	}
    	return ans;
    }

    //Runtime: 24 ms O(n)
    int maxArea(vector<int>& height) {
    	int left = 0;
    	int right = height.size() - 1;
    	int ans = 0;

    	while(left < right) {
    		int h_min = height[left] < height[right] ? height[left] : height[right];
    		int s = (right - left) * h_min;
    		if (ans < s)
    			ans = s;
    		if(height[left] < height[right]) {
    			int k;
    			for (k=left+1; k < right && height[k]<=height[left]; ++k){}
    			left = k;
    		}else{
    			int k;
    			for (k = right -1; k > left && height[k] <= height[right]; k--){}
    			right = k;
    		}
    	}
    	return ans;
    }
};

int main()
{
	vector<int> v{9,1,2,5,10};
	Solution mysolution;
	cout << mysolution.maxArea(v) << endl;
}