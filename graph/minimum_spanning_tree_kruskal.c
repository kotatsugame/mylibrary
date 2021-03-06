class edge
{
public:
	int source,target,cost;
	edge(int insource=0,int intarget=0,int incost=0):
	source(insource),target(intarget),cost(incost){}
	bool operator<(const edge &e)const{return cost<e.cost;}
};

class disjointset
{
public:
	vector<int> rank;
	vector<int> p;
	
	void makeset(int x)
	{
		p[x]=x;
		rank[x]=0;
		return;
	}
	disjointset(int s)
	{
		rank.resize(s);
		p.resize(s);
		for(int i=0;i<s;i++)makeset(i);
		return;
	}
	int findset(int x)
	{
		if(x!=p[x])p[x]=findset(p[x]);
		return p[x];
	}
	void link(int x,int y)
	{
		if(rank[x]>rank[y])p[y]=x;
		else
		{
			p[x]=y;
			if(rank[x]==rank[y])rank[y]++;
		}
		return;
	}
	bool same(int x,int y)
	{
		return findset(x)==findset(y);
	}
	void unite(int x,int y)
	{
		link(findset(x),findset(y));
		return;
	}
};

int n;

vector<edge> kruskal(vector<edge> e)
{
	sort(e.begin(),e.end());
	disjointset d=disjointset(n);
	edge ne;
	vector<edge> mst;
	
	for(int i=0;i<e.size();i++)
	{
		ne=e[i];
		if(!d.same(ne.source,ne.target))
		{
			mst.push_back(ne);
			d.unite(ne.source,ne.target);
		}
	}
	
	return mst;
}

int totalcostcal(vector<edge> e)
{
	int ans=0;
	for(int i=0;i<e.size();i++)ans+=e[i].cost;
	return ans;
}
