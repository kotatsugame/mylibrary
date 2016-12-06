const int MAX=10000;
typedef pair<int,int> P;

int n;
vector<P> G[MAX];
int dph[MAX][MAX];//vertex number, edge number
int h[MAX];

int dfs(int u,int e)
{
	if(dph[u][e]>=0)return dph[u][e];
	dph[u][e]=G[u][e].second;
	int v=G[u][e].first;
	
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].first==u)continue;
		dph[u][e]=max(dph[u][e],dfs(v,i)+G[u][e].second);
	}
	
	return dph[u][e];
}

void getheight()
{
	for(int i=0;i<n;i++)
	{
		h[i]=0;
		for(int j=0;j<G[i].size();j++)
		{
			dph[i][j]=-1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			if(dph[i][j]<0)dph[i][j]=dfs(i,j);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			h[i]=max(h[i],dph[i][j]);
		}
	}
	
	return;
}
