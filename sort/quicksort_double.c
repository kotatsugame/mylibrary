int partition(int A[][2],int p,int r)
{
	int x=A[r][0];
	int i=p-1;
	int sto;
	for(int j=p;j<r;j++)
	{
		if(A[j][0]<=x)
		{
			sto=A[++i][0];
			A[i][0]=A[j][0];
			A[j][0]=sto;
			sto=A[i][1];
			A[i][1]=A[j][1];
			A[j][1]=sto;
		}
	}
	sto=A[++i][0];
	A[i][0]=A[r][0];
	A[r][0]=sto;
	sto=A[i][1];
	A[i][1]=A[r][1];
	A[r][1]=sto;
	return i;
}

void quicksort(int A[][2],int p,int r)//r is often n-1
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
	return;
}
