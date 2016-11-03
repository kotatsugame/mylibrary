const int MAXn=100000;
const int NIL=-1;

int n,col[MAXn];
vector<int> G[MAXn];

void dfs(int r,int c)
{
	stack<int> S;
	S.push(r);
	col[r]=c;
	while(!S.empty())
	{
		int u=S.top();S.pop();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(col[v]==NIL)
			{
				col[v]=c;
				S.push(v);
			}
		}
	}
	return;
}

void assingcol()
{
	int id=1;
	for(int i=0;i<n;i++)col[i]=NIL;
	for(int u=0;u<n;u++)if(col[u]==NIL)dfs(u,id++);
	return;
}
