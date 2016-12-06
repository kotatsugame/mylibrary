map<int,int>prime_factorization(int n)
{
	map<int,int> ans;
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			ans[i]++;
			n/=i;
		}
	}
	if(n!=1)ans[n]++;
	return ans;
}
