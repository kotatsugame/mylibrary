const int counter_clockwise=1;
const int clockwise=-1;
const int on_segment=0;
const int online_back=2;
const int online_front=-2;

double norm(Vector a)
{
	return a.x*a.x+a.y*a.y;
}

double abs(Vector a)
{
	return sqrt(norm(a));
}

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

bool intersect(Segment s1,Segment s2)
{
	return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

double getdistance(Segment s1,Segment s2)
{
	if(intersect(s1,s2))return 0.0;
	else return min(min(getdistancesp(s1,s2.p1),getdistancesp(s1,s2.p2)),
			min(getdistancesp(s2,s1.p1),getdistancesp(s2,s1.p2)));
}

Point getcrosspoint(Segment s1,Segment s2)
{
	Vector base=s2.getvector();
	double d1=abs(cross(base,s1.p1-s2.p1));
	double d2=abs(cross(base,s1.p2-s2.p1));
	double t=d1/(d1+d2);
	return s1.p1+s1.getvector()*t;
}

pair<Point,Point> getcrosspoint(Circle c,Line l)
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

Point polar(double r,double theta)
{
	return Point(r*cos(theta),r*sin(theta));
}

pair<Point,Point> getcrosspoint(Circle c1,Circle c2)
{
	double d=abs(c2.c-c1.c);
	double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2.0*c1.r*d));
	double t=arg(c2.c-c1.c);
	return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}
