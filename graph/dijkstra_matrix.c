const int MAX=100;
const int INFTY=1<<21;

int n,M[MAX][MAX],col[MAX],d[MAX],p[MAX];

void dijkstra(int s)
{
	for(int i=0;i<n;i++)
	{
		col[i]=0;
		d[i]=INFTY;
	}
	d[s]=0;
	p[s]=-1;
	
	while(1)
	{
		int mincost=INFTY;
		int u;
		for(int i=0;i<n;i++)
		{
			if(col[i]!=2&&d[i]<mincost)
			{
				mincost=d[i];
				u=i;
			}
		}
		if(mincost==INFTY)break;
		col[u]=2;
		for(int v=0;v<n;v++)
		{
			if(col[v]!=2&&M[u][v]!=INFTY)
			{
				if(d[u]+M[u][v]<d[v])
				{
					d[v]=d[u]+M[u][v];
					p[v]=u;
					col[v]=1;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++)cout<<i<<" "<<(d[i]==INFTY?-1:d[i])<<endl;
	
	return;
}
