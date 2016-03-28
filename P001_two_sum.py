# Runtime: 824 ms

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]

        """
        i = 0
        for x in nums:
        	anoter = target - x
        	if anoter in nums:
        		j = nums.index(anoter)
        		if i < j:
        			return i,j
        		elif i > j:
        			return j,i
        	i = i + 1


### test

one = Solution()
nums = [3,4,3]
target = 6
print one.twoSum(nums, target)

