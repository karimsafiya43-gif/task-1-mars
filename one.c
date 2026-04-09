#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159

int main(){
    float x_cam,y_cam,z_cam;
    float x,y,z;
    float x_angle,y_angle,z_angle;
    float x_world,y_world,z_world;
    //take the input of the object coordinates in camera frame, position of the rover, direction of rotation of the rover 
    printf("Object coordinates:  ");
    scanf("%f%f%f",&x_cam,&y_cam,&z_cam);
    printf("rover position:  ");
    scanf("%f%f%f",&x,&y,&z);
    printf("rover rotation:  ");
    scanf("%f%f%f",&x_angle,&y_angle,&z_angle);
//convert the angle in degrees to radian
    float x_a=((x_angle)/180)*pi;
    float y_a=((y_angle)/180)*pi;
    float z_a=((z_angle)/180)*pi;
//get the value for the elements in the rotation matrix
    float r11 = cos(z_a)*cos(y_a);
    float r12 = (cos(z_a)*sin(y_a)*sin(x_a))-(sin(z_a)*cos(x_a));
    float r13 = (cos(z_a)*sin(y_a)*cos(x_a))+(sin(z_a)*sin(x_a));
    float r21 = (sin(z_a)*cos(y_a));
    float r22 = (sin(z_a)*sin(y_a)*sin(x_a))+(cos(z_a)*cos(x_a));
    float r23 = (sin(z_a)*sin(y_a)*cos(x_a))-(cos(z_a)*sin(x_a));
    float r31 = -sin(y_a);
    float r32 = cos(y_a)*sin(x_a);
    float r33 = cos(y_a)*cos(x_a);
//apply the formula for the conversion of coordinates in camera frame to the world frama
    x_world = (r11*x_cam) + (r12*y_cam) + (r13*z_cam) + x;
    y_world =  (r21*x_cam) + (r22*y_cam) + (r23*z_cam) + y;
    z_world = (r31*x_cam) + (r32*y_cam) + (r33*z_cam) + z;

    printf("object coordinates in world frame: \n");
    printf(" x: %f \n",x_world);
    printf(" y: %f \n",y_world);
    printf(" z: %f \n",z_world);

}
