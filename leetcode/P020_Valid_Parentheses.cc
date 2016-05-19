#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::cout; using std::cin; using std::endl;

//'(', ')', '{', '}', '[' and ']'

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> c;
        for(auto x: s) {
        	if(x == '(' | x == '{' | x == '['){
        		c.push(x);
        	} else {
        		if(c.empty())
        			return false;
        		char t = c.top();
        		if (x == ')' && t != '(')
        			return false;
        		if (x == '}' && t != '{')
        			return false;
        		if (x == ']' && t != '[')
        			return false;

        		c.pop();
        	}
        }
        if (!c.empty())
        	return false;
        return true;
    }
};


int main(int argc, char const *argv[])
{
	Solution mysolution;
	cout << mysolution.isValid("}") << endl;
	return 0;
}