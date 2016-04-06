import java.util.HashMap;

// Runtime: 6 ms

public class P001_two_sum {
    public static int[] twoSum(int[] nums, int target) {
        int ans [] = {-1,-1};
        HashMap<Integer, Integer> mymap = new HashMap<Integer, Integer>();// error for int
        int i = 0;

        for (int x : nums){
        	if ( mymap.get(target - x)!= null){
        		int j = mymap.get(target - x);
        		if (i < j){
        			ans[0] = i;
        			ans[1] = j;
        		} else if(i > j) {
        			ans[0] = j;
        			ans[1] = i;
        		}
        		return ans;
        	}
        	mymap.put(x, i);
        	i++;
    	}//for
    	return ans;
    }//twoSum

    public static void main(String[]agrs){
    	int nums [] = {2, 7, 11, 15, 2};

    	int ans [] = twoSum(nums, 4);
    	System.out.println(ans[0]);
    	System.out.println(ans[1]);
	}
}