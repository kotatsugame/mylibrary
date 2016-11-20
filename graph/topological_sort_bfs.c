const int MAX=10000;

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int n;
int indeg[MAX];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	V[s]=true;
	int u,v;
	
	while(!q.empty())
	{
		u=q.front();q.pop();
		out.push_back(u);
		for(int i=0;i<G[u].size();i++)
		{
			v=G[u][i];
			indeg[v]--;
			if(!V[v]&&indeg[v]==0)
			{
				V[v]=true;
				q.push(v);
			}
		}
	}
	
	return;
}

void topologicalsort()
{
	for(int i=0;i<n;i++)
	{
		indeg[i]=0;
		V[i]=false;
	}
	
	for(int u=0;u<n;u++)
	{
		for(int i=0;i<G[u].size();i++)
		{
			indeg[G[u][i]]++;
		}
	}
	
	for(int u=0;u<n;u++)if(!V[u]&&indeg[u]==0)bfs(u);
	
	for(auto it:out)cout<<it<<endl;
	
	return;
}
