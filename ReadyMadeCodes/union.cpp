/* Graph structure Template for ICPC */

//Included Libraries
#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


int 			parent[MAX_VERT];	//The parent of the vertex in traversal (in all) / parent in set hierarchy (in kruskal)
int			count[MAX_VERT];	//counts the number of elements in this set (in kruskal)

void Graph::kruskal()
{
	mst.clear();
	int i;
	FOR(i, 1, V)
	{
		parent[i] = i;
		count[i] = 1;
	}

	sort_edge_list();

	vector< edge_node >::iterator it;
	FOR(it, edge_list.begin(), --(edge_list.end()))
	{
		int set_v1 = find_set(it->v1); 
		int set_v2 = find_set(it->v2); 

		if (set_v1 != set_v2)
		{
			union_set(set_v1, set_v2);
			mst.push_back(*it);
		}
	}
}

int Graph::find_set(int v)
{
	while (v != parent[v])
	{
		v = parent[v];
	}

	return v;
}

void Graph::union_set(int v1, int v2)
{
	if (count[v1] >= count[v2])
	{
		count[v1] += count[v2];
		parent[v2] = v1;
	}
	else
	{
		count[v2] += count[v1];
		parent[v1] = v2;
	}
}
