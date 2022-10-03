#include <stdio.h>
typedef struct
{
	float coeff;
	int exp;
}poly;

poly term[100];

int main(void)
{
	int i=0, j=0, k, m, numOfPoly, numOfTerms;
	printf("ENTER THE NUMBER OF POLYNOMIALS FOR ADDITION: ");
	scanf("%d", &numOfPoly);
	printf("\n");
	while(numOfPoly)
	{
		printf("ENTER THE NUMBER OF TERMS: ");
		scanf("%d", &numOfTerms);
		printf("\nENTER THE CO-EFFICIENTS AND EXPONENTS: \n");
		k = 0;
		while(numOfTerms)
		{
			scanf("%f %d", &term[i].coeff, &term[i].exp);
			i++;
			k++;
			numOfTerms--;
		}
		j++;
		k--;
		printf("%d-th TERM IS: ",j);
		for(m=i-1;m>=i-k-1;m--)
		{
			printf("%.2fx*%d ", term[m].coeff, term[m].exp);
			if(m>i-k-1) printf(" + ");
		}
		printf("\n"); 
		numOfPoly--;
	}
	i--;
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<=i;k++)
		{
			if(term[j].exp == term[k].exp)
		{term[j]. coeff += term[k].coeff;
		 term[k].coeff = 0;
		}
	}
}
	printf("\nTHE ADDED POLYNOMIAL IS: "); 
	for(j=0; j<=i; j++) 
	{
		if(term[j].coeff > 0)
		{	printf("+ %.2fx^%d", term[j].coeff, term[j].exp);
		}
	}
	return 0;
}
