#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"hz.h"

#define pi 3.14159
#define rad pi/180

void polygon(double **v, int size)  //二维坐标 
 {
    int i, j;

    // 绘制底面
    for (j = 0; j < size / 2; j++) 
	{
        line(v[0][j], v[1][j], v[0][(j + 1) % (size / 2)], v[1][(j + 1) % (size / 2)]);
    }

    // 绘制侧面
    for (i = 0; i < size / 2; i++)
	{
		line(v[0][i],v[1][i],v[0][i+size/2],v[1][i+size/2]);
    }

    // 绘制顶面
    for (j = 0; j < size / 2; j++) 
	{
        line(v[0][j + size / 2], v[1][j + size / 2], v[0][(j + 1) % (size / 2) + size / 2], v[1][(j + 1) % (size / 2) + size / 2]);
    }
}

void fillPolygon(double **v, int size,int color)
{
    int points[8]; // 用于 fillpoly 的点数组
    int i, j;
	setfillstyle(SOLID_FILL, color);
//    // 设置填充样式和颜色
//    setfillstyle(SOLID_FILL, RED);

    // 填充顶面
    for (j = 0; j < size / 2; j++) {
        points[2 * j] = (int)v[0][j];
        points[2 * j + 1] = (int)v[1][j];
    }
    fillpoly(size / 2, points);

    // 填充底面
    for (j = 0; j < size / 2; j++) {
        points[2 * j] = (int)v[0][j + size / 2];
        points[2 * j + 1] = (int)v[1][j + size / 2];
    }
    fillpoly(size / 2, points);

//    // 设置填充样式和颜色为另一种颜色以区分侧面
//    setfillstyle(SOLID_FILL, BLUE);

    // 填充侧面
    for (i = 0; i < size / 2; i++) {
        j = (i + 1) % (size / 2);
        points[0] = (int)v[0][i];
        points[1] = (int)v[1][i];
        points[2] = (int)v[0][j];
        points[3] = (int)v[1][j];
        points[4] = (int)v[0][j + size / 2];
        points[5] = (int)v[1][j + size / 2];
        points[6] = (int)v[0][i + size / 2];
        points[7] = (int)v[1][i + size / 2];
        fillpoly(4, points);
    }
}

void Matply(double** matrix1,int rows1,int cols1, double** matrix2, int rows2,int cols2,double** result)    //矩阵乘法 
{                                 //rows表示行数，cols表示列数 
    int i, j, k;
    // 初始化result矩阵
    for(i = 0; i < rows1; i++) 
	{
        for(k = 0; k < cols2; k++) 
		{
            result[i][k] = 0.0;
        }
    }
    
    for(i = 0; i < rows1; i++) 
	{
        for(k = 0; k < cols2; k++) 
		{
            for(j = 0; j < cols1; j++)
			{
                result[i][k] += matrix1[i][j] * matrix2[j][k];
            }
        }
    }
}

void  Matadd(double** matrix1,int rows1,int cols1, double** matrix2, int rows2,int cols2,double** result)   //矩阵加法 
{
	int i,j;
	 // 初始化result矩阵
    for(i = 0; i < rows1; i++) 
	{
        for(j = 0; j < cols1; j++) 
		{
            result[i][j] = 0.0;
        }
    }
    
	for(i = 0;i<rows1;i++)
	{
		for(j = 0;j<cols1;j++)
		{
			result[i][j] += (matrix1[i][j] + matrix2[i][j]);
		}
	}
}

void Matexp(double** matrix,int rows,int cols,double* arr)   //矩阵展平为一维数组 
{
	int i = 0,j,k;
	for(j = 0; j < rows*cols; j++) 
	{
       arr[j] = 0.0;
    }
    
	for(j = 0;j<cols;j++)
	{
		for(k = 0;k<rows;k++)
		{
			arr[i*rows+k] = matrix[k][j];
			if(k == rows - 1 )i++;
		}
	}
} 

void  Coortla(double **matrix,int rows,int cols,double x,double y,double z,double **result)   //坐标平移
{
	int i,j;
	double _Rx[3][1];
	double _Ry[3][1];
	double _Rz[3][1];
	double *Rx[3];
	double *Ry[3];
	double *Rz[3];
	_Rx[0][0] = x;_Rx[1][0] = 0;_Rx[2][0] = 0;
	_Ry[0][0] = 0;_Ry[1][0] = y;_Ry[2][0] = 0;
	_Rz[0][0] = 0;_Rz[1][0] = 0;_Rz[2][0] = z;
	for(i = 0;i<rows;i++)
	{
		for(j = 0;j<cols;j++)
		{
			result[i][j] = 0;
		}
	}
	for(i = 0;i<3;i++)
	{
		Rx[i] = _Rx[i];
		Ry[i] = _Ry[i];
		Rz[i] = _Rz[i];
	}
	if(x>0)
	{
		for(j = 0;j<cols;j++)
		{
			result[0][j] = matrix[0][j] + Rx[0][0];
		}
	}
	else
	{
		for(j = 0;j<cols;j++)
		{
			result[0][j] = matrix[0][j];
		}
	}
	if(y>0)
	{
		for(j = 0;j<cols;j++)
		{
			result[1][j] = matrix[1][j] + Ry[1][0];
		}
	}
	else
	{
		for(j = 0;j<cols;j++)
		{
			result[1][j] = matrix[1][j];
		}
	}
	if(z>0)
	{
		for(j = 0;j<cols;j++)
		{
			result[2][j] = matrix[2][j] + Rz[2][0];
		}
	}
	else
	{
		for(j = 0;j<cols;j++)
		{
			result[2][j] = matrix[2][j];
		}
	}
}

void Coortfm(double x,double y,double* newx0y0)     //坐标变换 
{
	int i; 
	double *xy[2];
	double *R[2];
	double *x0y0[2];
	double *k[2];
	double *m[2];
	double _xy[2][1]; //= {{x},{y}};
	double _R[2][2] = {{1,0},{0,-1}};
	double _k[2][1] = {{0},{0}};
	double _x0y0[2][1] = {{320},{240}};
	double _m[2][1] = {{0},{0}};
    _xy[0][0] = x;
	_xy[1][0] = y; 
    for(i = 0;i<2;i++)         //初始化 
    {
    	newx0y0[i] = 0;
    	xy[i] = _xy[i];
    	R[i] = _R[i];
    	x0y0[i] = _x0y0[i];
    	k[i] = _k[i];
    	m[i] = _m[i];
	}

	Matply(R,2,2,xy,2,1,k);   //坐标运算转化 
	Matadd(k,2,1,x0y0,2,1,m);

	newx0y0[0] = m[0][0];      //赋值 
	newx0y0[1] = m[1][0];

}

void spin(double**matrix,int rows,int cols,int mask_x,int mask_y,int mask_z,double degree,double **result)  //图形旋转
{
	int i,j;
	double *Rx[3];
	double *Ry[3];
	double *Rz[3];
	double _Rx[3][3]; //= {{1,0,0},{0,cos(degree*rad),sin(degree*rad)},{0,-sin(degree*rad),cos(degree*rad)}};
	double _Ry[3][3]; //= {{cos(degree*rad),0,-sin(degree*rad)},{0,1,0},{sin(degree*rad),0,cos(degree*rad)}};
	double _Rz[3][3]; //= {{cos(degree*rad),sin(degree*rad),0},{-sin(degree*rad),cos(degree*rad),0},{0,0,1}};
	_Rx[0][0] = 1;_Rx[0][1] = 0;_Rx[0][2] = 0;_Rx[1][0] = 0;_Rx[1][1] = cos(degree*rad);_Rx[1][2] = sin(degree*rad);_Rx[2][0] = 0;_Rx[2][1] = -sin(degree*rad);_Rx[2][2] = cos(degree*rad);
	_Ry[1][0]= 0;_Ry[1][1]= 1;_Ry[1][2]= 0;_Ry[0][0] = cos(degree*rad);_Ry[0][1] = 0;_Ry[0][2] = -sin(degree*rad);_Ry[2][0] = sin(degree*rad);_Ry[2][1] = 0;_Ry[2][2] = cos(degree*rad);
	_Rz[2][0] = 0;_Rz[2][1] = 0;_Rz[2][2] = 1;_Rz[0][0] = cos(degree*rad);_Rz[0][1] = sin(degree*rad);_Rz[0][2] = 0; _Rz[1][0] = -sin(degree*rad);_Rz[1][1] = cos(degree*rad);_Rz[1][2] = 0;
	 // 初始化矩阵
    for(i = 0; i < rows; i++) 
	{
        for(j = 0; j < cols; j++) 
		{
            result[i][j] = 0.0;
        }
    }
    for(i = 0;i<3;i++)
    {
    	Rx[i] = _Rx[i];
		Ry[i] = _Ry[i];
		Rz[i] = _Rz[i];
	}
    if(mask_x == 1)
    {
    	Matply(Rx,3,3,matrix,rows,cols,result);
	}
	if(mask_y ==1)
	{
		Matply(Ry,3,3,matrix,rows,cols,result);
	}
	if(mask_z ==1)
	{
		Matply(Rz,3,3,matrix,rows,cols,result);
	}
} 

void zoom(double**matrix,int rows,int cols,double zoom_size,double **result)   //尺寸缩放 
{
	int i,j;
	double center_x,center_y;
	// 初始化矩阵
    for(i = 0; i < rows; i++) 
	{
        for(j = 0; j < cols; j++) 
		{
            result[i][j] = 0.0;
        }
    }
    center_x = (matrix[0][7] + matrix[0][5])/2;
    center_y = (matrix[1][7] + matrix[1][5])/2;
    //缩放 
    for(i = cols/2,j = 0;i<cols,j<cols/2;i++,j++)
    {
    	result[0][i] = center_x - zoom_size*(center_x - matrix[0][i]);
    	result[0][j] = center_x - zoom_size*(center_x - matrix[0][i]);
	}
	for(i = cols/2,j = 0;i<cols,j<cols/2;i++,j++)
	{
		result[1][i] = center_y - zoom_size*(center_y - matrix[1][i]);
		result[1][j] = center_y - zoom_size*(center_y - matrix[1][i]);
	}
	for(i = 0;i<cols;i++)
	{
		result[2][i] = zoom_size * matrix[2][i];
	}

}

void mapspin(double **matrix3D,double **matrix2D,double **R,int mask_x,int mask_y,int mask_z,double degree)      //地图旋转 
{
	int w = 0;
	int i;
	double x,y;
	double *x0y0;
	double _xy[2] = {0,0};
	//暂存模块 
	double *temp3D1[3];                                                      
	double *temp3D2[3];
	
	//初始化模块 
	for(i = 0;i<3;i++)
	{
		temp3D1[i] = (double*)malloc(8*sizeof(double));
		temp3D2[i] = (double*)malloc(8*sizeof(double));
	}
	x0y0 = _xy; 
	while(w<degree||w>degree)                                                
	{
//		cleardevice();
		for(i = 0;i<3;i++)
		{
			temp3D1[i] = temp3D2[i];
		}
		spin(matrix3D,3,8,mask_x,mask_y,mask_z,w,temp3D1);
		
		Matply(R,2,3,temp3D1,3,8,matrix2D);
		
		for(i = 0;i<3;i++)
		{
			temp3D2[i] = temp3D1[i];
		//	matrix3D[i] = temp3D1[i];
		}
		
		for(i = 0;i<8;i++)
		{
			x = matrix2D[0][i];
			y = matrix2D[1][i];
			Coortfm(x,y,x0y0);
			matrix2D[0][i] = x0y0[0];
			matrix2D[1][i] = x0y0[1];
		}
//		for(i = 0;i<8;i++)
//			printf("%f %f\n",matrix2D[0][i],matrix2D[1][i]);
//		fillPolygon(matrix2D,8,DARKGRAY);
//		polygon(matrix2D,8);
		if(degree>0)w++;
		else w--;
	}
	
	for(i = 0;i<3;i++)
	{
	//	free(temp3D1[i]);
	//	free(temp3D2[i]);
	}
}

void maptla(double **matrix3D,int rows,int cols,double**R,int x,int y,int z)     //地图平移 
{
	int i,j;
	double x1,y1;
	double **temp1;
	double *temp2[2];
	double *xy;
	
	//初始化 
	for(i = 0;i<rows;i++)
	{
		for(j = 0;j<cols;j++)
		{
			temp1[i][j] = matrix3D[i][j];
		}
	}
	for(i = 0;i<2;i++)
	{
		temp2[i] = (double*)malloc(cols*sizeof(double));
	}
	xy = (double*)malloc(2*sizeof(double));
	
	//坐标平移 
	cleardevice();
	Coortla(matrix3D,rows,cols,x,y,z,temp1);
	Matply(R,2,3,temp1,rows,cols,temp2);
	for(i = 0;i<cols;i++)
	{
		x1 = temp2[0][i];
		y1 = temp2[1][i];
		Coortfm(x1,y1,xy);
		temp2[0][i] = xy[0];
		temp2[1][i] = xy[1];
	}
	fillPolygon(temp2,8,DARKGRAY);
	polygon(temp2,8);
	delay(100);
	
	//内存释放 
	free(temp2[0]);
	free(temp2[1]);
	free(xy);
}

void initmap(double**matrix1,double**matrix2,double**R,int color)          //地图初始化 
{
	int i,x,y;
	double *xy;
	double temp[] = {0,0};
	xy = temp;
	Matply(R,2,3,matrix1,3,8,matrix2);
	for(i = 0;i<8;i++)
	{
		x = matrix2[0][i];
		y = matrix2[1][i];
		Coortfm(x,y,xy);
		matrix2[0][i] = xy[0];
		matrix2[1][i] = xy[1];
	}
	fillPolygon(matrix2,8,color);
	polygon(matrix2,8);
}
void mapzoom(double **matrix,int rows,int cols,double zoom_size)            //地图缩放 
{
	double *zoom1[3];
	int i,j;
	for(i = 0;i<3;i++)
	{
		zoom1[i] = (double*)malloc(cols*sizeof(double));
	}
	zoom(matrix,rows,cols,zoom_size,zoom1);
	for(i = 0;i<rows;i++)
	{
		for(j = 0;j<cols;j++)
		{
			matrix[i][j] = zoom1[i][j];
		}
	}
	for(i = 0;i<3;i++)
	{
		free(zoom1[i]);
	}
}
int main()
{
	//基础准备模块 
	int gm = VGA, gd = VGAHI;                         
	double _R[2][3] = {
						{0.707107, 0, 1},
						{0.707107, 1, 0}
						};
    double *R[2];
   	int i,j;
	double x,y,w = 0;
//	double *xy;
    double v[16];
//  double temp[] = {0,0};
    
    //图形模块
	double _road3D1[3][8] = {                                               //道路1          
							{340,340,-340,-340,340,340,-340,-340},
							{-50,50,50,-50,-50,50,50,-50},
							{0,0,0,0,0,0,0,0}
							};
	double *road3D1[3];
    double *road2D1[2];
    
    double  _road3D2[3][8] = {                                               //道路2          
							    {-340,-340,-440,-440,-340,-340,-440,-440},
							    {-695,50,50,-695,-695,50,50,-695},
						    	{0,0,0,0,0,0,0,0}
							};
	double *road3D2[3];
	double *road2D2[2];
	
	double _road3D3[3][8] = {                                                 //道路3
								{-340,-340,-980,-980,-340,-340,-980,-980},
								{-695,-595,-595,-695,-695,-595,-595,-695},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D3[3];
	double *road2D3[2];
	
	double _road3D4[3][8] = {                                                  //道路4
								{-880,-880,-980,-980,-880,-880,-980,-980},
								{-695,1495,1495,-695,-695,1495,1495,-695},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D4[3];
	double *road2D4[2];
	
	double _road3D5[3][8] = {                                                //道路5
								{-565,-565,-980,-980,-565,-565,-980,-980},
								{1395,1495,1495,1395,1395,1495,1495,1395},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D5[3];
	double *road2D5[2];
	
	double _road3D6[3][8] = {                                                   //道路6
								{-465,-465,-565,-565,-465,-465,-565,-565},
								{1395,2010,2010,1395,1395,2010,2010,1395},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D6[3];
	double *road2D6[2];
	
	double _road3D7[3][8] = {                                                    //道路7
								{620,620,-565,-565,620,620,-565,-565},
								{1910,2010,2010,1910,1910,2010,2010,1910},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D7[3];
	double *road2D7[2];
	
	double _road3D8[3][8] = {                                                    //道路8
								{720,720,620,620,720,720,620,620},
								{-50,2010,2010,-50,-50,2010,2010,-50},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D8[3];
	double *road2D8[2];
	
	double _road3D9[3][8] = {                                                    //道路9
								{720,720,340,340,720,720,340,340},
								{-50,50,50,-50,-50,50,50,-50},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D9[3];
	double *road2D9[2];
	
	double _road3D10[3][8] = {                                                //道路10
								{440,440,340,340,440,440,340,340},
								{-50,910,910,-50,-50,910,910,-50},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D10[3];
	double *road2D10[2];
	
	double _road3D11[3][8] = {                                                   //道路11
								{440,440,-565,-565,440,440,-565,-565},
								{810,910,910,810,810,910,910,810},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D11[3];
	double *road2D11[2];
	
	double _road3D12[3][8] = {                                                 //道路12
								{-465,-465,-565,-565,-465,-465,-565,-565},
								{810,1395,1395,810,810,1395,1395,810},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D12[3];
	double *road2D12[2];
	
	double _road3D13[3][8] = {                                                  //道路13
								{100,100,0,0,100,100,0,0},
								{910,1395,1395,910,910,1395,1395,910},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D13[3];
	double *road2D13[2];
	
	double _road3D14[3][8] = {                                                 //道路14
								{620,620,0,0,620,620,0,0},
								{1395,1495,1495,1395,1395,1495,1495,1395},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D14[3];
	double *road2D14[2];
	
	double _road3D15[3][8] = {                                                 //道路15
								{0,0,-565,-565,0,0,-565,-565},
								{1395,1495,1495,1395,1395,1495,1495,1395},
								{0,0,0,0,0,0,0,0}
							};
	double *road3D15[3];
	double *road2D15[2];
	
	double _building3D1[3][8] = {                                                 //建筑1 
									{70,70,-70,-70,70,70,-70,-70},
									{-200,60,60,-200,-200,60,60,-200},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D1[3];
	double *building2D1[2];
	
	double _building3D2[3][8] = {                                                 //建筑2
									{260,260,130,130,260,260,130,130},
									{-190,-140,-140,-190,-190,-140,-140,-190},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D2[3];
	double *building2D2[2];
	
	double _building3D3[3][8] = {                                                 //建筑3
									{200,200,130,130,200,200,130,130},
									{-140,-60,-60,-140,-140,-60,-60,-140},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D3[3];
	double *building2D3[2];
	
	double _building3D4[3][8] = {                                                 //建筑4
									{-110,-110,-170,-170,-110,-110,-170,-170},
									{-265,-60,-60,-265,-265,-60,-60,-265},
									{50,50,50,50,0,0,0,0}
								};
	double *building3D4[3];
	double *building2D4[2];
	
	double _building3D5[3][8] = {                                                 //建筑5
									{-250,-250,-330,-330,-250,-250,-330,-330},
									{-230,-80,-80,-230,-230,-80,-80,-230},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D5[3];
	double *building2D5[2];
	
	double _building3D6[3][8] = {                                                 //建筑6
									{600,600,325,325,600,600,325,325},
									{-190,-60,-60,-190,-190,-60,-60,-190},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D6[3];
	double *building2D6[2];
	
	double _building3D7[3][8] = {                                                 //建筑7
									{685,685,650,650,685,685,650,650},
									{-145,-115,-115,-145,-145,-115,-115,-145},
									{200,200,200,200,0,0,0,0}
								};
	double *building3D7[3];
	double *building2D7[2];
	
	double _building3D8[3][8] = {                                                 //建筑8
									{330,330,45,45,330,330,45,45},
									{60,445,445,60,60,445,445,60},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D8[3];
	double *building2D8[2];
	
	double _building3D9[3][8] = {                                                 //建筑9
									{610,610,455,455,610,610,445,445},
									{185,265,265,185,185,265,265,185},
									{50,50,50,50,0,0,0,0}
								};
	double *building3D9[3];
	double *building2D9[2];
	
	double _building3D10[3][8] = {                                                 //建筑10
									{525,525,455,455,525,525,455,455},
									{60,185,185,60,60,185,185,60},
									{50,50,50,50,0,0,0,0}
								};
	double *building3D10[3];
	double *building2D10[2];
	
	double _building3D11[3][8] = {                                                 //建筑11
									{610,610,445,445,610,610,445,445},
									{290,500,500,290,290,500,500,290},
									{50,50,50,50,0,0,0,0}
								};
	double *building3D11[3];
	double *building2D11[2];
	
	double _building3D12[3][8] = {                                                 //建筑12
									{25,25,-200,-200,25,25,-200,-200},
									{500,800,800,500,500,800,800,500},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D12[3];
	double *building2D12[2];
	
	double _building3D13[3][8] = {                                                 //建筑13
									{25,25,-380,-380,25,25,-380,-380},
									{60,310,310,60,60,310,310,60},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D13[3];
	double *building2D13[2];
	
	double _building3D14[3][8] = {                                                 //建筑14
									{-265,-265,-350,-350,-265,-265,-350,-350},
									{620,790,790,620,620,790,790,620},
									{50,50,50,50,0,0,0,0}
								};
	double *building3D14[3];
	double *building2D14[2];
	
	double _building3D15[3][8] = {                                                 //建筑15
									{-20,-20,-115,-115,-20,-20,-115,-115},
									{950,1355,1355,950,950,1355,1355,950},
									{200,200,200,200,0,0,0,0}
								};
	double *building3D15[3];
	double *building2D15[2];
	
	double _building3D16[3][8] = {                                                 //建筑16
									{-155,-155,-445,-445,-155,-155,-445,-445},
									{950,1355,1355,950,950,1355,1355,950},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D16[3];
	double *building2D16[2];
	
	double _building3D17[3][8] = {                                                 //建筑17
									{-400,-400,-455,-455,-400,-400,-455,-455},
									{600,760,760,600,600,760,760,600},
									{50,50,50,50,0,0,0,0}
								};
	double *building3D17[3];
	double *building2D17[2];
	
	double _building3D18[3][8] = {                                                 //建筑18
									{-460,-460,-500,-500,-460,-460,-500,-500},
									{-200,300,300,-200,-200,300,300,-200},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D18[3];
	double *building2D18[2];
	
	double _building3D19[3][8] = {                                                 //建筑19
									{-400,-400,-460,-460,-400,-400,-460,-460},
									{100,300,300,100,100,300,300,100},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D19[3];
	double *building2D19[2];
	
	double _building3D20[3][8] = {                                                 //建筑20
									{-460,-460,-500,-500,-460,-460,-500,-500},
									{-500,-300,-300,-500,-500,-300,-300,-500},
									{80,80,80,80,0,0,0,0}
								};
	double *building3D20[3];
	double *building2D20[2];
	
	double _building3D21[3][8] = {                                                 //建筑21
									{-595,-595,-860,-860,-595,-595,-860,-860},
									{-565,1375,1375,-565,-565,1375,1375,-565},
									{200,200,200,200,0,0,0,0}
								};
	double *building3D21[3];
	double *building2D21[2];
	
	double _building3D22[3][8] = {                                                 //建筑22
									{-550,-550,-950,-950,-550,-550,-950,-950},
									{-930,-720,-720,-930,-930,-720,-720,-930},
									{100,100,100,100,0,0,0,0}
								};
	double *building3D22[3];
	double *building2D22[2];
	
	double _grass3D1[3][8] = {                                                 //草地1 
									{610,610,455,455,610,610,455,455},
									{530,910,910,530,530,910,910,530},
									{0,0,0,0,0,0,0,0}
								};
	double *grass3D1[3];
	double *grass2D1[2];
	
	double _grass3D2[3][8] = {                                                 //草地2 
									{600,600,-445,-445,600,600,-445,-445},
									{1555,1870,1870,1555,1555,1870,1870,1555},
									{0,0,0,0,0,0,0,0}
								};
	double *grass3D2[3];
	double *grass2D2[2];
	
	double _lake3D[3][8] = {                                                 //湖泊 
									{610,610,120,120,610,610,120,120},
									{930,1375,1375,930,930,1375,1375,930},
									{0,0,0,0,0,0,0,0}
								};
	double *lake3D[3];
	double *lake2D[2];
	
	double _river3D1[3][8] = {                                                 //河流1 
									{-1040,-1040,-1240,-1240,-1040,-1040,-1240,-1240},
									{-870,2160,2160,-870,-870,2160,2160,-870},
									{0,0,0,0,0,0,0,0}
								};
	double *river3D1[3];
	double *river2D1[2];
	
	double _river3D2[3][8] = {                                                 //河流2
									{-740,-740,-1040,-1040,-740,-740,-1040,-1040},
									{1555,2160,2160,1555,1555,2160,2160,1555},
									{0,0,0,0,0,0,0,0}
								};
	double *river3D2[3];
	double *river2D2[2];
	
	double _river3D3[3][8] = {                                                 //河流3
									{-595,-595,-740,-740,-595,-595,-740,-740},
									{1555,2330,2330,1555,1555,2330,2330,1555},
									{0,0,0,0,0,0,0,0}
								};
	double *river3D3[3];
	double *river2D3[2];
	
	double _river3D4[3][8] = {                                                 //河流4
									{870,870,-595,-595,870,870,-595,-595},
									{2050,2330,2330,2050,2050,2330,2330,2050},
									{0,0,0,0,0,0,0,0}
								};
	double *river3D4[3];
	double *river2D4[2];
	
	double _river3D5[3][8] = {                                                 //河流5
									{870,870,740,740,870,870,740,740},
									{-300,2300,2300,-300,-300,2300,2300,-300},
									{0,0,0,0,0,0,0,0}
								};
	double *river3D5[3];
	double *river2D5[2];
	
	double _square3D[3][8] = {                                                 //广场 
									{330,330,45,45,330,330,45,45},
									{445,800,800,445,445,800,800,445},
									{0,0,0,0,0,0,0,0}
								};
	double *square3D[3];
	double *square2D[2];
	
	initgraph(&gm, &gd, "C:\\\\BORLANDC\\\\BGI");
	setcolor(WHITE);
	setbkcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);

	//初始化模块
	for(i = 0;i<2;i++)              
	{
		R[i] = _R[i];
	}
	for(i = 0;i<3;i++)
	{
		road3D1[i] = _road3D1[i];
		road3D2[i] = _road3D2[i];
		road3D3[i] = _road3D3[i];
		road3D4[i] = _road3D4[i];
		road3D5[i] = _road3D5[i];
		road3D6[i] = _road3D6[i];
		road3D7[i] = _road3D7[i];
		road3D8[i] = _road3D8[i];
		road3D9[i] = _road3D9[i];
		road3D10[i] = _road3D10[i];
		road3D11[i] = _road3D11[i];
		road3D12[i] = _road3D12[i];
		road3D13[i] = _road3D13[i];
		road3D14[i] = _road3D14[i];
		road3D15[i] = _road3D15[i];
		building3D1[i] = _building3D1[i];
		building3D2[i] = _building3D2[i];
		building3D3[i] = _building3D3[i];
		building3D4[i] = _building3D4[i];
		building3D5[i] = _building3D5[i];
		building3D6[i] = _building3D6[i];
		building3D7[i] = _building3D7[i];
		building3D8[i] = _building3D8[i];
		building3D9[i] = _building3D9[i];
		building3D10[i] = _building3D10[i];
		building3D11[i] = _building3D11[i];
		building3D12[i] = _building3D12[i];
		building3D13[i] = _building3D13[i];
		building3D14[i] = _building3D14[i];
		building3D15[i] = _building3D15[i];
		building3D16[i] = _building3D16[i];
		building3D17[i] = _building3D17[i];
		building3D18[i] = _building3D18[i];
		building3D19[i] = _building3D19[i];
		building3D20[i] = _building3D20[i];
		building3D21[i] = _building3D21[i];
		building3D22[i] = _building3D22[i];
		grass3D1[i] = _grass3D1[i];
		grass3D2[i] = _grass3D2[i];
		square3D[i] = _square3D[i];
		river3D1[i] = _river3D1[i];
		river3D2[i] = _river3D2[i];
		river3D3[i] = _river3D3[i];
		river3D4[i] = _river3D4[i];
		river3D5[i] = _river3D5[i];
		lake3D[i] = _lake3D[i];
	}
	
	//内存动态分配模块
	for(i = 0;i<2;i++)            
	{
		road2D1[i] = (double*)malloc(8*sizeof(double));
		road2D2[i] = (double*)malloc(8*sizeof(double));
		road2D3[i] = (double*)malloc(8*sizeof(double));
		road2D4[i] = (double*)malloc(8*sizeof(double));
		road2D5[i] = (double*)malloc(8*sizeof(double));
		road2D6[i] = (double*)malloc(8*sizeof(double));
		road2D7[i] = (double*)malloc(8*sizeof(double));
		road2D8[i] = (double*)malloc(8*sizeof(double));
		road2D9[i] = (double*)malloc(8*sizeof(double));
		road2D10[i] = (double*)malloc(8*sizeof(double));
		road2D11[i] = (double*)malloc(8*sizeof(double));
		road2D12[i] = (double*)malloc(8*sizeof(double));
		road2D13[i] = (double*)malloc(8*sizeof(double));
		road2D14[i] = (double*)malloc(8*sizeof(double));
		road2D15[i] = (double*)malloc(8*sizeof(double));
		building2D1[i] = (double*)malloc(8*sizeof(double));
		building2D2[i] = (double*)malloc(8*sizeof(double));
		building2D3[i] = (double*)malloc(8*sizeof(double));
		building2D4[i] = (double*)malloc(8*sizeof(double));
		building2D5[i] = (double*)malloc(8*sizeof(double));
		building2D6[i] = (double*)malloc(8*sizeof(double));
		building2D7[i] = (double*)malloc(8*sizeof(double));
		building2D8[i] = (double*)malloc(8*sizeof(double));
		building2D9[i] = (double*)malloc(8*sizeof(double));
		building2D10[i] = (double*)malloc(8*sizeof(double));
		building2D11[i] = (double*)malloc(8*sizeof(double));
		building2D12[i] = (double*)malloc(8*sizeof(double));
		building2D13[i] = (double*)malloc(8*sizeof(double));
		building2D14[i] = (double*)malloc(8*sizeof(double));
		building2D15[i] = (double*)malloc(8*sizeof(double));
		building2D16[i] = (double*)malloc(8*sizeof(double));
		building2D17[i] = (double*)malloc(8*sizeof(double));
		building2D18[i] = (double*)malloc(8*sizeof(double));
		building2D19[i] = (double*)malloc(8*sizeof(double));
		building2D20[i] = (double*)malloc(8*sizeof(double));
		building2D21[i] = (double*)malloc(8*sizeof(double));
		building2D22[i] = (double*)malloc(8*sizeof(double));
		grass2D1[i] = (double*)malloc(8*sizeof(double));
		grass2D2[i] = (double*)malloc(8*sizeof(double));
		square2D[i] = (double*)malloc(8*sizeof(double));
		river3D1[i] = (double*)malloc(8*sizeof(double));
		river3D2[i] = (double*)malloc(8*sizeof(double));
		river3D3[i] = (double*)malloc(8*sizeof(double));
		river3D4[i] = (double*)malloc(8*sizeof(double));
		river3D5[i] = (double*)malloc(8*sizeof(double));
		lake3D[i] = (double*)malloc(8*sizeof(double));
	}
	for(i = 0;i<3;i++)
	{
		//temp3D1[i] = (double*)malloc(8*sizeof(double));
		//temp3D2[i] = (double*)malloc(8*sizeof(double));
	}
//	xy = temp;
//	
//	//图形缩放模块
	mapzoom(building3D1,3,8,0.7);
	mapzoom(building3D2,3,8,0.7);
//	mapzoom(building3D3,3,8,0.5);
	mapzoom(building3D4,3,8,0.7);
	mapzoom(building3D5,3,8,0.7);
	mapzoom(building3D6,3,8,0.2);
	mapzoom(building3D7,3,8,0.7);
	mapzoom(building3D8,3,8,0.7);
	mapzoom(building3D9,3,8,0.7);
	mapzoom(building3D10,3,8,0.7);
	mapzoom(building3D11,3,8,0.7);
	mapzoom(building3D12,3,8,0.7);
	mapzoom(building3D13,3,8,0.5);
	mapzoom(building3D14,3,8,0.7);
	mapzoom(building3D15,3,8,0.7);
	mapzoom(building3D16,3,8,0.7);
	mapzoom(building3D17,3,8,0.7);
	mapzoom(building3D18,3,8,0.7);
	mapzoom(building3D19,3,8,0.7);
	mapzoom(building3D20,3,8,0.7);
	mapzoom(building3D21,3,8,0.7);
	mapzoom(building3D22,3,8,0.7);
	
	//图形初始绘制模块 
	initmap(road3D1,road3D2,R,DARKGRAY);
//	initmap(road3D2,road3D2,R,DARKGRAY);
//	initmap(road3D3,road3D2,R,DARKGRAY);
//	initmap(road3D4,road3D2,R,DARKGRAY);
//	initmap(road3D5,road3D2,R,DARKGRAY);
//	initmap(road3D6,road3D2,R,DARKGRAY);
//	initmap(road3D7,road3D2,R,DARKGRAY);
//	initmap(road3D8,road3D2,R,DARKGRAY);
//	initmap(road3D9,road3D2,R,DARKGRAY);
//	initmap(road3D10,road3D2,R,DARKGRAY);
//	initmap(road3D11,road3D2,R,DARKGRAY);
//	initmap(road3D12,road3D2,R,DARKGRAY);
//	initmap(road3D13,road3D2,R,DARKGRAY);
//	initmap(road3D14,road3D2,R,DARKGRAY);
//	initmap(road3D15,road3D2,R,DARKGRAY);
//	initmap(building3D1,building2D1,R,LIGHTBLUE);
//	initmap(building3D2,building2D2,R,LIGHTBLUE);
////	initmap(building3D3,building2D3,R,LIGHTBLUE);
//	initmap(building3D4,building2D4,R,LIGHTBLUE);
//	initmap(building3D5,building2D5,R,LIGHTBLUE);
//	initmap(building3D6,building2D6,R,LIGHTBLUE);
//	initmap(building3D7,building2D7,R,LIGHTBLUE);
//	initmap(building3D8,building2D8,R,LIGHTBLUE);
//	initmap(building3D9,building2D9,R,LIGHTBLUE);
//	initmap(building3D10,building2D10,R,LIGHTBLUE);
//	initmap(building3D11,building2D11,R,LIGHTBLUE);
//	initmap(building3D12,building2D12,R,LIGHTBLUE);
//	initmap(building3D13,building2D13,R,LIGHTBLUE);
//	initmap(building3D14,building2D14,R,LIGHTBLUE);
//	initmap(building3D15,building2D15,R,LIGHTBLUE);
//	initmap(building3D16,building2D16,R,LIGHTBLUE);
//	initmap(building3D17,building2D17,R,LIGHTBLUE);
//	initmap(building3D18,building2D18,R,LIGHTBLUE);
//	initmap(building3D19,building2D19,R,LIGHTBLUE);
//	initmap(building3D20,building2D20,R,LIGHTBLUE);
//	initmap(building3D21,building2D21,R,LIGHTBLUE);
//	initmap(building3D22,building2D22,R,LIGHTBLUE);
//	initmap(grass3D1,grass2D1,R,LIGHTGREEN);
//	initmap(grass3D2,grass2D2,R,LIGHTGREEN);
//	initmap(river3D1,river2D1,R,BLUE);
//	initmap(river3D2,river2D1,R,BLUE);
//	initmap(river3D3,river2D1,R,BLUE);
//	initmap(river3D4,river2D1,R,BLUE);
//	initmap(river3D5,river2D1,R,BLUE);
//	initmap(lake3D,lake2D,R,BLUE);
//	initmap(square3D,square2D,R,LIGHTGRAY);
//	cleardevice(); 
	
//	getch();
//	//平移模块
//	x = 0;
//	while(x<90)
//	{
//		maptla(road3D1,3,8,R,1,0,0);
//		maptla(road3D2,3,8,R,1,0,0);
//		maptla(road3D3,3,8,R,1,0,0);
//		maptla(road3D4,3,8,R,1,0,0);
//		maptla(road3D5,3,8,R,1,0,0);
//		maptla(road3D6,3,8,R,1,0,0);
//		maptla(road3D7,3,8,R,1,0,0);
//		maptla(road3D8,3,8,R,1,0,0);
//		maptla(road3D9,3,8,R,1,0,0);
//		maptla(road3D10,3,8,R,1,0,0);
//		maptla(road3D11,3,8,R,1,0,0);
//		maptla(road3D12,3,8,R,1,0,0);
//		maptla(road3D13,3,8,R,1,0,0);
//		maptla(road3D14,3,8,R,1,0,0);
//		maptla(road3D15,3,8,R,1,0,0);
//		maptla(building3D1,3,8,R,1,0,0);
//		maptla(building3D2,3,8,R,1,0,0);
//		maptla(building3D3,3,8,R,1,0,0);
//		maptla(building3D4,3,8,R,1,0,0);
//		maptla(building3D5,3,8,R,1,0,0);
//		maptla(building3D6,3,8,R,1,0,0);
//		maptla(building3D7,3,8,R,1,0,0);
//		maptla(building3D8,3,8,R,1,0,0);
//		maptla(building3D9,3,8,R,1,0,0);
//		maptla(building3D10,3,8,R,1,0,0);
//		maptla(building3D11,3,8,R,1,0,0);
//		maptla(building3D12,3,8,R,1,0,0);
//		maptla(building3D13,3,8,R,1,0,0);
//		maptla(building3D14,3,8,R,1,0,0);
//		maptla(building3D15,3,8,R,1,0,0);
//		maptla(building3D16,3,8,R,1,0,0);
//		maptla(building3D17,3,8,R,1,0,0);
//		maptla(building3D18,3,8,R,1,0,0);
//		maptla(building3D19,3,8,R,1,0,0);
//		maptla(building3D20,3,8,R,1,0,0);
//		maptla(building3D21,3,8,R,1,0,0);
//		maptla(building3D22,3,8,R,1,0,0);
//		x++;
//		delay(100);
//	}
//	
	//旋转模块 
	w = 0;
//	while(w<=90)
//	{
//		mapspin(road3D1,road2D1,R,0,0,1,w);
//		mapspin(road3D2,road2D1,R,0,0,1,w);
//		mapspin(road3D3,road2D1,R,0,0,1,w);
//		mapspin(road3D4,road2D1,R,0,0,1,w);
//		mapspin(road3D5,road2D1,R,0,0,1,w);
//		mapspin(road3D6,road2D1,R,0,0,1,w);
//		mapspin(road3D7,road2D1,R,0,0,1,w);
//		mapspin(road3D8,road2D1,R,0,0,1,w);
//		mapspin(road3D9,road2D1,R,0,0,1,w);
//		mapspin(road3D10,road2D1,R,0,0,1,w);
//		mapspin(road3D11,road2D1,R,0,0,1,w);
//		mapspin(road3D12,road2D1,R,0,0,1,w);
//		mapspin(road3D13,road2D1,R,0,0,1,w);
//		mapspin(road3D14,road2D1,R,0,0,1,w);
//		mapspin(road3D15,road2D1,R,0,0,1,w);
//		w++;
 //		delay(10);
//	}

	//平移模块
//	x = 0;
//	while(x<645)
//	{
//		maptla(road3D1,3,8,R,1,0,0);
//		maptla(road3D2,3,8,R,1,0,0);
//		maptla(road3D3,3,8,R,1,0,0);
//		maptla(road3D4,3,8,R,1,0,0);
//		maptla(road3D5,3,8,R,1,0,0);
//		maptla(road3D6,3,8,R,1,0,0);
//		maptla(road3D7,3,8,R,1,0,0);
//		maptla(road3D8,3,8,R,1,0,0);
//		maptla(road3D9,3,8,R,1,0,0);
//		maptla(road3D10,3,8,R,1,0,0);
//		maptla(road3D11,3,8,R,1,0,0);
//		maptla(road3D12,3,8,R,1,0,0);
//		maptla(road3D13,3,8,R,1,0,0);
//		maptla(road3D14,3,8,R,1,0,0);
//		maptla(road3D15,3,8,R,1,0,0);
//		x++;
//	}
		
	//内存释放模块 
	for(i = 0;i<2;i++)
	{
		free(road2D1[i]);
		free(road2D2[i]);
		free(road2D3[i]);
		free(road2D4[i]);
		free(road2D5[i]);
		free(road2D6[i]);
		free(road2D7[i]);
		free(road2D8[i]);
		free(road2D9[i]);
		free(road2D10[i]);
		free(road2D11[i]);
		free(road2D12[i]);
		free(road2D13[i]);
		free(road2D14[i]);
		free(road2D15[i]);
		free(building2D1[i]);
		free(building2D2[i]);
		free(building2D3[i]);
		free(building2D4[i]);
		free(building2D5[i]);
		free(building2D6[i]);
		free(building2D7[i]);
		free(building2D8[i]);
		free(building2D9[i]);
		free(building2D10[i]);
		free(building2D11[i]);
		free(building2D12[i]);
		free(building2D13[i]);
		free(building2D14[i]);
		free(building2D15[i]);
		free(building2D16[i]);
		free(building2D17[i]);
		free(building2D18[i]);
		free(building2D19[i]);
		free(building2D20[i]);
		free(building2D21[i]);
		free(building2D22[i]);
		free(grass2D1[i]);
		free(grass2D2[i]);
		free(square2D[i]);
		free(river2D1[i]);
		free(river2D2[i]);
		free(river2D3[i]);
		free(river2D4[i]);
		free(river2D5[i]);
		free(lake2D[i]);
	}
	for(i = 0;i<3;i++)
	{
		//free(temp3D1[i]);
		//free(temp3D2[i]);
	}
	
	getch();
    closegraph();
    return 0;
} 
