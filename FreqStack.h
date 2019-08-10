#pragma once
#include<iostream>
#include<stack>
#include<map>
using namespace std;

class FreqStack {

public:
	FreqStack():maxFreq(0){}
	~FreqStack();
	void push(int x);
	int pop();
private:
	map<int, int> counter;
	map<int,stack<int>*>orderGroup;
	int maxFreq;
};


void FreqStack::push(int x)
{
	int f=0;
	if (counter.count(x)!=0)
	{
		f = counter[x];
	}
	f += 1;

	counter[x] = f;
	if (f > maxFreq)
		maxFreq = f;
	if (orderGroup.count(f))
	{
		orderGroup[f]->push(x);
	}
	else
	{
		stack<int> *q = new stack<int>;
		q->push(x);
		orderGroup[f] = q;
	}

}

int FreqStack::pop()
{
	int x = orderGroup[maxFreq]->top();
	orderGroup[maxFreq]->pop();

	counter[x]--;
	if (counter[x]==0)
		counter.erase(x);

	if (orderGroup[maxFreq]->size() == 0)
	{
		stack<int> *temp = orderGroup[maxFreq];
		delete temp;
		maxFreq--;
	}
	return x;
}

FreqStack::~FreqStack()
{
	while (maxFreq > 0)
	{
		this->pop();
	}
}