#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
//Runtime: 40 ms
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* head = new ListNode(0);
    	ListNode* cur = head;
        int a = 0;
        int b = 0;
        while(l1 || l2) {
        	if (l1 && l2) {
        		int t = l1->val + l2->val + b;
        		a = t%10;
        		b = t/10;
        		l1 = l1->next;
        		l2 = l2->next;
        	}else if (l1 == NULL) {
        		int t = l2->val + b;
        		a = t%10;
        		b = t/10;
        		l2 = l2->next;
        	}else if (l2 == NULL) {
        		int t = l1->val + b;
        		a = t%10;
        		b = t/10;
        		l1 = l1->next;
        	}
        	cur->next = new ListNode(a);
        	cur = cur->next;
        }
        if (b){
        	cur->next = new ListNode(b);
        }

        return head->next;
    }
};
