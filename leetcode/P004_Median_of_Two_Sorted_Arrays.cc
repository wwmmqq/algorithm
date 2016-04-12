#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Runtime: 48 ms
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> temp;
        int len = nums1.size() + nums2.size();
        if(0 == nums1.size()) {
	        if (len%2 == 0)
				return (nums2.at(len/2) + nums2.at(len/2 -1))/2.0;
			else
				return nums2.at(len/2);
        }

        if (0 == nums2.size()) {
        	if (len%2 == 0){
        		//cout << nums1.at(len/2) + nums1.at(len/2 -1) <<endl;
				return (nums1.at(len/2) + nums1.at(len/2 -1))/2.0;
        	}
			else
				return nums1.at(len/2);
        }

        int i = 0; 
        int j = 0;
        while(i < nums1.size() || j < nums2.size()) {
        	if (i >= nums1.size()) {
        		temp.push_back(nums2[j]);
        		j++;

        	} else if(j >= nums2.size()) {
        		temp.push_back(nums1[i]);
        		i++;

        	} else if(nums1[i] < nums2[j]) {
        		temp.push_back(nums1[i]);
        		i++;

        	} else {
        		temp.push_back(nums2[j]);
        		j++;
        	}
        }

        if (len%2 == 0)
			return (temp.at(len/2) + temp.at(len/2 -1))/2.0;
		else
			return temp.at(len/2);
    }
};

int main()
{
	std::vector<int> v1{1};
	std::vector<int> v2{1};
	Solution mysolution;  
	cout<<mysolution.findMedianSortedArrays(v1, v2)<<endl;
}