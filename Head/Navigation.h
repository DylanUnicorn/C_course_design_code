#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

#include "public.h"
#include "database.h"

//int find_point(CAR* mycar); //�������
void paint_line(int now, int temp);
void floyd(unsigned (*P)[15], unsigned (*D)[15]); //��Ҫ�õ����������
void navigaiton(int destination, int* pnow,  int(*P)[15], double* p_distance); //����ʱ����Ҫ�жϳ��ӵ�ǰ��λ��
void paint_line(int now, int temp);


#endif