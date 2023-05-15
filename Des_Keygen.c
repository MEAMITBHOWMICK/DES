#include <stdio.h>
#include<stdlib.h>


#include "Des.h"  //Header file for including the permutation and number of shift of each round


FILE *ptr;  //pointer for pointing the round key file 


void Key_perm2(char *key, int round)
{
	//Function for the applying PC-2 and generating each round key
	int i, k;
	char round_key[6]={0}, b=0, byte=0, bit=0;
	
	
	//Applying PC-2
	for(i=0;i<6;i++)
	{
		k=7;
		while(k--)
		{
			int x = sub_key_permutation[8*i + (7-k)] - 1;
			byte=x/7;
			bit=x%8;
			b=((key[byte]>>(7-bit)) & 1)<<k;
			round_key[i]+=b;
			b=0;
		}
	}
	
	
	//Writting the round key in a file
	for(i=0;i<6;i++)
	{
		fprintf(ptr, "%c" , round_key[i]);
	}
	
	
	for(i=0;i<6;i++) round_key[i]=0;
}


void round_key_rotation(char *lh, char *rh, int round)
{
	//Funtion for applying circular shift
	int no_of_shift=key_shift_sizes[round], i;
	char c=0, b=0;
	
	
	if(no_of_shift==1)
	{
		b=(lh[0]>>7)&1;
		for(i=0;i<3;i++)
		{
			c=(lh[i+1]>>7)&1;
			lh[i]<<=1;
			lh[i] |= c;
		}
		lh[3] <<=1;
		lh[3] |=b;
		
		
		b=(rh[0]>>7)&1;
		for(i=0;i<2;i++)
		{
			c=(rh[i+1]>>7)&1;
			rh[i]<<=1;
			rh[i] |= c;
		}
		rh[2] <<=1;
		rh[2] |=b;
	}
	else
	{
		b=(lh[0] & 0Xc0)>>6;
		for(i=0;i<3;i++)
		{
			c=(lh[i+1] & 0Xc0)>>6;
			lh[i]<<=2;
			lh[i] |= c;
		}
		lh[3] <<=2;
		lh[3] |=b;
		
		b=(rh[0] & 0Xc0)>>6;
		for(i=0;i<2;i++)
		{
			c=(rh[i+1] & 0Xc0)>>6;
			rh[i]<<=2;
			rh[i] |= c;
		}
		rh[2] <<=2;
		rh[2] |=b;
	}
}


int main()
{
	char key[7];
	int i;
	
	
	for(i=0;i<7;i++) key[i]=rand()%256;  //generating master key of 56 bit.
	
	
	ptr=fopen("DesRoundKey.txt", "w");  //Used to point the file that stores all the round key
	
	
	for(i=0;i<16;i++)
	{
		round_key_rotation(&key[0], &key[4], i);  //Callling the function for the circular shift
		Key_perm2(key, i);  //Calling the function for applying PC-2 to the and extracting each round key
	}	
}
