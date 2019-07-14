#include <iostream>
#include<cstring>
#include<string.h>

using namespace std;


struct  A{
	int dtype;

	union value
	{
		int v;
		float fv;
		char cs[5];
	}value;
};


int main()
{
	struct A interface[5];
	unsigned char buf[20];


	for(int i=0;i<20;i++)
	{
		buf[i]=0x01;
	}
	//1-float, 0-integer
    interface[0].dtype=0;
    interface[1].dtype=0;
    interface[2].dtype=1;
    interface[3].dtype=0;
    interface[4].dtype=2;



     for(int i=0;i<5;i++){
     	
     	switch(interface[i].dtype){
     		case 0:
     			int val1;
     			memcpy(&val1,buf+i*4,sizeof(int));
     			interface[i].value.v=val1;
     			break;
     		case 1:
     			float val2;
     			memcpy(&val2,buf+i*4,sizeof(float));
     			interface[i].value.fv=val2;
     			break;
     		case 2:
     			char val3[5];
     			memcpy(&val3,buf+i*4,strlen(interface[i].value.cs)+1);
     			strcpy(interface[i].value.cs,val3);

     	}

     }
       for(int i=0;i<5;i++){
     	switch(interface[i].dtype){
     		case 0:
     			cout<<interface[i].value.v<<endl;;
     			break;
     		case 1:
     			cout<<interface[i].value.fv<<endl;

     			break;
     		case 2:
     			cout<<interface[i].value.cs<<endl;
     			break;

     	}

     }


}

