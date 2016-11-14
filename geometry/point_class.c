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
