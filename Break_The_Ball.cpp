#include <iostream>
#include <math.h>  //mathematical library......

using namespace std;
 //*****************************************************************************************************************************
//In this jumping search algorithm I start with 1 st floor(not the ground floor)..Because we practically start with 1 st floor....
//******************************************************************************************************************************
void jumpSearch(int arr[],int m,int target[],int iterations[]){  //function of jump and searching the target element...


   for(int e=0;e<100;e++)  //check trials for each floor
   {
    int steps=1;

    for(int k=0;k<100;)  //k is the increment of jumping...
    {

    if(target[e]==arr[k])
    {
		if(e==k && e!=0)  //if it's a jumping step....
		{
			iterations[e]=iterations[e-1]; //because if ball breaks in jumping step,we want search before jumping step+1 to this jumping step-1 ...so that jumping step trials equal previous floor trials..
			k=100;   //to stop seaching...
		}
		else
		{
			     iterations[e]=steps;   //assign trials....
     			 k=100;   //to stop seaching...
		}


    }
    else if(target[e]>arr[k]) 
    {

        k=k+m;
        if(k==100)  //I got last jump as last floop..(It should be 101th floor but there are no 101 so I get last floor) and k is the index..
        {
            k=99;
        }
        steps=steps+1;
    }

    else{

        int u;  //variable in for loop... 
            if(k==99)   //last jump is a 9 jump one...so normal u will change in for loop ..so I check it if it's the last jump...
            {
                u=91;  //linear search start..
            }
            else
            {
                u=k-m+1;     //linear search start..
            }
        for(;u<k;u++)
        {
            steps=steps+1;
            if(target[e]==arr[u])
            {
                iterations[e]=steps;   //asign trials...
                k=100;  //to stop searching...
            }

        }


        }

   }
   }






}

int main()  //main function...
{
    int m;  //jump steps....
    int target[100];  //target searching value...
    int arr[100];     //floors array...
    int iterations[100];  //no of trials storing array...


    for(int h=0;h<100;h++)
    {
        arr[h]=h+1;
    }
    for(int r=0;r<100;r++)
    {
        target[r]=r+1;
    }

    m=sqrt(100);  //calculate the number of steps jump....
    jumpSearch(arr,m,target,iterations);  //call the jumpSearch function...

    for(int u=0;u<100;u++)  //output the each floor trials...
    {
       cout<<"Floor No : "<<u+1<<"  No of Trials : "<<iterations[u]<<endl;
    }

    return 0;


}
