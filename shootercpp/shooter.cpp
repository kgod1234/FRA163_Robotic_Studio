#include <iostream>
#include <math.h>
#include "shooter.h"
#include <bits/stdc++.h>
#include <iomanip>

shooter::shooter(const double length, 
                 const double angle,
                 const double delta,
                 const double max_delta,
                 const double mass){
    this->length = length;
    this->angle = angle;
    this->delta = delta;
    this->max_delta = max_delta;
    this-> mass = mass;
    height = length*sin(angle * M_PI / 180.0) + (0.02 * sin(( 90 - angle) * M_PI / 180.0));
    wide = length*cos(angle * M_PI / 180.0) + (0.02 * cos(( 90 - angle) * M_PI / 180.0));

    init_height = (length - max_delta)*sin(angle * M_PI / 180.0) + (0.02 * sin(( 90 - angle) * M_PI / 180.0));
    init_wide = (length - max_delta)*cos(angle * M_PI / 180.0) + (0.02 * cos(( 90 - angle) * M_PI / 180.0));

    last_height = (length - delta)*sin(angle * M_PI / 180.0) + (0.02 * sin(( 90 - angle) * M_PI / 180.0));
    last_wide = (length - delta)*cos(angle * M_PI / 180.0) + (0.02 * cos(( 90 - angle) * M_PI / 180.0));
}
void shooter::getShooterDimension(){
    std::cout << "Default" << '\n'; 
    std::cout << "H : " << std::setprecision(3) << height << '\n'; 
    std::cout << "W : " << wide << '\n'; 
}

void shooter::getShootingDimension(){

    std::cout << "Initialize Position" << '\n'; 
    std::cout << "H : " << std::setprecision(3) << init_height << '\n'; 
    std::cout << "W : " << init_wide << '\n'; 

    std::cout << "Last Position" << '\n'; 
    std::cout << "H : " << last_height << '\n'; 
    std::cout << "W : " << last_wide << '\n'; 
}

void shooter::setShooterDimension(const double height, const double wide){
}

double shooter::initial_v(double target){
    // double init_y = (length - delta)*sin(angle * M_PI / 180.0) + (0.02 * sin(( 90 - angle) * M_PI / 180.0));
    // double init_x = (length - delta)*cos(angle * M_PI / 180.0) + (0.02 * cos(( 90 - angle) * M_PI / 180.0));
    double sx;
    double sy = target - last_height;
    if(last_wide < max_wide){
        sx = 2 + (max_wide - last_wide);
    }
    else{
        sx = 2 + delta;
    }
    return sqrt(
        (sx*sx*9.81) / (2 * cos(angle * M_PI / 180.0) * cos(angle * M_PI / 180.0) * (sx * tan(angle * M_PI / 180.0) - sy))
    );
}

double shooter::y_dis(const double init_v){
    double sx;
    if(init_wide < max_wide){
        sx = 1 + (max_wide - last_wide);
    }
    else{
        sx = 1 + delta;
    }
    return (sx * tan(angle * M_PI / 180.0)) - (9.81 * sx * sx) / (2 * init_v * init_v * cos(angle * M_PI / 180.0) * cos(angle * M_PI / 180.0));
}

double shooter::getlastheight(){
    return last_height;
}

double shooter::findK(const double init_v){
    return  mass * ((init_v * init_v + 9.81 * (last_height - init_height)) / (max_delta * max_delta));
}