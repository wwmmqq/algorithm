#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size() > 0)
            ans = strs[0];
        else
            return "";

        int k = ans.size();
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            int minlen = ans.size() < strs[i].size() ? ans.size() : strs[i].size();
            while(j < minlen && ans[j] == strs[i][j]) {
                j++;
            }
            k =  k < j ? k : j;
        }
        return ans.substr(0, k);
    }
};

class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size() > 0)
            ans = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int k = 0;
            int minlen = ans.size() < strs[i].size() ? ans.size() : strs[i].size();
            while(k < minlen && ans[k] == strs[i][k]) {
                k++;
            }
            ans = ans.substr(0, k);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution mysolution;
	vector<string> strs{"123", "12", "111"};
	cout << mysolution.longestCommonPrefix(strs)<<endl;
	return 0;
}