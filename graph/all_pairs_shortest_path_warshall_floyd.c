static const int MAX=100;
static const long long int INFTY=1LL<<32;

int n;
long long int M[MAX][MAX];

void floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(M[i][k]==INFTY)continue;
			for(int j=0;j<n;j++)
			{
				if(M[k][j]==INFTY)continue;
				M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
			}
		}
	}
	return;
}
