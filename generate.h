#include"above.h"
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<Windows.h>
using namespace std;
void ifsit(int a,int b){
	int k=rand()%20;
	if(k==0){seat[a][b]=1;}
}
void countpeople(){
	int peo=0;
	for(int i=1;i<21;i++){
		for(int j=1;j<21;j++){
			if(seat[i][j]==1){
				peo++;
			}
	}
}
	cout<<peo;
}
void generate(){
	for(int i=1;i<21;i++){
		for(int j=1;j<21;j++){
			ifsit(i,j);//每代有5%的几率一个座位被坐人
		}
	}
	Sleep(10);
	system("cls");
	for(int i=0;i<22;i++){
		for(int j=0;j<22;j++){
			if(seat[i][j]==0){
				cout<<"  ";
			}
			else if(seat[i][j]==1){
				cout<<"人";
			}
			else if(seat[i][j]==2){
				cout<<"■";
			}
		}
		cout<<endl;
	}
	countpeople();
}
