/*
 A palindrome is a string which reads the same in both directions. For example, ’abba‘is a palindome,‘abc’is not.
 */
#include <iostream>
#include <string>
#include <cmath>
using std::cout; using std::cin; using std::endl;
using std::string;

//Runtime: 60 ms O(n*n)
class Solution {
public:
	string longestPalindrome(string s) {
		int L = 0;
		int R = 0;
		int max = 0;
		int ii;
		for (int i = 0; i < s.size(); i++) {
			int c1 = center(s, i-1, i+1);
			int c2 = center(s, i, i+1);
			int maxc = c1 > c2 ? c1 : c2;
			if (maxc > max) {
				max = maxc;
				if ( max%2 == 1 ) {
					L = i - floor(max/2);
					R = i + floor(max/2);
				} else {
					L = i - floor(max/2) + 1;
					R = i + floor(max/2);
				}
				ii = i;
			}
			
		}
		//cout << L << " "<< R+1 <<endl;
		//cout << s <<endl;
		//return s.substr(L, R + 1); //bug for string("abcbe")
		string ans;
		for (int i = L ; i <= R; i++)
			ans.push_back(s.at(i));
		return ans;
	}

	int center(const string &s, int left, int right) {
		int l = left;
		int r = right;
		while(l >= 0 && r < s.size() && s.at(l) == s.at(r)) {
			l--;
			r++;
		}
		return r-l-1;
	}
};

int main()
{
	std::string test = "aba";
	Solution mysolution;
	//cout << test.substr(0,2)<<endl;
	cout << mysolution.longestPalindrome(test) <<endl;
}