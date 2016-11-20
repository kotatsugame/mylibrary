const int MAX=100000;

vector<int> G[MAX];
int n;
bool visited[MAX];
int prenum[MAX],parent[MAX],lowest[MAX],timer;

void dfs(int current,int prev)
{
	prenum[current]=lowest[current]=timer++;
	visited[current]=true;
	int next;
	
	for(int i=0;i<G[current].size();i++)
	{
		next=G[current][i];
		if(!visited[next])
		{
			parent[next]=current;
			dfs(next,current);
			lowest[current]=min(lowest[current],lowest[next]);
		}
		else if(next!=prev)
		{
			lowest[current]=min(lowest[current],prenum[next]);
		}
	}
	
	return;
}

void art_points()
{
	for(int i=0;i<n;i++)visited[i]=false;
	timer=1;
	dfs(0,-1);//0==root
	
	set<int> ap;
	int np=0,p;
	for(int i=1;i<n;i++)
	{
		p=parent[i];
		if(p==0)np++;
		else if(prenum[p]<=lowest[i])ap.insert(p);
	}
	if(np>=2)ap.insert(0);
	for(auto it:ap)cout<<it<<endl;
	
	return;
}
