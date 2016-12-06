const int MAX=1<<18;

int data[MAX],datb[MAX];

void add(int a,int b,int x,int k,int l,int r)//[a,b)+=x, k is vertex-number(0), [l,r) is recursion range
{
	if(a<=l&&r<=b)data[k]+=x;
	else if(l<b&&a<r)
	{
		datb[k]+=(min(b,r)-max(a,l))*x;
		add(a,b,x,k*2+1,l,(l+r)/2);
		add(a,b,x,k*2+2,(l+r)/2,r);
	}
	return;
}

int sum(int a,int b,int k,int l,int r)
{
	if(b<=l||r<=a)return 0;
	else if(a<=l&&r<=b)return data[k]*(r-l)+datb[k];
	else
	{
		int res=(min(b,r)-max(a,l))*data[k];
		res+=sum(a,b,k*2+1,l,(l+r)/2);
		res+=sum(a,b,k*2+2,(l+r)/2,r);
		return res;
	}
}
