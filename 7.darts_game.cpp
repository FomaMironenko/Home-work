#include <iostream>

using namespace std;

int darts_game(int N){
	int count=0;
	int M[500*N][6];

	for(int i=1; i<=N/2; i++){
		for(int j=1; j<=N-2*i; j++){
			for(int k=1; k<=N-2*i+j; k++){

				if (2*i+j+k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=1;
					M[count][4]=k;
					M[count][5]=1;
					count++;
				}
				if (2*i+j+2*k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=1;
					M[count][4]=k;
					M[count][5]=2;
					count++;
				}
				if (2*i+j+3*k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=1;
					M[count][4]=k;
					M[count][5]=3;
					count++;
				}

				if (2*i+3*j+k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=3;
					M[count][4]=k;
					M[count][5]=1;
					count++;
				}
				if (2*i+2*j+k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=2;
					M[count][4]=k;
					M[count][5]=1;
					count++;
				}

				if (2*i+2*j+2*k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=2;
					M[count][4]=k;
					M[count][5]=2;
					count++;
				}

				if (2*i+3*j+2*k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=3;
					M[count][4]=k;
					M[count][5]=2;
					count++;
				}

				if (2*i+2*j+3*k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=2;
					M[count][4]=k;
					M[count][5]=3;
					count++;
				}
				if (2*i+3*j+3*k==N) {
					M[count][0]=i;
					M[count][1]=2;
					M[count][2]=j;
					M[count][3]=3;
					M[count][4]=k;
					M[count][5]=3;
					count++;
				}
			}
		}
	}

	for(int i=1; i<=N/2; i++){
		for(int j=0; j<=N-2*i; j++){
			if (2*i+j==N) {
				M[count][0]=i;
				M[count][1]=2;
				M[count][2]=j;
				M[count][3]=1;
				M[count][4]=0;
				M[count][5]=1;
				count++;
			}
			else if (2*i+2*j==N) {
				M[count][0]=i;
				M[count][1]=2;
				M[count][2]=j;
				M[count][3]=1;
				M[count][4]=0;
				M[count][5]=1;
				count++;
			}
			else if (2*i+3*j==N) {
				M[count][0]=i;
				M[count][1]=2;
				M[count][2]=j;
				M[count][3]=3;
				M[count][4]=0;
				M[count][5]=1;
				count++;
			}
		}
	}
	cout<<count<<endl;

	for(int i=0; i<count; i++){

		for(int j=2; j>-1; j--){
			if (M[i][2*j+1]==2){
				cout<<"D";
			}
			else {if (M[i][2*j+1]==3){
				cout<<"T";
			}
			}
			if (M[i][2*j]>0){
				cout<<M[i][2*j]<<" ";
			}
		}
		cout<<endl;
	}
	return count;
}

int main() {
	darts_game(200);
	return 0;
}
