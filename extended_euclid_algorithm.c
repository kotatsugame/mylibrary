pair<int,int> ex_gcd(int a,int b)
{
	int x1=1,y1=0,z1=a;
	int x2=0,y2=1,z2=b;
	int q,sto;
	while(z2!=0)
	{
		q=z1/z2;
		x1-=q*x2;
		y1-=q*y2;
		z1-=q*z2;
		
		sto=x1;
		x1=x2;
		x2=sto;
		sto=y1;
		y1=y2;
		y2=sto;
		sto=z1;
		z1=z2;
		z2=sto;
	}
	return make_pair(x1,y1);
}
