class Solution {
private:
	void dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited,vector<int> &dfsVisited){
		visited[node] = 1;
		dfsVisited[node] = 1;
		for(auto neigh:graph[node]){
			if(!visited[neigh]){
				dfs(neigh, graph, visited, dfsVisited);
			}
		}
		dfsVisited[node] = 0;
	}
	
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> graph;
		for(auto i:prerequisites){
			int u = i[0], v = i[1];
			graph[u].push_back(v);
		}

		// cycle detection
		vector<int> visited(numCourses, 0);
		vector<int> dfsVisited(numCourses, 0);
		for(auto i:graph){
			if(!visited[i.first]){
				dfs(i.first, graph, visited, dfsVisited);
			}
		}
	}
};