#pragma once
#include"checkstop.h"
#include"generate.h"

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
