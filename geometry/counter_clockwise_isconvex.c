bool isconvex(Polygon p)
{
	int n=p.size(),now;
	for(int i=0;i<n;i++)
	{
		now=ccw(p[i],p[(i+1)%n],p[(i+2)%n]);
		if(now==clockwise)return false;
	}
	return true;
}
