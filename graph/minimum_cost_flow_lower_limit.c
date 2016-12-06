const int inf=1<<20;

void add_edge_lowerlimit(int from,int to,int cap,int cost,int limit)
{
	add_edge(from,to,cap-limit,cost);
	add_edge(from,to,limit,cost-inf);
	return;
}
