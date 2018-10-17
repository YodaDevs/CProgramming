#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
	int j,n,i,gira[MAX],k=0,continua=1;
	char carac[MAX];
	scanf("%d", &n);
	int slots[n],slots2[n], aun=n;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &slots[i]);
		slots2[i] = slots[i];
	}
	i=0;
	while(scanf("%c", &carac[i])!=EOF)
	{
		scanf("%d", &gira[i]);
		i++;
	}
	j=0;
	while(continua)
	{
		if (carac[j]=='D')
		{
			while(aun--)
			{
				while(gira[j]>n)
				{
					gira[j] = gira[j] - n;
				}
				i = ((n-gira[j])+k) % n;
				slots2[k]=slots[i];
				k++;
			}
			aun = n-1;
			k=0;
			while(aun--)
			{
				printf("%d ",slots2[k]);
				k++;
			}
			
			if (carac[j+1]=='S') printf("%d\n", slots2[k]);
			
			else printf("%d \n", slots2[k]);

			for(i=0; i<n; i++)
			{
			    slots[i] = slots2[i];
			}
			aun=n;
			k=0;
		}
		else if (carac[j]=='E')
		{
			while(aun--)
			{
				while(gira[j]>n)
				{
					gira[j] = gira[j] - n;
				}
				i = (gira[j]+k) % n;
				slots[k]=slots2[i];
				k++;
			}
			aun = n-1;
			k=0;
			while(aun--)
			{
				printf("%d ",slots[k]);
				k++;
			}
			
			if (carac[j+1]=='S') printf("%d\n", slots[k]);
			
			else printf("%d \n", slots[k]);

			for(i=0; i<n; i++)
			{
			    slots2[i] = slots[i];
			}
			aun=n;
			k=0;
		}
		if (carac[j]=='S')
		{
			break;
		}
		j++;
	}
	return 0;
}