/* Hexadecimal Convert
   Billy Pham*/

/*The program will ask the user for an integer and then display the hex representation of the number
 Using bit shifting and masking operations
 Prompt the user for an integer number and print out its hex representation*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/*prototype*/
char *to_hex(int n);

/*Compiler funtion*/
int main()
{
	int n;
	printf("Enter a Decimal: ");
	scanf("%d", &n);
	printf("A Hexadecimal: %s\n", to_hex(n));
	return 0;
}

/*Function to convert from a decimal to a hex*/
char *to_hex(int n)
{
	int i;
	/*Array String characters*/
	char characters[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}; 
	
	/*create a char array*/
	char *arr = malloc(2*sizeof(int)+1); ;
	int temp;
	
	/*leave the high-order 4 bits in the low-order bit positions*/
	temp = n >> 28;
	
	/*clear all but the low-order four bits*/
	temp = temp&0xf; /*0xf: bitmask*/
	
	/*Store in index 0 of an array arr*/
	*(arr+0) = characters[temp];  /*Get value at index of the array characters from value of temp*/ 
	
	/*Store in the rest of index of the array arr*/
	for(i = 1; i<=7; i++)
	{
		/*get next hex digit*/
		n = n<<4; 
		
		/*leave the high-order 4 bits in the low-order bit positions*/
		temp = n>>28;
		
		/*clear all but the low-order four bits*/
		temp = temp&0xf;
		
		/*store value hex in array arr*/
		*(arr + i) = characters[temp];
	}
	/*store the '\0' terminator*/
	*(arr+i) = '\0';
	
	/*return a pointer to the char array*/
	return arr;
}

