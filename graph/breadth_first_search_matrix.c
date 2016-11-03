const int MAXn=100;
const int INFTY=1<<21;

int n,M[MAXn][MAXn]={0},d[MAXn];

void bfs(int u)
{
	queue<int> Q;
	Q.push(s);
	for(int i=0;i<n;i++)d[i]=INFTY;
	d[s]=0;
	int v;
	
	while(!Q.empty())
	{
		v=Q.front();Q.pop();
		for(int r=0;r<n;r++)
		{
			if(M[v][r]==0)continue;
			if(d[r]!=INFTY)continue;
			d[r]=d[v]+1;
			Q.push(r);
		}
	}
	
	for(int i=0;i<n;i++)cout<<i+1<<" "<<d[i]==INFTY?-1:d[i]<<endl;
	
	return;
}
