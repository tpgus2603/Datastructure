#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"���.h"

int GetSsn(Person* p) {
	return p->ssn;
}
void ShowPerInfo(Person* p) {
	if (p != NULL) {
		printf("�ֹε�Ϲ�ȣ : %d\n", p->ssn);
		printf("�̸�: %s\n", p->name);
		printf("�ּ�: %s\n", p->addr);
	}
	else
		printf("NO Data");
}
Person* MakePersonData(int ssn, char * name, char* addr) { //�迭�� ���� �Ҵ����� ����..
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;

}