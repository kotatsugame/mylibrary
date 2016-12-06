const int MAX=1<<17;

vector<int> G[MAX];
int root;
int V;

int vs[MAX*2-1];
int depth[MAX*2-1];
int id[MAX];

int n;
int dat[MAX*4-1];//0-indexed

void rmq_init(int V)
{
	n=1;
	while(n<V)n<<=1;
	for(int i=0;i<2*n-1;i++)dat[i]=-1;
	return;
}

void update(int k,int a)
{
	k+=n-1;
	dat[k]=a;
	while(k>0)
	{
		k=(k-1)/2;
		int b1=dat[k*2+1],b2=dat[k*2+2];
		if(b1!=-1&&b2!=-1)dat[k]=(depth[b1]<=depth[b2]?b1:b2);
		else if(b2!=-1)dat[k]=b2;
		else dat[k]=b1;
	}
	return;
}

int getmin(int a,int b,int k,int l,int r)//[a,b),vertex-number(0),k's range[l,r)
{
	if(r<=a||b<=l)return -1;
	
	if(a<=l&&r<=b)return dat[k];
	else
	{
		int vl=getmin(a,b,k*2+1,l,(l+r)/2);
		int vr=getmin(a,b,k*2+2,(l+r)/2,r);
		if(vl!=-1&&vr!=-1)return (depth[vl]<=depth[vr]?vl:vr);
		else if(vr!=-1)return vr;
		else return vl;
	}
}

void dfs(int v,int p,int d,int &k)
{
	id[v]=k;
	vs[k]=v;
	depth[k]=d;
	k++;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]!=p)
		{
			dfs(G[v][i],v,d+1,k);
			vs[k]=v;
			depth[k]=d;
			k++;
		}
	}
	return;
}

void init()
{
	int k=0;
	dfs(root,-1,0,k);
	rmq_init(V*2-1);
	for(int i=0;i<V*2-1;i++)update(i,i);
	return;
}

int lca(int u,int v)
{
	if(id[u]>id[v])swap(u,v);
	return vs[getmin(id[u],id[v]+1,0,0,n)];
}
