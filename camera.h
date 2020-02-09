#ifndef _CAMERA_
#define _CAMERA_

class Camera
{
private:
    double R_[9];
    double t_[3];
    double c_[2];
    double f_;
    double dist_[2];

    
public:
    double p_i[2]{};
    double p_w[3]{};
    double dir_[3]{};
    //相机投影过程
    double* projection(double* p3d);

    //相机在世界坐标中的位置 -R^T*t
    double* pos_in_world();

    //相机在世界坐标中的方向
    double* dir_in_world();

    //构造函数
    Camera(double f,double* dist,double* c,double* R,double* t)
    :f_(f){
        dist_[0] = dist[0];
        dist_[1] = dist[1];
        c_[0] = c[0];
        c_[1] = c[1];
        R_[0] = R[0]; R_[1] = R[1]; R_[2] = R[2];
        R_[3] = R[3]; R_[4] = R[4]; R_[5] = R[5];
        R_[6] = R[6]; R_[7] = R[7]; R_[8] = R[8];
        t_[0] = t[0]; t_[1] = t[1]; t_[2] = t[2];


    }

};

#endif