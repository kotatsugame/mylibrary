const int NIL=-1;
const int MAXt=10000;

class Node{
public:
	int parent;
	int left;
	int right;
};

Node T[MAXt];
int Depth[MAXt];

int getDepth(int u)
{
	int d=0,ub=u;
	while(T[u].parent!=NIL)
	{
		u=T[u].parent;
		d++;
	}
	return Depth[ub]=d;
}

void setDepth(int u,int p)
{
	Depth[u]=p;
	if(T[u].right!=NIL)setDepth(T[u].right,p);
	if(T[u].left!=NIL)setDepth(T[u].left,p+1);
	return;
}
