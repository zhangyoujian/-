#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;
#define INF ~(1<<31)
#define MAXCITYNUM 20


long hasPath(vector<int>&path,int dist[], bool visited[], int N, long curlength, stack<int>&saveedPath)
{
	if (path.size() == N)
	{
		return curlength;
	}

	long ret = INF;
	long cnd = INF;
	int selr = -1;
	for (int next = 0; next< N;++next)
	{
		int pre = path.back();

		if (visited[next] || dist[pre*MAXCITYNUM + next] == INF)
			continue;
		
		visited[next] = true;
		path.push_back(next);
		cnd = hasPath(path, dist, visited, N, curlength + dist[pre*MAXCITYNUM + next], saveedPath);
		if (cnd < ret)
		{
			ret = cnd;
			selr = next;
		}
		visited[next] = false;
		path.pop_back();
	}

	if (selr != -1)
		saveedPath.push(selr);
	return ret;
}


long travePath(vector<vector<int>>&route, int N)
{
	int dist[MAXCITYNUM*MAXCITYNUM];
	std::fill(dist, dist + MAXCITYNUM*MAXCITYNUM, INF);
	
	for (auto i = 0;i < route.size();++i)
	{
		dist[route[i][0] * MAXCITYNUM + route[i][1]] = route[i][2];
		dist[route[i][1] * MAXCITYNUM + route[i][0]] = route[i][2];
	}

	bool Visited[MAXCITYNUM];
	std::fill(Visited, Visited + MAXCITYNUM, false);

	long ret = INF;
	long cnd = INF;
	vector<int>path;
	stack<int>saveedPath;
	int selRoue = -1;
	for (int i = 0;i < N;++i)
	{
		Visited[i] = true;
		path.push_back(i);
		cnd = hasPath(path, dist,Visited, N, 0, saveedPath);
		if (cnd < ret)
		{
			ret = cnd;
			selRoue = i;
		}
		Visited[i] = false;
		path.pop_back();
	}
	if (selRoue != -1)
		saveedPath.push(selRoue);

	cout << "最短路线" << endl;
	while (!saveedPath.empty())
	{
		cout << saveedPath.top() << " ";
		saveedPath.pop();
    }
	   
	return ret;
}



int main()
{

	int N, M;
	cin >> N >> M;
	vector<vector<int>> route(N);
	for (int i = 0;i < M;++i)
	{
		vector<int>temp(M);
		cin >> temp[0] >> temp[1] >> temp[2];
		route[i] = temp;
	}

	long ret = travePath(route, N);
	cout << "最短距离:" << ret << endl;

	system("pause");
	return 0;
}