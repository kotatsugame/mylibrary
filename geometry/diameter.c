double diameter(Polygon p)
{
	int n=p.size();
	if(n<=1)return 0.0;
	else if(n==2)return abs(p[1]-p[0]);
	
	int i=0,j=0;
	for(int k=0;k<n;k++)
	{
		if(p[k].x<p[i].x)i=k;
		else if(p[k].x>p[j].x)j=k;
	}
	
	double ans=0.0;
	int si=i,sj=j;
	
	while(i!=sj||j!=si)
	{
		ans=max(ans,abs(p[i]-p[j]));
		if(cross(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0.0)i=(i+1)%n;
		else j=(j+1)%n;
	}
	
	return ans;
}
