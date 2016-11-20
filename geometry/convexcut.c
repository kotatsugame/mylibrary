Polygon convexcut(Polygon p,Line l)
{
	int n=p.size();
	Polygon q;
	
	for(int i=0;i<n;i++)
	{
		if(ccw(l.p1,l.p2,p[i])!=-1)q.push_back(p[i]);
		if(ccw(l.p1,l.p2,p[i])*ccw(l.p1,l.p2,p[(i+1)%n])<0.0)
		{
			if(!isparallel(l,Segment(p[i],p[(i+1)%n])))
			{
				q.push_back(getcrosspointll(l,Segment(p[i],p[(i+1)%n])));
			}
		}
	}
	
	return q;
}
