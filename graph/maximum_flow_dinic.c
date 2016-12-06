const int MAX=100;
const int MAX_cap=10000;

class edge
{
public:
	int to,cap,rev;
	edge(){}
	edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};

vector<edge> G[MAX];
int level[MAX];//s->v distance
int iter[MAX];

void add_edge(int from,int to,int cap)
{
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
	return;
}

void bfs(int s)
{
	memset(level,-1,sizeof(level));
	queue<int> Q;
	level[s]=0;
	Q.push(s);
	
	while(!Q.empty())
	{
		int v=Q.front();Q.pop();
		for(int i=0;i<G[v].size();i++)
		{
			edge e=G[v][i];
			if(e.cap>0&&level[e.to]<0)
			{
				level[e.to]=level[v]+1;
				Q.push(e.to);
			}
		}
	}
	return;
}

int dfs(int v,int t,int f)
{
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to])
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int maxflow(int s,int t)
{
	int flow=0;
	while(1)
	{
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,MAX_cap))>0)flow+=f;
	}
}
