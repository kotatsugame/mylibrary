const int MAX=1<<17;

int bit[MAX+1]={},n;//[1,n]

int sum(int i)//[1,i]
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i&=i-1;//i-=i&-i
	}
	return s;
}

void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
	return;
}
