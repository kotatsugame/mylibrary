const int MAX=1<<17;
const int INF=(1LL<<31)-1;

int n,dat[2*MAX-1];//0-indexed

void init()
{
	int n_=n;
	n=1;
	while(n<n_)n<<=1;
	for(int i=0;i<2*n-1;i++)dat[i]=INF;
	return;
}

void update(int k,int a)
{
	k+=n-1;
	dat[k]=a;
	while(k>0)
	{
		k=(k-1)/2;
		dat[k]=min(dat[k*2+1],dat[k*2+2]);
	}
	return;
}

int getmin(int a,int b,int k,int l,int r)//[a,b),vertex-number(0),k's range[l,r)
{
	if(r<=a||b<=l)return INF;
	
	if(a<=l&&r<=b)return dat[k];
	else
	{
		int vl=getmin(a,b,k*2+1,l,(l+r)/2);
		int vr=getmin(a,b,k*2+2,(l+r)/2,r);
		return min(vl,vr);
	}
}
