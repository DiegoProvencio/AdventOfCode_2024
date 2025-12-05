#include <bits/stdc++.h>
using namespace std;

const vector<vector<char>> NUM_PAD =
	{
		{'#','#','#','#','#'},
		{'#','7','8','9','#'},
		{'#','4','5','6','#'},
		{'#','1','2','3','#'},
		{'#','#','0','A','#'},
		{'#','#','#','#','#'}
	};
	
const vector<vector<char>> DIR_PAD =
	{
    	{'#','#','#','#','#'},
    	{'#','#','^','A','#'},
    	{'#','<','v','>','#'},
    	{'#','#','#','#','#'},
	};
    							 // up,   down, left,  right
const vector<pair<int, int>> DELTA{{0,1},{0,-1},{1,0},{-1,0}};

//--------------------------------------------------------------//

string BFS(const vector<vector<char>>& grid, 
		   pair<int,int> start, pair<int,int> target)
{
	int n = grid.size();
    int m = grid[0].size();
    
	queue<pair<int, int>> q;
	q.push(start);
	
	vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
	parent[start.first][start.second] = start;
	while(!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		
		if(i == target.first && j == target.second)
			break;
		
		for(auto &p : DELTA)
		{
			int newI = i + p.first;
			int newJ = j + p.second;
			
			if(grid[newI][newJ] == '#') continue;
			else if (parent[newI][newJ].first != -1) continue; // ya visitado
			
			parent[newI][newJ] = {i, j};
			q.push({newI, newJ});		
		}
	}
	
	string path = "";
    pair<int,int> curr = target;
    
    if (parent[curr.first][curr.second].first == -1)
        return ""; 
    
    while(curr != start)
    {
    	auto [pi, pj] = parent[curr.first][curr.second];
		
	 	if (pi == curr.first && pj == curr.second-1) path.push_back('>');
        else if (pi == curr.first && pj == curr.second+1) path.push_back('<');
        else if (pi == curr.first-1 && pj == curr.second) path.push_back('v');
        else if (pi == curr.first+1 && pj == curr.second) path.push_back('^');
        
        curr = {pi, pj};
    }
	    
    reverse(path.begin(), path.end());
    return path + 'A';
}

int main(void)
{
	
    return 0;
}