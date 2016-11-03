const int NIL=-1;
const int MAXt=10000;

class node
{
public:
	int p;
	int l;
	int r;
};

node T[MAXt];

int H[MAXt];

int seth(int u)
{
	int h1=0,h2=0;
	if(T[u].r!=NIL)h1=seth(T[u].r)+1;
	if(T[u].l!=NIL)h2=seth(T[u].l)+1;
	return H[u]=h1>h2?h1:h2;
}

int D[MAXt];

void setdp(int u,int d)//depth
{
	if(u==NIL)return;
	D[u]=d++;
	setdp(T[u].l,d);
	setdp(T[u].r,d);
	return;
}

int gets(int u)//sibling
{
	if(T[u].p!=NIL)
	{
		if(T[T[u].p].l!=u&&T[T[u].p].l!=NIL)return T[T[u].p].l;
		if(T[T[u].p].r!=u&&T[T[u].p].r!=NIL)return T[T[u].p].r;
	}
	return NIL;
}

int getdg(int u)//degree
{
	int d=0;
	if(T[u].l!=NIL)d++;
	if(T[u].r!=NIL)d++;
	return d;
}

int treein(int n)
{
	int id,r,l,root;
	for(int i=0;i<n;i++)T[i].p=NIL;
	for(int i=0;i<n;i++)
	{
		cin>>id>>l>>r;
		T[id].l=l;
		if(l!=NIL)T[l].p=id;
		T[id].r=r;
		if(r!=NIL)T[r].p=id;
	}
	for(int i=0;i<n;i++)if(T[i].p==NIL){root=i;break;}
	return root;
}

void preo(int u)//preorder
{
	if(u==NIL)return;
	cout<<" "<<u;
	preo(T[u].l);
	preo(T[u].r);
	return;
}

void ino(int u)//inorder
{
	if(u==NIL)return;
	ino(T[u].l);
	cout<<" "<<u;
	ino(T[u].r);
	return;
}

void posto(int u)//postorder
{
	if(u==NIL)return;
	posto(T[u].l);
	posto(T[u].r);
	cout<<" "<<u;
	return;
}
