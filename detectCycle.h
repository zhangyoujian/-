#pragma once
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode *detectCycle(ListNode *head) {

	if (head == NULL || head->next == NULL)
		return NULL;

	ListNode *slowNode = NULL;
	ListNode *FastNode = NULL;
	
	slowNode = head;
	FastNode = head;

	while (FastNode!=NULL &&(FastNode->next!=NULL))
	{
		slowNode = slowNode->next;
		FastNode = FastNode->next->next;
		if (FastNode == slowNode)
		{
			slowNode = head;
			while (slowNode != FastNode)
			{
				slowNode = slowNode->next;
				FastNode = FastNode->next;

			}
			return slowNode;
		}
	}

	return NULL;
}



