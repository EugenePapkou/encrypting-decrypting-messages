/* Write a program for encrypting and decrypting messages using the specified method.
Encrypt the text as follows: write a message into the matrix in a spiral counter-clockwise, starting from the outside. Write the result of line-by-line matrix reading into the string. The size of matrix depends on length of a message.
Decrypt the text.

task_10.05.2010 */

#include "stdafx.h"
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
void Coding(); // input a message, encrypting a message, display an encrypted message
void Decoding(); // input an encrypted message, decrypting a message, display a decrypted message
int UserQuits(); // exit from program
char Message[300];
char cypher[30][30];
int p, q, i, j, m, v;

#define FALSE 0
#define TRUE 1

int main(void)
{
	int quitting = FALSE; setlocale(0, "");

	while(!quitting)
	{
Menu:	printf("\nTo encrypt a message press \"1\"\nTo decrypt a message press \"0\"\nTo exit press \"е\"\n\n");
		fflush(stdin);
		switch(getchar())
		{
		case '1':
			Coding();
			break;
		case '0':
			Decoding();
			break;
		case 'e':
			goto Quit;
		default:
			printf("Wrong selection. Try again please!");
			break;
		}
		quitting = UserQuits(); 
	}
Quit:
	return 0;
}

void Coding() // input a message, encrypting a message, display an encrypted message
{
	fflush(stdin);
	printf("\nEnter a message:\n");
	gets(Message); // input a message
	
	p = 0; q = 0; // encrypting
	m = ceil(pow(strlen(Message), 0.5)); // size of matrix
	v = 0; j = 0;
	while (m >= 1)
	{
		for(i = q, v; i < m; i++, v++)
			cypher[i][j] = Message[v];
		i--;
		
		for(j = p + 1, v; j < m; j++, v++)
			cypher[i][j] = Message[v];
		j--;
		
		for(i = m - 2, v; i >= q; i--, v++)
			cypher[i][j] = Message[v];
		i++;

		for(j = m - 2, v; j >= p+1; j--, v++)
			cypher[i][j] = Message[v];
		j++;

		m -= 1;
		++p;
		++q;
	}
	printf("\nEncrypted message:\n\n");
	for(i = 0; i <= ceil(pow(strlen(Message), 0.5)) - 1; i++) // printing an encrypted message
		for(j = 0; j <= ceil(pow(strlen(Message), 0.5)) - 1; j++)
			printf("%c", cypher[i][j]);
		
	for(i = 0; i <= 29; i++) 
		for(j = 0; j <= 29; j++)
			cypher[i][j] = ' '; // array cleaning
	for(v = 0; v <= 299; v++) // string cleaning
		Message[v] = ' ';
}

void Decoding() // input an encrypted message, decrypting a message, display a decrypted message
{
	fflush(stdin);
	printf("\nEnter an encrypted message:\n");
	gets(Message); // input a message
	
	v = 0;
	m = ceil(pow(strlen(Message), 0.5)); // size of matrix
	
	for(i = 0; i <= m - 1; i++) // line-by-line message transfer to the matrix
		for (j = 0, v; j <= m - 1; j++, v++)
			cypher[i][j] = Message[v];
		
	p = 0; q = 0; // decrypting
	v = 0; j = 0;
	while (m >= 1)
	{
		for(i = q, v; i < m; i++, v++)
			Message[v] = cypher[i][j];
		i--;
		
		for(j = p + 1, v; j < m; j++, v++)
			Message[v] = cypher[i][j];
		j--;
		
		for(i = m - 2, v; i >= q; i--, v++)
			Message[v] = cypher[i][j];
		i++;

		for(j = m - 2, v; j >= p+1; j--, v++)
			Message[v] = cypher[i][j];
		j++;

		m -= 1;
		++p;
		++q;
	}
	for(i = 0; i <= 29; i++) 
		for(j = 0; j <= 29; j++)
			cypher[i][j] = ' '; // array cleaning
		
	printf("\nDecrypted message:%s\n", Message); // printing a decrypted message

	for(v = 0; v <= 299; v++) // string cleaning
		Message[v] = ' ';
}

int UserQuits() // exit from program
{
	char w;

	do
	{
		printf("\nContinue? Y/N\n");
		fflush(stdin);
		w = toupper(getchar());
	}
	while ((w != 'Y') && (w != 'N'));

	return (w == 'N');
}
