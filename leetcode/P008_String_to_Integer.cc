#include <iostream>
#include <cmath>
#include <limits>
#include <cctype>

using std::cin; using std::cout; using std::endl;
using std::string;

//Runtime: 12 ms
class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        int len = str.size();
        int i = 0;
        if (len == 0)
        	return 0;

        int cnt_flag = 0;
        bool fu = 0;
        while(i < len && (str.at(i) == '+'|| str.at(i) == '-' || str.at(i) == ' ')) {
        	if (str.at(i) == '+'){
        		cnt_flag++;
        		if (i+1 < len && str.at(i+1) == ' ')
        			return ans;
        	}
        	if (str.at(i) == '-'){
        		cnt_flag++;
        		fu=true;
        		if (i+1 < len && str.at(i+1) == ' ')
        			return ans;
        	}
        	i++;
        }
        if (cnt_flag > 1)
        	return ans;

        while(i < len) {
        	int t = int(str.at(i) - '0');
        	if ( t > -1 and t < 10  ) {
        		ans = t + ans * 10;
        		i++;
        	} else {
        		break;
        	}
        	if (ans > INT_MAX and !fu) {
        		return INT_MAX;
        	} else if(fu and -ans < INT_MIN){
        		return INT_MIN;
        	}
        }
        if (fu)
        	ans = -ans;
        return ans;
    }
};


int main(int argc, char const *argv[])
{
	Solution mysolution;
	//"    -00134"
	//"-   010"
	//"  -0012a42"
	//" -a"
	//"2147483648"
	//"   - 321"
	// "-+1"
	// "9223372036854775809"
	string test = "9223372036854775809";
	//cout << std::stoi(test) <<endl;
	cout << mysolution.myAtoi(test) <<endl;
	return 0;
}