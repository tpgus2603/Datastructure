#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"사람.h"

int GetSsn(Person* p) {
	return p->ssn;
}
void ShowPerInfo(Person* p) {
	if (p != NULL) {
		printf("주민등록번호 : %d\n", p->ssn);
		printf("이름: %s\n", p->name);
		printf("주소: %s\n", p->addr);
	}
	else
		printf("NO Data");
}
Person* MakePersonData(int ssn, char * name, char* addr) { //배열은 서로 할당하지 못함..
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;

}