#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN 50

typedef struct {
	int ssn;  //�ֹε�Ϲ�ȣ
	char name[STR_LEN];  //�̸�
	char addr[STR_LEN];  //�ּ�
}Person;
int GetSsn(Person* p);
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, char* name, char* addr);



#endif // !__PERSON_H__
