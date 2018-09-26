#include<iostream>
using namespace std;
const int MAX=102;

int main() {
	int x,y,vx,vy;
	int i,j,k;
	int row,col;
	int a[MAX][MAX];
	cin>>col>>row;
	for(i=1;i<=row;i++)
		for(j=1;j<=col;j++)
			cin>>a[i][j];
	
	k=2;
	for(i=1;i<=col;i++){
		a[row+1][i]=k;
		k++;
	}

	for(i=row;i>0;i--){
		a[i][col+1]=k;
		k++;
	}
	for(i=col;i>0;i--){
		a[0][i]=k;
		k++;
	}
	for(i=1;i<=row;i++){
		a[i][0]=k;
		k++;
	}
	for(i=1;i<=col;i++){
		vy=-1;
		vx=0;
		x=i;
		y=row+1;
		do{
			x+=vx;
			y+=vy;
			if(a[y][x]==1)
			if(vx==0){
				vx=1;
				vy=0;
			}
			else{
				vy=-1;
				vx=0;
			}
		}
		while(a[y][x]==0||a[y][x]==1);
		cout<<a[y][x]-2<<endl;
	}
	for(i=row;i>0;i--){
		vy=0;
		vx=-1;
		x=col+1;
		y=i;
		do{
			x+=vx;
			y+=vy;
			if(a[y][x]==1)
			if(vx==0){
				vx=-1;
				vy=0;
			}
			else{
				vy=1;
				vx=0;
			}
		}
		while(a[y][x]==0||a[y][x]==1);
		cout<<a[y][x]-2<<endl;
	}
	for(i=col;i>0;i--){
		vy=1;
		vx=0;
		x=i;
		y=0;
		do{
			x+=vx;
			y+=vy;
			if(a[y][x]==1)
			if(vx==0){
				vx=-1;
				vy=0;
			}
			else{
				vy=1;
				vx=0;
			}
		}
		while(a[y][x]==0||a[y][x]==1);
		cout<<a[y][x]-2<<endl;
	}
	for(i=1;i<=row;i++){
		vy=0;
		vx=1;
		x=0;
		y=i;
		do{
			x+=vx;
			y+=vy;
			if(a[y][x]==1)
			if(vx==0){
				vx=1;
				vy=0;
			}
			else{
				vy=-1;
				vx=0;
			}
		}
		while(a[y][x]==0||a[y][x]==1);
		cout<<a[y][x]-2<<endl;
	}

	return 0;
}