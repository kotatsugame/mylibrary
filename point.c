#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<utility>
#include<cmath>
#include<set>
using namespace std;
typedef long long int ll;
const double EPS=1e-10;

bool equals(double a,double b)
{
	return a>b?a-b<EPS:b-a<EPS;
}

class Point
{
public:
	double x;
	double y;
	Point(double inx=0.0,double iny=0.0):x(inx),y(iny){}
	Point operator+(const Point &p){return Point(x+p.x,y+p.y);}
	Point operator-(const Point &p){return Point(x-p.x,y-p.y);}
	Point operator*(const double k){return Point(x*k,y*k);}
	Point operator/(const double k){return Point(x/k,y/k);}
	Point operator=(const Point &p){x=p.x;y=p.y;return *this;}
	bool operator<(const Point &p)const{return x!=p.x?x<p.x:y<p.y;}
	bool operator==(const Point &p)const{return equals(x,p.x)&&equals(y,p.y);}
	double norm()
	{
		return x*x+y*y;
	}
	double abs()
	{
		return sqrt(norm());
	}
};

typedef Point Vector;

class Segment
{
public:
	Point p1;
	Point p2;
	Segment(Point inp1=Point(),Point inp2=Point()):p1(inp1),p2(inp2){}
	bool operator==(const Segment s)const
	{
		return p1.x==p2.x?s.p1.x==s.p2.x&&s.p1.x==p1.x:s.p1.x==s.p2.x?false:
		(p2.y-p1.y)/(p2.x-p1.x)==(s.p2.y-s.p1.y)/(s.p2.x-s.p1.x);
	}
	Vector getvector()
	{
		return p2-p1;
	}
};

typedef Segment Line;

class Circle
{
public:
	Point c;
	double r;
	Circle(Point inc=Point(),double inr=0.0):c(inc),r(inr){}
};

typedef vector<Point> Polygon;

double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}

double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}

double norm(Vector a)
{
	return a.x*a.x+a.y*a.y;
}

double abs(Vector a)
{
	return sqrt(norm(a));
}

const int counter_clockwise=1;
const int clockwise=-1;
const int on_segment=0;
const int online_back=2;
const int online_front=-2;

bool isorthogonal(Vector a,Vector b)
{
	return equals(dot(a,b),0.0);
}

bool isorthogonal(Point a1,Point a2,Point b1,Point b2)
{
	return isorthogonal(a1-a2,b1-b2);
}

bool isorthogonal(Segment s1,Segment s2)
{
	return equals(dot(s1.getvector(),s2.getvector()),0.0);
}

bool isparallel(Vector a,Vector b)
{
	return equals(cross(a,b),0.0);
}

bool isparallel(Point a1,Point a2,Point b1,Point b2)
{
	return isparallel(a1-a2,b1-b2);
}

bool isparallel(Segment s1,Segment s2)
{
	return equals(cross(s1.getvector(),s2.getvector()),0.0);
}

Point project(Segment s,Point p)
{
	Vector base=s.getvector();
	double r=dot(p-s.p1,base)/norm(base);
	return s.p1+base*r;
}

Point reflect(Segment s,Point p)
{
	return project(s,p)*2.0-p;//p+(project(s,p)-p)*2.0
}

double getdistance(Point a,Point b)
{
	return abs(a-b);
}

double getdistancelp(Line l,Point p)//Line,Point
{
	double s=abs(cross(l.p2-l.p1,p-l.p1));
	return s/abs(l.getvector());
}

double getdistancesp(Segment s,Point p)
{
	if(dot(s.getvector(),p-s.p1)<0.0)return abs(p-s.p1);
	else if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
	else return getdistancelp(s,p);
}

int ccw(Point p0,Point p1,Point p2)
{
	Vector a=p1-p0;
	Vector b=p2-p0;
	if(cross(a,b)>EPS)return counter_clockwise;
	else if(cross(a,b)<-EPS)return clockwise;
	else if(dot(a,b)<-EPS)return online_back;
	else if(a.norm()<b.norm())return online_front;
	else return on_segment;
}

bool intersect(Point p1,Point p2,Point p3,Point p4)
{
	return ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0;
}

bool intersectss(Segment s1,Segment s2)
{
	return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

double getdistance(Segment s1,Segment s2)
{
	if(intersectss(s1,s2))return 0.0;
	else return min(min(getdistancesp(s1,s2.p1),getdistancesp(s1,s2.p2)),
			min(getdistancesp(s2,s1.p1),getdistancesp(s2,s1.p2)));
}

Point getcrosspointss(Segment s1,Segment s2)
{
	Vector base=s2.getvector();
	double d1=abs(cross(base,s1.p1-s2.p1));
	double d2=abs(cross(base,s1.p2-s2.p1));
	double t=d1/(d1+d2);
	return s1.p1+s1.getvector()*t;
}

Point getcrosspointll(Line l1,Line l2)
{
	double c1=cross(l1.p1,l1.p2),c2=cross(l2.p1,l2.p2);
	double de=(l1.p1.y-l1.p2.y)*(l2.p1.x-l2.p2.x)-(l2.p1.y-l2.p2.y)*(l1.p1.x-l1.p2.x);
	double x=(l2.p2.x-l2.p1.x)*c1+(l1.p1.x-l1.p2.x)*c2;
	double y=(l2.p2.y-l2.p1.y)*c1+(l1.p1.y-l1.p2.y)*c2;
	return Point(x/de,y/de);
}

pair<Point,Point> getcrosspointcl(Circle c,Line l)
{
	Vector pr=project(l,c.c);
	Vector e=l.getvector()/abs(l.getvector());
	double base=sqrt(c.r*c.r-norm(pr-c.c));
	return make_pair(pr+e*base,pr-e*base);
}

double arg(Vector p)
{
	return atan2(p.y,p.x);
}

Vector polar(double r,double theta)
{
	return Point(r*cos(theta),r*sin(theta));
}

pair<Point,Point> getcrosspointcc(Circle c1,Circle c2)
{
	double d=abs(c2.c-c1.c);
	double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2.0*c1.r*d));
	double t=arg(c2.c-c1.c);
	return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}

int intersect(Circle c1,Circle c2)
{
	double d=abs(c2.c-c1.c);
	if(equals(d,c1.r+c2.r))return 3;
	else if(d>c1.r+c2.r)return 4;
	else if(equals(d,abs(c1.r-c2.r)))return 1;
	else if(d>abs(c1.r-c2.r))return 2;
	else return 0;
}

pair<Point,Point> gettangentpoint(Circle c,Point p)
{
	double d=abs(p-c.c);
	double l=sqrt(d*d-c.r*c.r);
	double a=asin(c.r/d);
	double t=arg(c.c-p);
	return make_pair(p+polar(l,t+a),p+polar(l,t-a));
}

vector<Point> gettangentpoint(Circle c1,Circle c2)
{
	vector<Point> p;
	int n=intersect(c1,c2);
	double d=abs(c2.c-c1.c);
	double t=arg(c2.c-c1.c);
	double a;
	
	if(n==1||n==3)
	{
		if(c1.r<c2.r&&n==1)p.push_back(c1.c-(c2.c-c1.c)*c1.r/d);
		else p.push_back(c1.c+(c2.c-c1.c)*c1.r/d);
	}
	if(n==2||n==3||n==4)
	{
		a=acos((c1.r-c2.r)/d);
		p.push_back(c1.c+polar(c1.r,t+a));
		p.push_back(c1.c+polar(c1.r,t-a));
	}
	if(n==4)
	{
		a=acos((c1.r+c2.r)/d);
		p.push_back(c1.c+polar(c1.r,t+a));
		p.push_back(c1.c+polar(c1.r,t-a));
	}
	
	sort(p.begin(),p.end());
	return p;
}

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

Polygon andrewscan(Polygon s)
{
	Polygon u,l;
	if(s.size()<=2)return s;
	sort(s.begin(),s.end());
	u.push_back(s[0]);
	u.push_back(s[1]);
	l.push_back(s[s.size()-1]);
	l.push_back(s[s.size()-2]);
	
	for(int i=2;i<s.size();i++)
	{
		for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])!=clockwise;n--)
		{
			u.pop_back();
		}
		u.push_back(s[i]);
	}
	
	for(int i=s.size()-3;i>=0;i--)
	{
		for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])!=clockwise;n--)
		{
			l.pop_back();
		}
		l.push_back(s[i]);
	}
	
	reverse(l.begin(),l.end());
	for(int i=u.size()-2;i>=1;i--)l.push_back(u[i]);
	
	return l;
}

const int Bottom=0;
const int Left=1;
const int Right=2;
const int Top=3;

class endPoint
{
public:
	Point p;
	int seg;//ID of Point
	int st;//kind of Point
	endPoint(){}
	endPoint(Point inp,int inseg,int inst):p(inp),seg(inseg),st(inst){}
	bool operator<(const endPoint &ep)const
	{
		if(p.y==ep.p.y)
		{
			return st<ep.st;//Bottom->Left->Right->Top
		}
		else return p.y<ep.p.y;
	}
};

endPoint EP[200000];

int manhattanintersection(vector<Segment> s)
{
	int n=s.size();
	double sto;
	
	for(int i=0,k=0;i<n;i++)
	{
		if(s[i].p1.y==s[i].p2.y)
		{
			if(s[i].p1.x>s[i].p2.x)
			{
				sto=s[i].p1.x;
				s[i].p1.x=s[i].p2.x;
				s[i].p2.x=sto;
			}
		}
		else if(s[i].p1.y>s[i].p2.y)
		{
			sto=s[i].p1.y;
			s[i].p1.y=s[i].p2.y;
			s[i].p2.y=sto;
		}
		
		if(s[i].p1.y==s[i].p2.y)
		{
			EP[k++]=endPoint(s[i].p1,i,Left);
			EP[k++]=endPoint(s[i].p2,i,Right);
		}
		else
		{
			EP[k++]=endPoint(s[i].p1,i,Bottom);
			EP[k++]=endPoint(s[i].p2,i,Top);
		}
	}
	
	sort(EP,EP+2*n);
	
	set<int> BT;
	BT.insert(1000000001);
	int cnt=0;
	
	for(int i=0;i<2*n;i++)
	{
		if(EP[i].st==Top)BT.erase(EP[i].p.x);
		else if(EP[i].st==Bottom)BT.insert(EP[i].p.x);
		else if(EP[i].st==Left)
		{
			set<int>::iterator b=lower_bound(BT.begin(),BT.end(),s[EP[i].seg].p1.x);
			set<int>::iterator e=upper_bound(BT.begin(),BT.end(),s[EP[i].seg].p2.x);
			cnt+=distance(b,e);
		}
	}
	
	return cnt;
}

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

