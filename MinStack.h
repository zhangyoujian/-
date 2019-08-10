#pragma once
#include<iostream>
using namespace std;
#include<stack>

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		buffer.push(x);
		if (minData.empty() || x <= minData.top())
			minData.push(x);
	}

	void pop() {
		if (!buffer.empty())
		{
			if (minData.top() == buffer.top())
				minData.pop();

			buffer.pop();
		}
			

	}

	int top() {
		return buffer.top();
	}

	int getMin() {
		return minData.top();
	}
private:
	stack<int> buffer;
	stack<int> minData;
};


