void bubblesort(int A[],int n)
{
	bool flag=true;
	int a;
	for(int i=0;flag;i++)
	{
		flag=false;
		for(int j=n-1;j>=i+1;j--)
		{
			if(A[j]<A[j-1])
			{
				a=A[j];
				A[j]=A[j-1];
				A[j-1]=a;
				flag=true;
			}
		}
	}
	return;
}
