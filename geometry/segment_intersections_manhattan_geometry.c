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
