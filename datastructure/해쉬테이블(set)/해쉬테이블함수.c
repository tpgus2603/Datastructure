//#include<stdio.h>
//
////�ؽ��Լ� �۵��ͤ��� 
//typedef struct _empInfo {
//	int empNum;
//	int age;
//}EmpInfo;
//int GetHashValue(int empNum) { //���� ������ Ű�� ���� ������ �ٲٴ� �ؽ��Լ� 
//	return empNum % 100;
//}
//int main() {
//	EmpInfo empInfoArr[100];
//	EmpInfo emp1 = { 20220033,30 };
//	EmpInfo emp2 = { 20120001,41 };
//	EmpInfo emp3 = { 20230034,30 };
//
//	EmpInfo r1, r2, r3;
//
//	empInfoArr[GetHashValue(emp1.empNum)] = emp1;
//	empInfoArr[GetHashValue(emp2.empNum)] = emp2;
//	empInfoArr[GetHashValue(emp3.empNum)] = emp3;
//	
//	r1 = empInfoArr[GetHashValue(20220033)];
//	r2 = empInfoArr[GetHashValue(20120001)];
//	r3 = empInfoArr[GetHashValue(20230034)];
//
//
//
//}