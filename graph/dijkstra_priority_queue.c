const int MAX=100000;
const int INFTY=1<<30;

int n,col[MAX],d[MAX];
vector<pair<int,int>> Q[MAX];//target,weight

void dijkstra(int s)
{
	priority_queue<pair<int,int>> PQ;//weight,id
	for(int i=0;i<n;i++)
	{
		d[i]=INFTY;
		col[i]=0;
	}
	d[s]=0;
	PQ.push(make_pair(0,s));
	col[s]=1;
	
	while(!PQ.empty())
	{
		pair<int,int> f=PQ.top();PQ.pop();
		int u=f.second;
		col[u]=2;
		if(d[u]<f.first*(-1))continue;
		for(int j=0;j<Q[u].size();j++)
		{
			int v=Q[u][j].first;
			if(col[v]==2)continue;
			if(d[u]+Q[u][j].second<d[v])
			{
				d[v]=d[u]+Q[u][j].second;
				PQ.push(make_pair(d[v]*(-1),v));
				col[v]=1;
			}
		}
	}
	
	for(int i=0;i<n;i++)cout<<i<<" "<<(d[i]==INFTY?-1:d[i])<<endl;
	
	return;
}
