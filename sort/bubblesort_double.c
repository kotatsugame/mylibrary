void bubblesort(int A[][2],int n)
{
	bool flag=true;
	int a;
	for(int i=0;flag;i++)
	{
		flag=false;
		for(int j=n-1;j>=i+1;j--)
		{
			if(A[j][0]<A[j-1][0])
			{
				a=A[j][0];
				A[j][0]=A[j-1][0];
				A[j-1][0]=a;
				a=A[j][1];
				A[j][1]=A[j-1][1];
				A[j-1][1]=a;
				flag=true;
			}
		}
	}
	return;
}
