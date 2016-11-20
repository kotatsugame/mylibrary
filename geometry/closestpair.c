const double INF_double=1e12;

double closestpair_cal(Point p[],int n)
{
	if(n<=1)return INF_double;
	int m=n/2;
	double x=p[m].x;
	double d=min(closestpair_cal(p,m),closestpair_cal(p+m,n-m));
	inplace_merge(p,p+m,p+n,[](const Point p1,const Point p2){return p1.y==p2.y?p1.x<p2.x:p1.y<p2.y;});
	
	vector<Point> q;
	double dx,dy;
	
	for(int i=0;i<n;i++)
	{
		if(abs(p[i].x-x)>=d)continue;
		
		for(int j=q.size()-1;j>=0;j--)
		{
			dx=p[i].x-q[j].x;
			dy=p[i].y-q[j].y;
			if(dy>=d)break;
			d=min(d,sqrt(dx*dx+dy*dy));
		}
		q.push_back(p[i]);
	}
	
	return d;
}

double closestpair(Point p[],int n)
{
	if(n<=1)return 0.0;
	sort(p,p+n);
	double ans=closestpair_cal(p,n);
	return ans==INF_double?0.0:ans;
}
