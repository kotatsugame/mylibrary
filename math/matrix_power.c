typedef vector<int> VI;
typedef vector<VI> VVI;

VVI mul(VVI &A,VVI &B)
{
	VVI C(A.size(),VI(B[0].size()));
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B[0].size();j++)
		{
			C[i][j]=0;
			for(int k=0;k<B.size();k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	return C;
}

VVI  pow(VVI A,int n)
{
	VVI B(A.size(),VI(A[0].size()));
	for(int i=0;i<A.size();i++)B[i][i]=1;
	
	while(n>0)
	{
		if(n&1)B=mul(B,A);
		A=mul(A,A);
		n>>=1;
	}
	return B;
}
