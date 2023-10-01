#ifndef __SLOT_H__
#define __SLOT_H__

#include "사람.h"

typedef int Key;
typedef Person* Value;

//열거형 enum 코드의 가독성을 위해 상수에 정수값을 0 1씩 증가시키는 값이 담긴 하나의 구조체 

enum SlotStatus{EMPTY,DELETED,INUSE};   

typedef struct { //테이블을 구성하는 요소 각각 키와 밸류,상태가 존재함 
	Key key;
	Value val;
    enum SlotStatus status;
}Slot;

#endif // !__SLOT_H__
