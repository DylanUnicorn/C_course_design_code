#ifndef _AIR_H_
#define _AIR_H_

#include<public.h>
void wind(int x, int y, int airType, int speed, int derection);//��ͼ
void airfun(int mode, AIR* pair);
void airtemshow(AIR* pair);//�¶���ʾ
void airstage(int mode, AIR* pair);//״̬�ı�
void paintAir(AIR* pair);//���յ�
void airusemous(int* page_index, AIR* pair,int *ischange);


#endif  // _AIR_H_
