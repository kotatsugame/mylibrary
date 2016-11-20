const int MAX=10000;

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int n;

void dfs(int u)
{
	V[u]=true;
	for(int i=0;i<G[u].size();i++)
	{
		if(!V[G[u][i]])dfs(G[u][i]);
	}
	out.push_front(u);
	return;
}

void topologicalsort()
{
	for(int i=0;i<n;i++)V[i]=false;
	for(int i=0;i<n;i++)if(!V[i])dfs(i);
	for(auto it:out)cout<<it<<endl;
	return;
}
