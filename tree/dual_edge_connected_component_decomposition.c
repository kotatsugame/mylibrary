typedef pair<int,int> P;

const int MAX=100000;

int n;
vector<int> G[MAX];
int order[MAX]={};
bool inS[MAX]={};
stack<int> roots,S;
int k;
vector<P> brg;
vector<vector<int>> each_bcc;

void visit(int v,int p)
{
	order[v]=++k;
	S.push(v);
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
		vector<int> bcc;
		while(1)
		{
			int node=S.top();S.pop();
			inS[node]=false;
			bcc.push_back(node);
			if(node==v)break;
		}
		each_bcc.push_back(bcc);
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
