#ifndef __SLOT_H__
#define __SLOT_H__

#include "���.h"

typedef int Key;
typedef Person* Value;

//������ enum �ڵ��� �������� ���� ����� �������� 0 1�� ������Ű�� ���� ��� �ϳ��� ����ü 

enum SlotStatus{EMPTY,DELETED,INUSE};   

typedef struct { //���̺��� �����ϴ� ��� ���� Ű�� ���,���°� ������ 
	Key key;
	Value val;
    enum SlotStatus status;
}Slot;

#endif // !__SLOT_H__
