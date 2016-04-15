//P009_Palindrome_Number.cc

#include <iostream>
#include <string>
using std::endl; using std::cin; using std::cout;
using std::string;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        	return false;
        string sx = std::to_string(x);
        int indx = 0;
        indx = sx.size()/2;
        int left,right;

        if (sx.size() %2 == 1){
        	left = sx.size()/2 - 1;
        	right = left + 2;
        }  else{
        	left = sx.size()/2 - 1;
        	right = left + 1;
        }
        while(left > -1 && right < sx.size()) {
        	if(sx[left] != sx[right])
        		return false;
        	left--;
        	right++;
        }
 		return true; 	
    }
};


int main(int argc, char const *argv[])
{
	Solution mysolution;
	cout << mysolution.isPalindrome(-122321) <<endl;
	return 0;
}