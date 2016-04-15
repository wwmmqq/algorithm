#include <iostream>
#include <string>
#include <cmath>
#include <limits>
using std::cin; using std::cout; using std::endl;
using std::string;

//Runtime: 8 ms
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x != 0) {
        	ans = ans * 10 + x % 10;
        	x /= 10;
        	//cout << "ans: " << ans <<" a : "<< a << " x: " <<x <<endl;
        }
       	if (ans > std::numeric_limits<int>::max() || ans < std::numeric_limits<int>::min())
       		return 0;
       	//INT_MAX INT_MIN
        return ans;
    }
};


int main(int argc, char const *argv[])
{
	Solution mysolution;
	//int a = 1534236469;
	//cout << a <<endl;
	cout << mysolution.reverse(-123)<<endl;
	return 0;
}