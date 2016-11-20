int euler_phi(int n)
{
	int ans=n;
	if(n%2==0)
	{
		while(n%2==0)n/=2;
		ans/=2;
	}
	for(int i=3;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)n/=i;
			ans/=i;
			ans*=i-1;
		}
	}
	if(n>1)
	{
		ans/=n;
		ans*=n-1;
	}
	return ans;
}
