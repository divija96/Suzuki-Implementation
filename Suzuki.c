#include <stdio.h>
#include <omp.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int fmask(int label[10][10],int matrix[10][10],int m,int n,int i,int j, int T[50]){

	int a,b,c,min;
	a=i-1;
	b=j-1;
	c=j+1;
	
	if(a!=-1 && b!=-1 && c!=n){
		
		if(matrix[i][b]==0 && matrix[a][b]==0 && matrix[a][c]==0 && matrix[a][j]==0 ){
			return 0;
		}
		else{

			min=100;
			if(T[label[i][b]]!=0){
				min=T[label[i][b]];
			}
			if(T[label[a][b]] < min && T[label[a][b]]!=0){
				min=T[label[a][b]];
						
			}
			if(T[label[a][c]] < min && T[label[a][c]]!=0){
				min=T[label[a][c]];
			}
			if(T[label[a][j]] < min && T[label[a][j]]!=0){
				min=T[label[a][j]];
			}
			return min;
		}
	}
	else{

		if(a==-1 && b==-1){
			return 0;
		}
		if(a==-1){
			return T[label[i][b]];
		}
		if(b==-1){

			if(T[label[a][j]] <= T[label[a][c]]){

				if(T[label[a][j]]==0){
					return T[label[a][c]];
				}
				else{
					return T[label[a][j]];
				}
			}
			else{	

				if(T[label[a][c]]==0){
					return T[label[a][j]];
				}
				else{
					return T[label[a][c]];
				}
			}
		}
		if(c==n)
		{
			
			min=100;
			if(T[label[i][b]]!=0){
				min=T[label[i][b]];
			}
			if(T[label[a][b]] < min && T[label[a][b]]!=0){
				min=T[label[a][b]];
			}
			if(T[label[a][j]] < min && T[label[a][j]]!=0){
				min=T[label[a][j]];
			}
			if(min == 100){
				return 0;
			}
			else{
				return min;
			}
		}
		return 0;
	}

}
int bmask(int label[10][10],int matrix[10][10],int m,int n,int i,int j, int T[50]){

	int a,b,c,min;
	a=i+1;
	b=j-1;
	c=j+1;

	if(a!=m && b!=-1 && c!=n){

		if(matrix[i][c]==0 && matrix[a][b]==0 && matrix[a][c]==0 && matrix[a][j]==0 ){
			return 0;
		}
		else{

			min=100;
			if(label[i][c]!=0){
				min=label[i][c];
			}
			if(label[a][b] < min && label[a][b]!=0){
				min=label[a][b];
			}
			if(label[a][c] < min && label[a][c]!=0){
				min=label[a][c];
			}
			if(label[a][j] < min && label[a][j]!=0){
				min=label[a][j];
			}
			return min;
		}
	}
	else
	{
		if(a==m && c==n){
			return 0;
		}
		if(a==m){
			return label[i][c];
		}
		if(c==n){
			if(label[a][j] <= label[a][b]){

				if(label[a][j]==0){
					return label[a][b];
				}
				else{
					return label[a][j];
				}
			}
			else{

				if(label[a][b]==0){
					return label[a][j];
				}
				else{
					return label[a][b];
				}
			}
		}
		if(b==-1)
		{
			min=100;
			if(label[i][c]!=0){
				min=label[i][c];
			}
			if(label[a][c] < min && label[a][c]!=0){
				min=label[a][c];
			}
			if(label[a][j] < min && label[a][j]!=0){
				min=label[a][j];
			}
			if(min == 100){
				return 0;
			}
			else{
				return min;
			}
		}
		return 0;
	}
}
void fassignT(int T[50], int label[10][10],int m,int n,int i,int j, int val){

	int a,b,c,min;
	a=i-1;
	b=j-1;
	c=j+1;
	if(a!=-1 && b!=-1 && c!=n){
		
		
		if(label[i][b]!=0){
			T[label[i][b]]=val;
		}
		if(label[a][b]!=0){
			T[label[a][b]]=val;
		}
		if(label[a][c]!=0){
			T[label[a][c]]=val;
		}
		if(label[a][j]!=0){
			T[label[a][j]]=val;
		}
		
	}
	else{
        if(a==-1 && b==-1){
        	return;
        }
		if(a==-1){
			if(label[i][b]!=0){
				T[label[i][b]]=val;
			}
		}
		if(b==-1){

			if(label[a][j]!=0){
				T[label[a][j]]=val;
			}
			if(label[a][c]!=0){
				T[label[a][c]]=val;
			}
			
		}
		if(c==n)
		{
			
			if(label[i][b]!=0){
				T[label[i][b]]=val;
			}
			if(label[a][b]!=0){
				T[label[a][b]]=val;
			}
			if(label[a][j]!=0){
				T[label[a][j]]=val;
			}
		}
	}
}
void bassignT( int T[50], int label[10][10],int m,int n,int i,int j, int val ){

	int a,b,c,min;
	a=i+1;
	b=j-1;
	c=j+1;
    if(a==m && b==-1)
    {
		if(label[i][c]!=0){
			T[label[i][c]]=val;
		}
		return;
    }
	if(a!=m && b!=-1 && c!=n){
		if(label[i][c]!=0){
			T[label[i][c]]=val;
		}
		if(label[a][b]!=0){
			T[label[a][b]]=val;
		}
		if(label[a][c]!=0){
			T[label[a][c]]=val;
		}
		if(label[a][j]!=0){
			T[label[a][j]]=val;
		}
	}
	else
	{
		if(a==m && c==n){
			return;
		}
		
		if(a==m){
			if(label[i][c]!=0){
				T[label[i][c]]=val;
			}
		}
		if(c==n){

			if(label[a][j]!=0){
				T[label[a][j]]=val;
			}
			if(label[a][b]!=0){
				T[label[a][b]]=val;
			}
			
		}
		if(b==-1)
		{
			if(label[i][c]!=0){
				T[label[i][c]]=val;
			}
			if(label[a][c]!=0){
				T[label[a][c]]=val;
			}
			if(label[a][j]!=0){
				T[label[a][j]]=val;
			}
		}
	}	
}
int suzuki(int matrix[10][10],int m, int n)
{
	double time_spent,t1,t2;
   struct timespec tp,tp1;
	int tid=0,label[10][10],i,j,val,counter,flag,T[50]={0};
	counter=0;
	int nthreads=2;
	omp_set_num_threads(nthreads);
	int condition[2][100];
	int chunk=n/nthreads;
	for(i=0;i<2;i++)
	{
		for(j=0;j<m;j++)
			condition[i][j]=0;
	}
	condition[0][0]=1;
	clock_gettime(CLOCK_REALTIME,&tp);
   t1 = (((double)tp.tv_sec) * 1000000) + (((double)tp.tv_nsec) / 1000) ;
	#pragma omp parallel default(shared) private(tid,i,j) firstprivate(chunk)
	for(i=0;i<m;i++){
		#pragma omp for 
		for(j=0;j<n;j++){
			tid=omp_get_thread_num();
			while(condition[tid][i]!=1)
				wait();

				if(matrix[i][j]==0){
				label[i][j]=0;
			}
			else{
				
				val=fmask(label,matrix,m,n,i,j,T);
				if(val == 0){
					#pragma omp critical 
					{
					counter++;
					T[counter]=counter;
					label[i][j]=counter;
				}
				}
				else{

					label[i][j]=val;
					fassignT(T,label,m,n,i,j,val);
				}

			}	
			if(j==((tid+1)*chunk)-1&&i!=m-1&&j!=n-1){
				condition[tid+1][i]=1;
				condition[tid][i+1]=1;
			}
			else if(j==((tid+1)*chunk)-1&&i!=m-1){
				condition[tid][i+1]=1;
			}
			else if(j==((tid+1)*chunk)-1&&j!=n-1){
				condition[tid+1][i]=1;
			}
		}
	}
	flag=1;
	while(flag){
		for(i=0;i<2;i++)
		{
			for(j=0;j<m;j++)
				condition[i][j]=0;
		}
		condition[0][0]=1;
	#pragma omp parallel default(shared) private(tid,i,j) firstprivate(chunk)	
		for(i=0;i<m;i++){
				#pragma omp for 
			for(j=0;j<n;j++){
				tid=omp_get_thread_num();
				while(condition[tid][i]!=1)
				wait();

				if(matrix[i][j]!=0){
					val=bmask(label,matrix,m,n,i,j,T);
					if(val !=0 && val < label[i][j]){
						flag=0;
						label[i][j]=val;
					}
					if(val!=0)
					{
						#pragma omp critical
						{
						bassignT(T,label,m,n,i,j,val);
						}
					}
				}
				if(j==((tid+1)*chunk)-1&&i!=m-1&&j!=n-1){
				condition[tid+1][i]=1;
				condition[tid][i+1]=1;
				}
				else if(j==((tid+1)*chunk)-1&&i!=m-1){
					condition[tid][i+1]=1;
				}
				else if(j==((tid+1)*chunk)-1&&j!=n-1){
					condition[tid+1][i]=1;
				}
			}
		}
		for(i=0;i<2;i++)
		{
			for(j=0;j<m;j++)
				condition[i][j]=0;
		}
		condition[0][0]=1;
		#pragma omp parallel default(shared) private(tid,i,j) firstprivate(chunk)
		for(i=0;i<m;i++){
			#pragma omp for 
			for(j=0;j<n;j++){
				tid=omp_get_thread_num();
				while(condition[tid][i]!=1)
				wait();

				if(matrix[i][j]!=0){
					val=fmask(label,matrix,m,n,i,j,T);
					if(val!=0 && val < label[i][j]){
						flag=0;
						label[i][j]=val;
					}
					if(val!=0)
					{
						#pragma omp critical
						{
						fassignT(T,label,m,n,i,j,val);
						}
					}
				}
				if(j==((tid+1)*chunk)-1&&i!=m-1&&j!=n-1){
				condition[tid+1][i]=1;
				condition[tid][i+1]=1;
				}
				else if(j==((tid+1)*chunk)-1&&i!=m-1){
					condition[tid][i+1]=1;
				}
				else if(j==((tid+1)*chunk)-1&&j!=n-1){
					condition[tid+1][i]=1;
				}
			}
		}
		flag=1-flag;
	}
	printf("The Result is \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ", label[i][j]);
		}
		printf("\n");
	}
	clock_gettime(CLOCK_REALTIME,&tp1);
  t2 = (((double)tp1.tv_sec) * 1000000) + (((double)tp1.tv_nsec) / 1000) ;
  time_spent = t2 -t1;
  printf("Time Spent : %f\n",time_spent);	
	

}
		
  

	
int main(){

	int matrix[10][10],i,j,n,m;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	suzuki(matrix,m,n);
	return 0;
}
