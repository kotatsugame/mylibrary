const int MAXn=100;

int n,M[MAXn][MAXn]={0},col[MAXn];//color:0=white,1=gray,2=brack
int d[MAXn],f[MAXn],t;

void dfs_visit(int u)
{
	int v;
	col[u]=1;
	d[u]=++t;
	for(v=0;v<n;v++)
	{
		if(M[u][v]==0)continue;
		if(col[v]==0)dfs_visit(v);
	}
	col[u]=2;
	f[u]=++t;
	return;
}

void dfs()
{
	int u;
	for(u=0;u<n;u++)col[u]=0;
	t=0;
	
	for(u=0;u<n;u++)if(col[u]==0)dfs_visit(u);
	
	for(u=0;u<n;u++)cout<<u+1<<" "<<d[u]<<" "<<f[u]<<endl;
	
	return;
}
