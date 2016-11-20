int lis(int A[],int n)
{
	int*L=new int[n+1];
	L[0]=A[0];
	int length=1;
	
	for(int i=1;i<n;i++)
	{
		if(L[length-1]<A[i])L[length++]=A[i];
		else *lower_bound(L,L+length,A[i])=A[i];
	}
	
	return length;
}
