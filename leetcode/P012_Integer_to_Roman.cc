#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values{1000, 900,500,400, 100, 90, 50, 40,  10,  9,  5,   4,   1};
        vector<string> strs{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans;
        for(int i = 0; i < values.size(); ++i) {
        	int cnt = num / values[i];
        	num %= values[i];
        	while(cnt--)
        		ans.append(strs[i]);
        }
        return ans;
    }
};

int main()
{
	//Input is guaranteed to be within the range from 1 to 3999.
	Solution mysolution;
	cout << mysolution.intToRoman(3999) << endl;
}