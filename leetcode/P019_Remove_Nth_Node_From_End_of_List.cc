#include <iostream>

using std::cout; using std::cin; using std::endl;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution0 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* p0 = head;
        ListNode* pn = head;

        while(--n) {
        	pn = pn->next;
        }

        if(pn->next) {
        	p = p->next;
        	pn = pn->next;
        }

        while(pn->next) {
        	p = p->next;
        	p0 = p0->next;
        	pn = pn->next;
        }

        if (p == head && pn == head)
        	head = NULL;

        if(p->next == NULL) {
        	p0->next = NULL;
        	delete p;
        } else {
        	p->val = p->next->val;
        	ListNode* t = p->next;
        	p->next = t->next;
        	delete t;
        }
        return head;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode prehead(0);
    	prehead.next = head;

        ListNode* p = &prehead;
        ListNode* pn = &prehead;

        while (n-- && pn)
            pn = pn->next;

        while (pn->next) {
            p = p->next;
            pn = pn->next;
        }

//        if(p == &prehead)
//        	prehead.next = NULL;
// why ? run time error? add up codes

        ListNode* t = p->next;
        p->next = p->next->next;
        delete t;

        return prehead.next;
    }
};