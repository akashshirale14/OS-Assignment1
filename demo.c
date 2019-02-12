#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


int main(int argc,char *argv[])
{
	int H,C,i,r;
	printf("Pid: %d Process starting\n",(int)getpid());
	printf("Pid: %d Parent Pid:%d\n",(int)getpid(),(int)getppid());
	H=atoi(argv[1]);
	C=atoi(argv[2]);
	printf("Pid: %d Height in the tree %d\n",(int)getpid(),H);
	printf("Pid: %d Creating %d children at height %d\n",(int)getpid(),C,H-1);

	 if(H>1)
	{   
		
    	for(i=0;i<C;i++)
    	{	
       			r=fork();
        	if(r<0)
        	{
        			fprintf(stderr, "Fork failed\n" );
        			exit(1);
        	}	
	        else if(r==0)
	        {
	           printf("child Pid:%d\n",(int)getpid());
	           char buffer1[10];
	           char buffer2[10];
	           H=H-1;
	           snprintf(buffer1,sizeof(buffer1),"%d",H);
	           snprintf(buffer2,sizeof(buffer2),"%d",C);
	           if(execl(argv[0],argv[0],buffer1,buffer2,NULL)==-1)
	           	  printf("error");
	        }
    			    		
    	}
    }
printf("Pid: %u Terminating at height %d\n",(int)getpid(),H);
    while(wait(NULL)>0);	

return 0;
}