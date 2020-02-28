#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()
void randData(double *dPtr ,int N,int M){

	for( int j = 0; j < N*M; j++){
		double y = rand()%101;
		*(dPtr+j) = y/100;
	}
}

void findColSum(const double *dPtr,double *result ,int N,int M){
	for(int i = 0; i < M; i++){
		
		*(result+i) = 0;
		//int j= 0;
		for (int j = i; j < N*M; j = j+M)
		{
			*(result+i) = *(result+i) + *(dPtr+j);	
		}
	}
	
}

void showData(double *dPtr,int N,int M){
	for( int j = 0; j < N*M; j++){
		if( j != 0 && j%M == 0) cout << "\n";
		cout << *(dPtr+j) << "\t";
	}
	cout << "\n";
}