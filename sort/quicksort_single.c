int partition(int A[],int p,int r)
{
	int x=A[r];
	int i=p-1;
	int sto;
	for(int j=p;j<r;j++)
	{
		if(A[j]<=x)
		{
			sto=A[++i];
			A[i]=A[j];
			A[j]=sto;
		}
	}
	sto=A[++i];
	A[i]=A[r];
	A[r]=sto;
	return i;
}

void quicksort(int A[],int p,int r)//r is often n-1
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
	return;
}
