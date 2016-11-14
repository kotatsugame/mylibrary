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
