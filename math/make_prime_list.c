vector<int> p;
void makeprimelist(int n)
{
	bool *isp=new bool[++n];
	for(int i=0;i<n;i++)isp[i]=true;
	for(int i=2;i<n;i++)
	{
		if(isp[i])
		{
			p.push_back(i);
			for(int j=i;j<n;j+=i)isp[j]=false;
		}
	}
	return;
}
