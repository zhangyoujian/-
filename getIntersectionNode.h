#pragma once
#include<iostream>
using namespace std;
 
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* PA = headA;
	ListNode* PB = headB;
	int LA = 0;
	int LB = 0;
	while (PA)
	{
		LA++;
		PA = PA->next;
	}
	while (PB)
	{
		LB++;
		PB = PB->next;
	}
	PA = headA;
	PB = headB;
	
	int L = LA - LB;
	if (L > 0)
	{
		for (int i = 0;i < L;++i)
			PA = PA->next;
	}
	else {
		for (int i = 0;i < -L;++i)
			PB = PB->next;
	}

	while(PA!=PB)
	{
		PA = PA->next;
		PB = PB->next;
	}
	
	return PA;
}

