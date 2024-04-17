#ifndef _SETTING_H_
#define _SETTING_H_

#include "public.h"
void paintbar(INSTRUMENT* pi);
void SetLuseMous(int* page_index, AIR* pair,INSTRUMENT* pi,int* ischange);

void paintRVAndSeat(INSTRUMENT* pi);
void paintRV(int x, int y, INSTRUMENT* pi,int mode, double alpha);
void paintRV2(int x, int y, INSTRUMENT* pi,int mode, double alpha);
void seatfunc(int mode, INSTRUMENT* pi);
void drawseat(INSTRUMENT* pi);
void RVuseMous(int* page_index, AIR* pair, INSTRUMENT* pi, int* ischange);
void restore(int item, INSTRUMENT* pi);

void DoorWinfunc(int mode, INSTRUMENT* pi);
void paintDoorWin(INSTRUMENT* pi);
void DWusemous(int* page_index, INSTRUMENT* pi, int* ischange);

#endif // !_SETTING_H_
