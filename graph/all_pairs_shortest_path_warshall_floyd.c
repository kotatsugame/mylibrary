typedef long long int ll;

const int MAX=100;
const ll INFTY=1LL<<32;

int n;
ll M[MAX][MAX];//diagonal component=0

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
