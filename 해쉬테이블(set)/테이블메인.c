//#include<stdio.h>
//#include"���.h"
//#include"���̺�.h"
//#include<stdlib.h>
//int HashFun(int k) {
//	return k % 100;  //ũ�Ⱑ 100�� �迭���� �ؽ�
//}
//int main() {
//	Table myTbl;
//	Person* np; //���� �Ű�ü ������
//	Person* sp; //Ž�� �Ű�ü
//	Person* rp; //���� �Ű�ü
//	TBLInit(&myTbl, HashFun);
//	np = MakePersonData(20120003, "Lee", "Seoul");
//	TBLInsert(&myTbl, GetSsn(np), np);
//	np = MakePersonData(20130002, "KIM", "Anyang");
//	TBLInsert(&myTbl, GetSsn(np), np);
//	np = MakePersonData(20150049, "LIM", "Seoul");
//	TBLInsert(&myTbl, GetSsn(np), np);
//	sp = TBLSearch(&myTbl, 20120003);
//		ShowPerInfo(sp);
//	sp = TBLSearch(&myTbl, 20130002);
//		ShowPerInfo(sp);
//	sp = TBLSearch(&myTbl, 20150049);
//		ShowPerInfo(sp);
//	rp = TBLDelete(&myTbl, 20130002);
//	if(rp!=NULL)
//		free(rp);
//	sp = TBLSearch(&myTbl, 20130002);
//		ShowPerInfo(sp);
//
//
//	return 0;
//}