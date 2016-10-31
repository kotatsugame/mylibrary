vector<int> p;
void makeprimelist(int n)
{
	bool *isp=new bool[++n];
	for(int i=0;i<n-1;i++)isp[i]=true;
	for(int i=2;i<=n;i++)
	{
		if(isp[i])
		{
			p.push_back(i);
			for(int j=2;j<=n/i;j++)isp[i*j]=false;
		}
	}
	return;
}
