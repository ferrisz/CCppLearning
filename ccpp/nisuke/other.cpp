#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	int n=-1;
	int x,y,z;
	char Maxname[20],Minname[20];
	char name[20];
    printf("\n");
	while(scanf("%d",&n)&&n!=-1){
		int Max=0,Min=99999999999999;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d%d%s",&x,&y,&z,name);
			if (x*y*z>Max)
			{
				strcpy(Maxname,name);
				Max=x*y*z;
			}
			if (x*y*z<Min)
			{
				strcpy(Minname,name);
				Min=x*y*z;
				
			}

		}
		printf("%s took clay from %s\n",Maxname,Minname);
	}
	
	return 0;
}