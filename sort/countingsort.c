void countingsort(int A[],int n,int maxs)//maxsize
{
	int *B=new int[n];
	int *C=new int[++maxs];
	int i;
	for(i=0;i<maxs;i++)C[i]=0;
	for(i=0;i<n;i++)
	{
		C[A[i]]++;
		B[i]=A[i];
	}
	for(i=1;i<maxs;i++)C[i]+=C[i-1];
	for(i=n;i--;)
	{
		C[B[i]]--;
		A[C[B[i]]]=B[i];
	}
	return;
}
