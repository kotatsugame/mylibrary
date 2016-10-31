const int INF=2000000000;
const int SIZE=500000;

int L[SIZE/2+2],R[SIZE/2+2];

void merge(int A[],int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	int i,j;
	for(i=0;i<n1;i++)L[i]=A[left+i];
	for(i=0;i<n2;i++)R[i]=A[mid+i];
	L[n1]=R[n2]=INF;
	i=j=0;
	for(int k=left;k<right;k++)
	{
		if(L[i]<R[j])A[k]=L[i++];
		else A[k]=R[j++];
	}
	return;
}

void mergesort(int A[],int left,int right)
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
