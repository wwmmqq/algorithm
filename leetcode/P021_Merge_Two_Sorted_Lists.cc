#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::cout; using std::cin; using std::endl;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr)
        	return l2;
        if (l2 == nullptr)
        	return l1;

        ListNode* head = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p = head;

        while(p1 && p2) {
        	if (p1->val < p2->val) {
        		p->next = p1;
        		p1 = p1->next;
        	} else {
        		p->next = p2;
        		p2 = p2->next;
        	}
        	p = p->next;
        }

        if (p1)
        	p->next = p1;

        if (p2)
        	p->next = p2;

        return head->next;
    }
};