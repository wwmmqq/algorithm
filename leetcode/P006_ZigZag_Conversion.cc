#include <iostream>
#include <string>
#include <cmath>
using std::cin; using std::cout; using std::endl;
using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
    	string ans;
    	int k = 2 * (numRows - 1);
    	if (numRows < 2)
    		return s;

    	int j = 0;
    	//first line
    	j = 0;
    	while (j < s.size()) {
    		ans.push_back(s.at(j));
    		j += k;
    	}
    	// middle
    	for (int i = 1; i < numRows-1; i++) {
        	j = i;
        	if (j >= s.size())/// very important !!!!!!!!
        		break;
        	ans.push_back(s.at(j));

        	j += k;
        	while(j < s.size() or j-i*2 < s.size()) {
        		if (j-i*2 < s.size())
        			ans.push_back(s.at(j-i*2)); /// j - i*2 important!!!
        		if (j < s.size())
        			ans.push_back(s.at(j));
        		j = j + k;
        	}
        }

    	//last line
    	if (s.size() < numRows)
    		return ans;

    	j = numRows-1;
    	while (j < s.size()) {
    		ans.push_back(s.at(j));
    		j += k;
    	}

        //cout << cnt << s.size() << ans.size()<<endl;
       	return ans;
    }
};

int  main(int argc, char const *argv[])
{
	std::string test ="ABCDE";
	Solution mysolution;
	cout << mysolution.convert(test, 4) <<endl;
	return 0;
}