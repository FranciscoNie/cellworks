#pragma once
int seat[22][22];
void initial(){
	for(int i=0;i<22;i++){
		seat[i][0]=2;
		seat[i][21]=2;
		seat[0][i]=2;
		seat[21][i]=2;
	}
}
bool existseat(int u){
	if(u==2){
	for(int i=1;i<21;i++){
		for(int j=1;j<21;j++){
			if(seat[i][j]==0&&seat[i][j+1]==0){return true;}
			if(seat[i][j]==0&&seat[i][j-1]==0){return true;}
			if(seat[i][j]==0&&seat[i+1][j]==0){return true;}
			if(seat[i][j]==0&&seat[i-1][j]==0){return true;}//只要发现两个挨着的座位，即判定存在
		}
	}
}
	if(u==3){
	for(int i=1;i<21;i++){
		for(int j=1;j<21;j++){
			if(seat[i][j]==0&&seat[i][j+1]==0&&seat[i-1][j]==0){return true;}
			if(seat[i][j]==0&&seat[i][j-1]==0&&seat[i-1][j]==0){return true;}
			if(seat[i][j]==0&&seat[i+1][j]==0&&seat[i][j-1]==0){return true;}
			if(seat[i][j]==0&&seat[i+1][j]==0&&seat[i][j+1]==0){return true;}//只要发现三个挨着的座位（这里判定成L形的），即判定存在
			if(seat[i-1][j]==0&&seat[i][j]==0&&seat[i+1][j]==0){return true;}
			if(seat[i][j-1]==0&&seat[i][j]==0&&seat[i][j+1]==0){return true;}//三连坐
		}
	}
}
	return false;
}
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
int main(){
	srand(clock());
	initial();
	int b;
	cin>>b;
	for(;;){
		generate();
		if(existseat(b)==false){
			break;
		}
	}
	system("pause");
}
