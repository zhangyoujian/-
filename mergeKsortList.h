#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0) {
		return NULL;
	}
	if (lists.size() == 1) {
		return lists.front();
	}
	map<int, ListNode*> hmTotalNums;
	for (int i = 0; i < lists.size(); i++) {
		ListNode* temp = lists.at(i);
		while (temp != NULL) {
			ListNode* nextNode = temp->next;
			temp->next = NULL;
			if (hmTotalNums.count(temp->val)) {
				temp->next = hmTotalNums[temp->val];
				hmTotalNums[temp->val] = temp;
			}
			else
				hmTotalNums[temp->val] = temp;
			temp = nextNode;
		}
	}
	if (hmTotalNums.size() == 0)
		return NULL;
	auto iter = hmTotalNums.begin();
	while (iter != hmTotalNums.end()) {
		ListNode* temp = iter->second;
		while (temp->next != NULL)
			temp = temp->next;
		iter++;
		if (iter != hmTotalNums.end())
			temp->next = iter->second;
	}
	return hmTotalNums.begin()->second;
}

