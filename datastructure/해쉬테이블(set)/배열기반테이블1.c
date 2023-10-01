//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//typedef struct _empInfo {
//	int empNum;
//	int age;
//}EmpInfo;
//
//int main() {
//	EmpInfo empInfoArr[1000];
//	EmpInfo ei;
//	int eNum;
//	printf("사번과 나이 입력: ");
//	scanf("%d %d", &(ei.empNum), &(ei.age));   //사원 정보 저장 일시 
//	empInfoArr[ei.empNum] = ei;   //배열에 사원정보 저장
//	printf("확인하고픈 직원의 사번 입력: ");
//	scanf("%d", &eNum);
//	ei = empInfoArr[eNum];  //탐색 
//	printf("사번: %d 나이 %d\n", ei.empNum, ei.age);
//	return 0;
//
//}