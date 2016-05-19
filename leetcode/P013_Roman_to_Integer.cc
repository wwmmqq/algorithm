#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

class Solution {
public:
	//Runtime: 40 ms
    int romanToInt(string s) {
        int ans = 0;
        int hash[256];
        char order[7] = {'M','D','C','L','X','V','I'};
   		hash['I'] = 1; hash['V'] = 5; hash['X'] = 10; hash['L'] = 50;
   		hash['C'] = 100; hash['D'] = 500; hash['M'] = 1000;
    	for (int i = 0; i < s.size(); i++) {
    		if( i+1 < s.size() && hash[s[i]] < hash[s[i+1]])
    			ans -= hash[s[i]];
    		else
    			ans += hash[s[i]];
    	}
    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution mysolution;
	//Input is guaranteed to be within the range from 1 to 3999. MMMCMXCIX : 3999
	cout << mysolution.romanToInt("M")<<endl;//"DCXXI" "MCMXCVI"
	return 0;
}