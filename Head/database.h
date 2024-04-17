#ifndef _DATABASE_H_
#define _DATABASE_H_

typedef struct 
{
	int position_x;
	int podition_y;
	int speed;
	int run;//������̵�ֵ���Ƴ����ƶ�(�ֶ�):0��ʾֹͣ��1��ʾǰ����2��ʾ���ˣ�3��ʾͣ����4��ʾ��ת��5��ʾ��ת��6��ʾ��ͷ
	int r;//���ӵĽǶ�
	int car_oil;//����
	int car_mode;//���ӵ�ģʽ//0��ʾ�ֶ���1��ʾ�Զ�
}CAR;

typedef struct 
{
	int state;
	int TotalDistance;
	int distant;
	int light;//���յ���̵Ƶ�����
	int node;//���յ�Ľڵ���
	int roadPart;//��ʾ�ڼ�·��
	
}PLAN;//·���滮

typedef struct 
{
	int type[3];//ʵ�����ֵƹ������//һ����˵���ĵ� , 0,1,2,3
}SETLIGHT;


typedef struct
{
	int positionx[10];//��һ������ߣ��ڶ������ұ�
	int positiony[10];//���ҹ�10����
	int choose;//0��ʾ��1��ʾ��
	int adjust[2];//01��ʾ�����£�2��ʾ����,
	//int moveUpAndDown[2];//0��ʾ���ϣ�1��ʾ����

}RearviewMirror;

typedef struct 
{
	int choose;//�ĸ��Ŵ���ѡ��
	int position[4];//4���Ŵ�
	int lock[4];//0��ʾ�Źأ�1��ʾ�ſ�
}DOORWINDOW;

typedef struct 
{
	int position;//��ǰ�������ε�λ��//0��ʾ����ʻ��1��ʾ����ʻ��2��ʾ����
	int height[3];//��ʾ����//0��ʾ�ϣ�1��ʾ��
	int horiz[3];//��ʾǰ��//0��ʾǰ��1��ʾ��
	int angle[3];//��ʾ�������εĽǶ�0��60��

}SEAT;

typedef struct 
{
	int air_degree[3];//����λ�õ�ǰ�¶�
	//int now_degree[];//�����¶�
	int mode;//�Զ������ֶ�//0��ʾ�Զ���1��ʾ�ֶ�
	int air_type;//���仹������//0��ʾ���䣬1��ʾ����
	int wind_speed;//������������
	int wind_direct;//����//�ϣ��У���
	int air_con;//�յ�����//0��ʾ�أ�1��ʾ��
	int loop;//ѭ��ģʽ//0��ʾ��ѭ����1��ʾ��ѭ��

}AIR;

typedef struct
{
	int wiper_speed[5];//��ˢ�ٶ�
	int wiper_mode;//��ˢģʽ
	int wiper_con;//��ˢ����
	int func[2];//������ˢ���ֹ����Ƿ���
}WIPER;

typedef struct 
{
	int mileage;//���
	int speed;//�ٶ�
	int oil;//����
	int water_temp;//ˮ��
	int light[8];//�ƹ�  //0ǰ�յ� 1�г��� 2ʾ���� 3Σ�վ�ʾ�� 4ǰ��� 5����� 6��Χ�� 7ת���״̬ 0�� 1��(0�� 1���� 2Զ��)
	DOORWINDOW doorwin;
	SETLIGHT setlight;
	RearviewMirror RVmirror;
	SEAT seat;
	WIPER wiper;

}INSTRUMENT;

struct CONTROL 
{
	int scram;//�����ƶ�//0��ʾ�أ�1��ʾ��
	int con_draw;//���ƻ�ͼ//0��ʾ�أ�1��ʾ��
	//int con_time;//����ʱ��
	long int con_ep1;//��������

};

#endif