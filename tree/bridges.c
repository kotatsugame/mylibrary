typedef pair<int,int> P;

const int MAX=100000;

int n;
vector<int> G[MAX];
int order[MAX]={};
bool inS[MAX]={};
stack<int> roots;
int k;
vector<P> brg;

void visit(int v,int p)
{
	order[v]=++k;
	inS[v]=true;
	roots.push(v);
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(order[to]==0)
		{
			visit(to,v);
		}
		else if(to!=p&&inS[to])
		{
			while(order[roots.top()]>order[to])roots.pop();
		}
	}
	if(v==roots.top())
	{
		if(p!=-1)brg.push_back(P(min(p,v),max(p,v)));
		roots.pop();
	}
	return;
}

void bridge()
{
	k=0;
	for(int i=0;i<n;i++)
	{
		if(order[i]==0)
		{
			visit(i,-1);
		}
	}
	return;
}
