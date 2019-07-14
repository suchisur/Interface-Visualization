#include<iostream>
#include<cstring>

using namespace std;

int main(){

	unsigned char buf[4];
	float test;
	buf[0]=0x00;
	buf[1]=0x00;
	buf[2]=0x80;
	buf[3]=0x40;
	memcpy(&test,buf,sizeof(test));
	cout<<test;
}