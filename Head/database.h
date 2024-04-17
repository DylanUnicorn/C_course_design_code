#ifndef _DATABASE_H_
#define _DATABASE_H_

typedef struct 
{
	int position_x;
	int podition_y;
	int speed;
	int run;//输入键盘的值控制车子移动(手动):0表示停止，1表示前进，2表示后退，3表示停车，4表示左转，5表示右转，6表示掉头
	int r;//车子的角度
	int car_oil;//油量
	int car_mode;//车子的模式//0表示手动，1表示自动
}CAR;

typedef struct 
{
	int state;
	int TotalDistance;
	int distant;
	int light;//至终点红绿灯的数量
	int node;//至终点的节点数
	int roadPart;//表示第几路段
	
}PLAN;//路径规划

typedef struct 
{
	int type[3];//实现三种灯光的设置//一般来说有四档 , 0,1,2,3
}SETLIGHT;


typedef struct
{
	int positionx[10];//第一个是左边，第二个是右边
	int positiony[10];//左右共10个点
	int choose;//0表示左，1表示右
	int adjust[2];//01表示向上下，2表示左右,
	//int moveUpAndDown[2];//0表示向上，1表示向下

}RearviewMirror;

typedef struct 
{
	int choose;//四个门窗的选择
	int position[4];//4个门窗
	int lock[4];//0表示门关，1表示门开
}DOORWINDOW;

typedef struct 
{
	int position;//当前调整座椅的位置//0表示主驾驶，1表示副驾驶，2表示后排
	int height[3];//表示上下//0表示上，1表示下
	int horiz[3];//表示前后//0表示前，1表示后
	int angle[3];//表示三个座椅的角度0到60度

}SEAT;

typedef struct 
{
	int air_degree[3];//三个位置当前温度
	//int now_degree[];//现在温度
	int mode;//自动或者手动//0表示自动，1表示手动
	int air_type;//制冷还是制热//0表示制冷，1表示制热
	int wind_speed;//风速设置三档
	int wind_direct;//风向//上，中，下
	int air_con;//空调开关//0表示关，1表示开
	int loop;//循环模式//0表示内循环，1表示外循环

}AIR;

typedef struct
{
	int wiper_speed[5];//雨刷速度
	int wiper_mode;//雨刷模式
	int wiper_con;//雨刷开关
	int func[2];//控制雨刷两种功能是否开启
}WIPER;

typedef struct 
{
	int mileage;//里程
	int speed;//速度
	int oil;//油量
	int water_temp;//水温
	int light[8];//灯光  //0前照灯 1行车灯 2示廓灯 3危险警示灯 4前雾灯 5后雾灯 6氛围灯 7转向灯状态 0关 1开(0关 1近光 2远光)
	DOORWINDOW doorwin;
	SETLIGHT setlight;
	RearviewMirror RVmirror;
	SEAT seat;
	WIPER wiper;

}INSTRUMENT;

struct CONTROL 
{
	int scram;//紧急制动//0表示关，1表示开
	int con_draw;//控制绘图//0表示关，1表示开
	//int con_time;//控制时间
	long int con_ep1;//控制数据

};

#endif