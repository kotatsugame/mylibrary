const int INF=2000000000;
const int SIZE=100000;

int L[SIZE/2+2][2],R[SIZE/2+2][2];

void merge(int A[][2],int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	int i,j;
	for(i=0;i<n1;i++)
	{
		L[i][0]=A[left+i][0];
		L[i][1]=A[left+i][1];
	}
	for(i=0;i<n2;i++)
	{
		R[i][0]=A[mid+i][0];
		R[i][1]=A[mid+i][1];
	}
	L[n1][0]=R[n2][0]=INF;
	i=j=0;
	for(int k=left;k<right;k++)
	{
		if(L[i][0]<=R[j][0])
		{
			A[k][0]=L[i][0];
			A[k][1]=L[i++][1];
		}
		else
		{
			A[k][0]=R[j][0];
			A[k][1]=R[j++][1];
		}
	}
	return;
}

void mergesort(int A[][2],int left,int right)
{
	if(left+1<right)
	{
		int mid=(left+right)/2;
		mergesort(A,left,mid);
		mergesort(A,mid,right);
		merge(A,left,mid,right);
	}
	return;
}
