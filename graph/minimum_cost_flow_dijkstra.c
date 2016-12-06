typedef pair<int,int> P;//shortest pass,vertex number

const int MAX=100;
const int INF=1<<25;

class edge
{
public:
	int to,cap,cost,rev;
	edge(){}
	edge(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
};

int V;
vector<edge> G[MAX];
int h[MAX];
int dist[MAX];
int prevv[MAX],preve[MAX];

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
	return;
}

int mincostflow(int s,int t,int f)
{
	int res=0;
	memset(h,0,sizeof(h));
	while(f>0)
	{
		priority_queue<P> Q;
		fill(dist,dist+V,INF);
		dist[s]=0;
		Q.push(P(0,s));
		
		while(!Q.empty())
		{
			P p=Q.top();Q.pop();
			int v=p.second;
			if(dist[v]<p.first*(-1))continue;
			for(int i=0;i<G[v].size();i++)
			{
				edge &e=G[v][i];
				if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
				{
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					Q.push(P(dist[e.to]*(-1),e.to));
				}
			}
		}
		
		if(dist[t]==INF)return -1;
		
		for(int v=0;v<V;v++)h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v])d=min(d,G[prevv[v]][preve[v]].cap);
		f-=d;
		res+=d*h[t];
		
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}
