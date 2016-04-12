#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//O(n) Runtime: 60 ms
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int ASCII[128] = {0};
        std::memset(ASCII, 0, sizeof ASCII);
        int max = 0;
        int index = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
        	int j = i;
        	int cnt = 0;
        	while(j < len and ASCII[int(s.at(j))] != 1) {
        		ASCII[int(s.at(j))] = 1;
        		cnt++;
        		j++;

        	}
        	std::memset(ASCII, 0, sizeof ASCII);
        	max =  cnt > max ? cnt : max;
        	cnt = 0;
            if (j == len-1)
                return max;
        }
        return max;
    }
};

// O(n) Runtime: 16 ms
class Solution2 {  
public: 
    int lengthOfLongestSubstring(string s) {  
        int last[256];//保存字符上一次出现的位置
        std::memset(last, -1, sizeof(last));  
        
        int idx = -1, max = 0;//idx为当前子串的开始位置-1  
        for (int i = 0; i < s.size(); i++)  
        {  
            if (last[s[i]] > idx)//如果当前字符出现过，那么当前子串的起始位置为这个字符上一次出现的位置+1  
            {  
                idx = last[s[i]];  
            }
  
            if (i - idx > max)//这里是关键！！！！！！！！！  
            {
                max = i - idx;  
            }  
  
            last[s[i]] = i;  
        }  
        return max;  
    }  
};

// O(n) Runtime: 16 ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128] = {-1};
        std::memset(last, -1, sizeof(last));
        int index = 0;
        int max = 0;

        // error: aabbaa
        for (int i = 0; i < s.size(); i++) {
            if (last[int(s.at(i))] >= index) { // error : -1 -> index
                //cout << "occor at: "<<int(s.at(i))<<endl;
                index = last[int(s.at(i))] + 1; // error: remove +1
                //cout << "index: "<< index <<endl;
            }

            if (i - index + 1 > max) {
                max = i - index + 1;
            }

            last[int(s.at(i))] = i;
           // cout << "max: " << max <<endl;
        }
        return max;
    }
};

int main()  
{
    string str = "aabbaa"; 
    Solution mysolution;  
    cout<<mysolution.lengthOfLongestSubstring(str)<<endl;  
  
}