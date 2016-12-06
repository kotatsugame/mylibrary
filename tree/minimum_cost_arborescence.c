const int MAX=100;

class edge
{
public:
	int src,tar,w;
	edge(int src=0,int tar=0,int w=0):src(src),tar(tar),w(w){}
};

int n;
vector<edge> G[MAX];

int cost;
vector<edge> GG[MAX];//reverse edge
int num[MAX],pre[MAX],mcost[MAX];//number, prev of vertex, edges min cost
bool mark[MAX];//vertex used flag
vector<int> comp[MAX];//compressed vertex
vector<int> nex[MAX];//next of vertex

void cycle(int v,int s,int r,bool &found)
{
	if(mark[v])
	{
		int temp[MAX];
		for(int i=0;i<n;i++)temp[i]=num[i];
		found=true;
		do
		{
			cost+=mcost[v];
			v=pre[v];
			if(v!=s)
			{
				while(!comp[v].empty())
				{
					num[comp[v].back()]=s;
					comp[s].push_back(comp[v].back());
					comp[v].pop_back();
				}
			}
		}while(v!=s);
		
		for(int i=0;i<comp[s].size();i++)
		{
			int j=comp[s][i];
			if(j!=r)
			{
				for(int k=0;k<GG[j].size();k++)
				{
					if(num[GG[j][k].src]!=s)
					{
						GG[j][k].w-=mcost[temp[j]];
					}
				}
			}
		}
	}
	
	mark[v]=true;
	for(int k=0;k<nex[v].size();k++)
	{
		int i=nex[v][k];
		if(num[i]!=num[v]&&pre[num[i]]==v)
		{
			if(!mark[num[i]]||i==s)
			{
				cycle(i,s,r,found);
			}
		}
	}
	return;
}

int mincosttree(int r)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			GG[G[i][j].tar].push_back(G[i][j]);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		num[i]=i;
		comp[i].push_back(i);
	}
	cost=0;
	
	while(1)
	{
		for(int i=0;i<n;i++)
		{
			pre[i]=-1;
			mcost[i]=1<<28;
		}
		
		for(int j=0;j<n;j++)
		{
			if(j==r)continue;
			for(int k=0;k<GG[j].size();k++)
			{
				int i=GG[j][k].src;
				if(num[i]!=num[j])
				{
					if(GG[j][k].w<mcost[num[j]])
					{
						mcost[num[j]]=GG[j][k].w;
						pre[num[j]]=num[i];
					}
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
			if(pre[i]>=0)
			{
				nex[pre[i]].push_back(i);
			}
		}
		
		bool stop=true;
		for(int i=0;i<n;i++)mark[i]=false;
		
		for(int i=0;i<n;i++)
		{
			if(i==r||mark[i]||comp[i].empty())continue;
			bool found=false;
			cycle(i,i,r,found);
			if(found)stop=false;
		}
		if(stop)
		{
			for(int i=0;i<n;i++)
			{
				if(pre[i]>=0)
				{
					cost+=mcost[i];
				}
			}
			return cost;
		}
	}
}
