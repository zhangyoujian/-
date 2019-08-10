#pragma once
#include<iostream>
#include<map>
#include<list>
using namespace std;

class LRUCache {
	list<pair<int, int>> q;
	map<int, list<pair<int, int>>::iterator> cache;
	int m_capcity;

public:
	LRUCache(int capacity) {
		m_capcity = capacity;
	}
	int get(int key) {
		if (cache.count(key))
		{
			auto iter = cache[key];
			int value = (*iter).second;
			q.erase(iter);
			q.emplace_back(make_pair(key, value));
			cache[key] = std::prev(q.end());
			return value;
		}
		return -1;
	}

	void put(int key, int value) {
		if (cache.count(key))
		{
			auto iter = cache[key];
			q.erase(iter);
			q.emplace_back(make_pair(key, value));
			cache[key] = std::prev(q.end());
		}
		else
		{
			if (cache.size() < m_capcity)
			{
				q.emplace_back(make_pair(key, value));
				cache[key] = std::prev(q.end());
			}
			else
			{
				auto iter = q.begin();
				int Recentkey = (*iter).first;
				q.erase(iter);
				cache.erase(Recentkey);
				q.emplace_back(make_pair(key, value));
				cache[key] = std::prev(q.end());
			}
		}
	}
};
