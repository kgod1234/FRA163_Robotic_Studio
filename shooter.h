#pragma once
#include <iostream>
// #include <math.h>

class shooter {
    public :
        shooter(const double length, 
                const double angle,
                const double delta,
                const double max_delta);

        double initial_v(double target);
        double y_dis(const double init_v);
        void getShootingDimension();
        void getShooterDimension();
        double getlastheight();
        void setShooterDimension(const double heigth, const double wide);
    private :
        double angle;
        double length ,delta, max_delta;
        double wide, init_wide, last_wide;
        double height, init_height, last_height;
        double h,w,l;
        double max_wide = 0.33292;
        /*
            |\
          h | \  l
            |  \
            ----
              w  
        */
};