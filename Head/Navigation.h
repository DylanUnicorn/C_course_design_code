#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

#include "public.h"
#include "database.h"

//int find_point(CAR* mycar); //找最近点
void paint_line(int now, int temp);
void floyd(unsigned (*P)[15], unsigned (*D)[15]); //需要用点计算器计算
void navigaiton(int destination, int* pnow,  int(*P)[15], double* p_distance); //先暂时不需要判断车子当前的位置
void paint_line(int now, int temp);


#endif