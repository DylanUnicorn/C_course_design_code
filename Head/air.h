#ifndef _AIR_H_
#define _AIR_H_

#include<public.h>
void wind(int x, int y, int airType, int speed, int derection);//画图
void airfun(int mode, AIR* pair);
void airtemshow(AIR* pair);//温度显示
void airstage(int mode, AIR* pair);//状态改变
void paintAir(AIR* pair);//画空调
void airusemous(int* page_index, AIR* pair,int *ischange);


#endif  // _AIR_H_
