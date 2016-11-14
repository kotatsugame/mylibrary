const int in=2;
const int on=1;
const int out=0;

int contain(Polygon g,Point p)
{
	int n=g.size();
	bool x=false;
	Point a,b;
	for(int i=0;i<n;i++)
	{
		a=g[i]-p;
		b=g[(i+1)%n]-p;
		if(abs(cross(a,b))<EPS&&dot(a,b)<EPS)return on;
		if(a.y>b.y)
		{
			Point sto=a;
			a=b;
			b=sto;
		}
		if(a.y<EPS&&EPS<b.y&&cross(a,b)>EPS)x=!x;
	}
	return x?in:out;
}
