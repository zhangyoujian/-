#pragma once
#include<iostream>
#include<vector>
using namespace std;


const int coverType[4][3][2] = {
								{ {0,0}, {0,1}, {1, 0} },
								{ {0,0}, {0,1}, {1,1}  },
								{ {0,0}, {1,0},  {1,1} },
								{ {0,0}, {1,-1}, {1,0} }
								};

bool set(vector<vector<int>>&board, int x,int y,int type, int delta)
{
	bool ok=true;
	for (int i = 0;i < 3;++i)
	{
		int nx = x + coverType[type][i][0];
		int ny = y + coverType[type][i][1];
		
		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
			ok = false;

		else if (board[nx][ny] += delta > 1)
			ok = false;
	}

	return ok;
}

int conver(vector<vector<int>>&board)
{
	int ret = 0;
	int delat = -1;
	int x=-1, y=-1;
	for(int i = 0;i<board.size();++i)
		for (int j = 0;j < board[i].size();++j)
		{
			if (board[i][j] == 0)
			{
				x = i;
				y = j;
				break;
			}
		}

	if (x == -1 || y == -1)
		return 1;

	for (int i = 0;i < 4;i++)
	{
		if (set(board, x, y, i, 1))
			ret += conver(board);
		set(board, x, y, i, -1);
	}


	return ret;
}
