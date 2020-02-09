#include <iostream>
#include "camera.h"

using namespace std;

int main()
{
    double f = 0.920227;
    double c[2]{0.0,0.0};
    double dist[2]{-0.106599,0.104383};
    double t[3]{0.0814358,0.937498,0.0887441};
    double R[9]{
        0.999796,-0.0127375,0.0156807,
        0.0128557,0.999894,-0.0073718,
        -0.0155846,0.00757181,0.999854
    };

    double p3d[3]{1.36939,-1.17123,7.04869};
    Camera cam(f,dist,c,R,t);
    
    //计算相机投影点
    cam.projection(p3d);
    cout<<"projection coord:\n"<<'('<<cam.p_i[0]<<','
        <<cam.p_i[1]<<')'<<endl;
    cout<<"result should be:\n (0.208188,-0.035398)\n\n"<<endl;

    //计算相机在世界坐标中的位置
    cam.pos_in_world();
    cout<<"cam position in world is:\n"<<'('<<cam.p_w[0]<<','
        <<cam.p_w[1]<<','<<cam.p_w[2]<<')'<<endl;
    cout<<"result should be:\n -0.0948544 -0.935689 0.0943652\n\n"<<endl;

    //相机在世界坐标中的方向
    cam.dir_in_world();
    cout<<"cam direction in world is:\n"<<'('<<cam.dir_[0]<<','
        <<cam.dir_[1]<<','<<cam.dir_[2]<<')'<<endl;
    cout<<"result should be:\n -0.0155846 0.00757181 0.999854\n"<<endl;
     cout<<"新加了一行，看一下git"<<endl;
    cin.get();
}
