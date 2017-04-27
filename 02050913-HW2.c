//Kang Tong Pei 02050913
//Collatz Conjecture
//2017/04/27


#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>


int main(int argc ,const char* argv[])
{
        pid_t pid;
        pid = fork();
        int n,i;
        int a[100];


        if(pid<0)
        {
                fprintf(stderr,"Fork Fail");
                return 1;
        }
        else if(pid == 0 )
        {
        	printf("Please enter a number:");
        	scanf("%d",&n);
		printf("%d ",n);
        	for(i=0;i<=100;i++)
           	{
           		if(n%2==0)
           		{
              			n = n /2;
                      		a[i]=n;
           		}
           		else
           		{
                      		n = 3 * n + 1;
                      		a[i]=n;
           		}

           		printf("%d ",a[i]);
           		
			if(a[i]==1)
			{
				printf("\n");
           			break;
			}
    	   	}
        }
        else
        {
                wait(NULL);
                printf("Child complete!\n");
        }

  return 0;
}


