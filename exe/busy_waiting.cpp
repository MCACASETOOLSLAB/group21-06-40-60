#include<stdio.h>
#include<windows.h>
using namespace std;
int philospher[5]={1,2,3,4,5},spoons[5]={1,1,1,1,1};

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
void paint(int n)
{
   SetConsoleTextAttribute(h,n);
}

void call()
{
    int i;
    printf("\n\t\t\t\t\t\t\t*****RESOURCE DETAILS*****\n");
    printf("\n\t\tPHILOSPHER: ");
    for(i=0;i<5;i++)
    {
         printf("\t\t%d",philospher[i]);
    }
    printf("\n\n\t\tSPOONS: ");
    for(i=0;i<5;i++)
    {
       printf("\t\t%d",spoons[i]);
    }
}
void release(int a,int n)
{
  paint(a);
  switch(n)
  {
  	case 1:
  		MessageBox(NULL,"RESOURCE RELEASED BY PHILOSOPHER 1","STATUS",MB_OK|MB_ICONINFORMATION);
  		spoons[0]=spoons[1]=spoons[4]=1;
  		call();
		break;
  		
  	case 2:
  		MessageBox(NULL,"RESOURCE RELEASED BY PHILOSOPHER 2","STATUS",MB_OK|MB_ICONINFORMATION);
  		spoons[0]=spoons[1]=spoons[2]=1;
  		call();
		break;
		  
	case 3:
  		MessageBox(NULL,"RESOURCE RELEASED BY PHILOSOPHER 3","STATUS",MB_OK|MB_ICONINFORMATION);
  		spoons[1]=spoons[2]=spoons[3]=1;
  		call();
		break;
		  
	case 4:
  		MessageBox(NULL,"RESOURCE RELEASED BY PHILOSOPHER 4","STATUS",MB_OK|MB_ICONINFORMATION);
  		spoons[2]=spoons[3]=spoons[4]=1;
  		call();
		break;
		  
	case 5:
  		MessageBox(NULL,"RESOURCE RELEASED BY PHILOSOPHER 5","STATUS",MB_OK|MB_ICONINFORMATION);
  		spoons[3]=spoons[4]=spoons[0]=1;
  		call();
		break;	  	  	  	
  		
  }
}

void start(int a,int i)
{
  int flag=0;
  paint(a);
  switch(i)
     {
       case 1: 
         if(spoons[1]!=1 || spoons[4]!=1)
            {
               MessageBox(NULL,"SORRY!!!PHILOSOPHER 1 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR PHILOSOPHER 1","STATUS",MB_OK|MB_ICONINFORMATION);
         spoons[0]=2,spoons[1]=spoons[4]=0;
         call();
         printf("\n\n\t\t\tPHILOSOPHER 1 IS CURRENTLY DINNING....\n\n");
         flag=1;
         break;
         
       case 2: 
         if(spoons[0]!=1 || spoons[2]!=1)
            {
               MessageBox(NULL,"SORRY!!!PHILOSOPHER 2 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR PHILOSOPHER 2","STATUS",MB_OK|MB_ICONINFORMATION);
         spoons[1]=2,spoons[0]=spoons[2]=0;
         call();
         printf("\n\n\t\t\tPHILOSOPHER 2 IS CURRENTLY DINNING....\n\n");
         flag=2;
         break;
		 
	   case 3: 
         if(spoons[1]!=1 || spoons[3]!=1)
            {
               MessageBox(NULL,"SORRY!!!PHILOSOPHER 3 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR PHILOSOPHER 3","STATUS",MB_OK|MB_ICONINFORMATION);
         spoons[2]=2,spoons[1]=spoons[3]=0;
         call();
         printf("\n\n\t\t\tPHILOSOPHER 2 IS CURRENTLY DINNING....\n\n");
         flag=3;
         break;
		 
	   case 4: 
        if(spoons[2]!=1 || spoons[4]!=1)
            {
               MessageBox(NULL,"SORRY!!!PHILOSOPHER 4 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR PHILOSOPHER 4","STATUS",MB_OK|MB_ICONINFORMATION);
         spoons[3]=2,spoons[2]=spoons[4]=0;
         call();
         printf("\n\n\t\t\tPHILOSOPHER 4 IS CURRENTLY DINNING....\n\n");
         flag=4;
         break;
		 
	   case 5: 
         if(spoons[3]!=1 || spoons[0]!=1)
            {
               MessageBox(NULL,"SORRY!!!PHILOSOPHER 5 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR PHILOSOPHER 5","STATUS",MB_OK|MB_ICONINFORMATION);
         spoons[4]=2,spoons[3]=spoons[0]=0;
         call();
         printf("\n\n\t\t\tPHILOSOPHER 5 IS CURRENTLY DINNING....\n\n");
         flag=5;
         break;	 	 	   
         
       default:
	     printf("\n\n\t\tINVALID PHILOSOPHER TABLE NO. ENTERED....\n\n");   
         
     }
 }

int main()
{
   paint(12);
   int n,i,num,flag=0;
   call();
  do
   {
          printf("\n\n1.ENTER PHILOSOPHER TABLE NO.\n");
		  printf("2.RELEASE THE RESOURCE\n");
		  printf("3.EXIT");
          printf("\n\n\tENTER YOUR CHOICE NO:\t");
          scanf("%d",&n);
          switch(n)
          {
            case 1:
            	printf("\n\tENTER THE PHILOSPHER TABLE NO. WHO WILL DINE:");
            	scanf("%d",&i);
		        start(13,i);
		        flag=1;
		        break;
            
			case 2:
				printf("\n\n\tENTER THE PHILOSPHER TABLE NO. FOR RELEASE THE SPOONS:");
                scanf("%d",&num);
                if(flag==0)
                  {
                    MessageBox(NULL,"RESOURCE ALREADY AVAILABLE","STATUS",MB_OK|MB_ICONERROR);
                    break;
                  }

                if(num!=i)
                  {
                    MessageBox(NULL,"THIS PHILOSOPHER IS IN BUSY WAITING","STATUS",MB_OK|MB_ICONERROR);
                    break;
                  }
                release(14,num);
                flag=0;
                break;
          }

  }while(n!=3);
}

    
