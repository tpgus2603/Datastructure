//#include<stdio.h>
//#include"사람.h"
//#include"테이블.h"
//#include<stdlib.h>
//int HashFun(int k) {
//	return k % 100;  //크기가 100인 배열전용 해쉬
//}
//int main() {
//	Table myTbl;
//	Person* np; //삽입 매게체 포인터
//	Person* sp; //탐색 매개체
//	Person* rp; //삭제 매게체
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