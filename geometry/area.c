double area(Polygon p)
{
	int n=p.size();
	double sum=0.0;
	for(int i=0;i<n;i++)
	{
		sum+=0.5*cross(p[i],p[(i+1)%n]);
	}
	return sum<0.0?-sum:sum;
}
