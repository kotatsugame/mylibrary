const int MAX=100000;
const int INFTY=1<<30;

class edge
{
public:
	int t,w;
	edge(int in_t=0,int inw=0):t(in_t),w(inw){}
};

vector<edge> G[MAX];
int n,d[MAX];
bool visited[MAX];
int count;

void bfs(int s)
{
	for(int i=0;i<n;i++)d[i]=INFTY;
	queue<int> q;
	q.push(s);
	d[s]=0;
	int u;
	edge e;
	
	while(!q.empty())
	{
		u=q.front();q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			e=G[u][i];
			if(d[e.t]==INFTY)
			{
				d[e.t]=d[u]+e.w;
				q.push(e.t);
			}
		}
	}
	
	return;
}

int getdiameter()
{
	bfs(0);
	int maxv=0,tgt=0;
	for(int i=0;i<n;i++)
	{
		if(d[i]==INFTY)continue;
		else if(maxv<d[i])
		{
			maxv=d[i];
			tgt=i;
		}
	}
	
	bfs(tgt);
	maxv=0;
	for(int i=0;i<n;i++)
	{
		if(d[i]==INFTY)continue;
		maxv=max(maxv,d[i]);
	}
	
	return maxv;
}
