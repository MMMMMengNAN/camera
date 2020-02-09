#include "camera.h"

double* Camera::projection(double* p3d)
    {
        //世界坐标到相机坐标
        double xc = R_[0]*p3d[0]+R_[1]*p3d[1]+R_[2]*p3d[2]+t_[0];
        double yc = R_[3]*p3d[0]+R_[4]*p3d[1]+R_[5]*p3d[2]+t_[1];
        double zc = R_[6]*p3d[0]+R_[7]*p3d[1]+R_[8]*p3d[2]+t_[1];

        //相机坐标系到像平面
        double x = xc/zc;
        double y = yc/zc;

        //理想物理像平面
        double u = f_*x;
        double v = f_*y;

        //径向畸变过程
        double r2 = u*u + v*v;
        double distort_ratio = 1+dist_[0]*r2+dist_[1]*r2*r2;

        
        p_i[0] = u*distort_ratio+c_[0];
        p_i[1] = v*distort_ratio+c_[1];
        return p_i;

    }

//相机在世界坐标中的位置 -R^T*t
double* Camera::pos_in_world()
{

    p_w[0] = -(R_[0]*t_[0]+R_[3]*t_[1]+R_[6]*t_[2]);
    p_w[1] = -(R_[1]*t_[0]+R_[4]*t_[1]+R_[7]*t_[2]);
    p_w[2] = -(R_[2]*t_[0]+R_[5]*t_[1]+R_[8]*t_[2]);
    return p_w;

}

//相机在世界坐标中的方向
double* Camera::dir_in_world()
{
    dir_[0] = R_[6];
    dir_[1] = R_[7];
    dir_[2] = R_[8];
    return dir_;

}