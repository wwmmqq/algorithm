#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::unordered_map;

// Runtime: 16 ms

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
    	int i = 0;
    	for (int x : nums) {
    		auto t = mymap.find(target - x);
    		if (t != mymap.end()) {
    			int j = t->second;
    			if(i < j)
    				return vector<int>{i,j};
    			else
    				return vector<int>{j,i};
    		}
    		mymap[x] = i;
    		i++;
    	}

    	return vector<int>{-1,-1};
    }
};

int main()
{
	vector<int> nums{2, 7, 11, 15, 2};
	int target = 4;
	Solution mysolution;
	for (auto x : mysolution.twoSum(nums, target))
		cout << x <<endl;
}