#include<stdio.h>
#include<stdlib.h>
void addition(long long int **t,long long int **t1,long long int **t2,long int r,long int c )
{
	long long int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			t2[i][j] = t1[i][j]+t[i][j];
 return;
}
void substraction(long long int **t,long long int **t1,long long int **t2,long long int r,long long int c)
{
	long long int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			t2[i][j] = t[i][j]-t1[i][j];
 return;
}
void print(long long int **t,long long int r,long long int c)
{
	long long int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%lld ",t[i][j]);}
	printf("\n");	
	}
	return;
}

void straussens_method(long long int **a,long long int **b,long long int **c,long long int n)
{
	long long int i,j;
long long int **temp = (long long int **)malloc(n*sizeof( int *));long long int **temp1 = (long long int **)malloc(n*sizeof(int *));long long int **temp2 = (long long int **)malloc(n*sizeof(int *));
long long int **temp3 = (long long int **)malloc(n*sizeof(int *));long long int **p1 = (long long int **)malloc(n*sizeof(int *));long long int **p2 = (long long int **)malloc(n*sizeof(int *));
long long int **p3 = (long long int **)malloc(n*sizeof(int *));long long int **p4 = (long long int **)malloc(n*sizeof(int *));long long int **p5 = (long long int **)malloc(n*sizeof(int *));
long long int **p6 = (long long int **)malloc(n*sizeof(int *));long long int **p7 = (long long int **)malloc(n*sizeof(int *));
	for( i=0;i<n;i++){
		temp[i] = (long long int *)malloc(n*sizeof(int));temp1[i] = (long long int *)malloc(n*sizeof(int));temp2[i] = (long long int *)malloc(n*sizeof(int));
		temp3[i] = (long long int *)malloc(n*sizeof(int));p1[i] = (long long int *)malloc(n*sizeof(int));p2[i] = (long long int *)malloc(n*sizeof(int));
		p3[i] = (long long int *)malloc(n*sizeof(int));p4[i] = (long long int *)malloc(n*sizeof(int));p5[i] = (long long int *)malloc(n*sizeof(int));
		p6[i] = (long long int *)malloc(n*sizeof(int));p7[i] = (long long int *)malloc(n*sizeof(int));
	}
	if(n==1){
		c[0][0] = a[0][0] * b[0][0];
		return;	
	}
	//p1=a(f-h)
	//f & h
	for(i=0;i<n/2;i++)
		for(j=n/2;j<n;j++)
			temp[i][j-n/2] = b[i][j];			

	for(i=n/2;i<n;i++)
		for( j=n/2;j<n;j++)
			temp1[i-n/2][j-n/2] = b[i][j];
			
	substraction(temp,temp1,temp2,n/2,n/2);
	
	//get a 

	for( i=0;i<n/2;i++)
		for(j=0;j<n/2;j++)
			temp3[i][j] = a[i][j];

	straussens_method(temp3,temp2,p1,n/2);
		
	//temp1 has 'h' , temp3 has 'a' currently
	//p2=(a+b)h	
	
		
	//get b

	for( i=0;i<n/2;i++)
		for( j=n/2;j<n;j++)
			temp2[i][j-n/2] = a[i][j];

	addition(temp2,temp3,temp2,n/2,n/2);	
	straussens_method(temp2,temp1,p2,n/2);

	//p3=(c+d)e
	
	//get c,d,e
	
	for( i=n/2;i<n;i++)
		for( j=0;j<n/2;j++)
			temp[i-n/2][j] = a[i][j];

	for( i=n/2;i<n;i++)
		for(j=n/2;j<n;j++)
			temp1[i-n/2][j-n/2] = a[i][j];
	
	addition(temp,temp1,temp,n/2,n/2);
	
	for(i=0;i<n/2;i++)
		for(j=0;j<n/2;j++)
			temp2[i][j] = b[i][j];
	straussens_method(temp,temp2,p3,n/2);

	//p4=d(g-e)
	//d in temp1 && e in temp2
	//get g

	for(i=n/2;i<n;i++)
		for(j=0;j<n/2;j++)
			temp[i-n/2][j] = b[i][j];

	substraction(temp,temp2,temp,n/2,n/2);
	
	straussens_method(temp1,temp,p4,n/2);
	
	//p5=(a+d)(e+h)
	//d in temp1 && e in temp2
	//get a & h
	
	for(i=0;i<n/2;i++)
		for(j=0;j<n/2;j++)
			temp[i][j] = a[i][j];
	
	addition(temp1,temp,temp,n/2,n/2);


	for(i=n/2;i<n;i++)
		for(j=n/2;j<n;j++)
			temp3[i-n/2][j-n/2] = b[i][j];

	addition(temp3,temp2,temp2,n/2,n/2);
	
	straussens_method(temp,temp2,p5,n/2);

	//p6=(b-d)(g+h)
	//h in temp3 && d in temp1 //get b,g
	
	
	for(i=0;i<n/2;i++)
		for(j=n/2;j<n;j++)
			temp2[i][j-n/2] = a[i][j];


	substraction(temp2,temp1,temp2,n/2,n/2);
	
	for(i=n/2;i<n;i++)
		for(j=0;j<n/2;j++)
			temp[i-n/2][j] = b[i][j];

	addition(temp,temp3,temp,n/2,n/2);
	
	straussens_method(temp2,temp,p6,n/2);

	//p7=(a-c)(e+f)

	for(i=0;i<n/2;i++)
		for(j=0;j<n/2;j++)
			temp[i][j] = a[i][j];

	for(i=n/2;i<n;i++)
		for(j=0;j<n/2;j++)
			temp1[i-n/2][j] = a[i][j];

	substraction(temp,temp1,temp1,n/2,n/2);

	for(i=0;i<n/2;i++)
		for(j=0;j<n/2;j++)
			temp2[i][j] = b[i][j];
	
	for(i=0;i<n/2;i++)
		for(j=n/2;j<n;j++)
			temp3[i][j-n/2] = b[i][j];

	addition(temp2,temp3,temp3,n/2,n/2);

	straussens_method(temp1,temp3,p7,n/2);

	//c matrix
	for( i=0;i<n/2;i++)
		for(j=0;j<n/2;j++)
			c[i][j] = p5[i][j] + p4[i][j] - p2[i][j] + p6[i][j];
	
	for( i=0;i<n/2;i++)
		for( j=0;j<n/2;j++)
			c[i][j+n/2] = p1[i][j] + p2[i][j];
	
	for( i=0;i<n/2;i++)
		for( j=0;j<n/2;j++)
			c[i+n/2][j] = p3[i][j] + p4[i][j];
	
	for( i=0;i<n/2;i++)
		for(j=0;j<n/2;j++)
			c[i+n/2][j+n/2] = p1[i][j] + p5[i][j] - p3[i][j] - p7[i][j];

}
int main()
{
	long long int n,t,i,j;
	scanf("%lld",&t);
	while(t--){
	scanf("%lld",&n);
	    
	    long long int **C = (long long int **)malloc(n * sizeof(int *));
	    long long int **A = (long long int **)malloc(n * sizeof(int *));
	    for (i=0; i<n; i++){
	         A[i] = (long long int *)malloc(n * sizeof(int));
		 C[i] = (long long int *)malloc(n * sizeof(int));
		}
	
	for(i=0;i<n;i++)	
		for( j=0;j<n;j++)
			scanf("%lld",&A[i][j]);


	straussens_method(A,A,C,n);

	print(C,n,n);
	}
return 0;
}
