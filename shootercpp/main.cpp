#include <iostream>
#include <iomanip>
#include "shooter.h"

int main(){
    double init_angle = 57.89;
    double target = 0.755;
    double delta = 0.01465;
    double max_delta = 0.1;
    double mass = 0.124;
    // shooter shooter(0.470, 36.89, 0.01465, 0.11465);
    // shooter.getShooterDimension();
    // shooter.getShootingDimension();
    std::cout << std::setprecision(3);
    std::cout << std::fixed;
    // std::cout << std::setprecision(3) << shooter.initial_v(0.755) << '\n';
    // std::cout << std::setprecision(3) << shooter.initial_v(0.755+0.48) << '\n';
    // std::cout << std::setprecision(3) << shooter.y_dis(shooter.initial_v(0.755)) << '\n';
    // std::cout << std::setprecision(3) << shooter.y_dis(shooter.initial_v(0.755+0.48)) << '\n';
    std::cout << "Smallest initial velocity" << '\n';
    std::cout << "|-----------------------------------------------------------------------|" << '\n';
    std::cout << "|  angle   |      initial v      |  ydis at wall  |     spring const    |" << '\n';
    std::cout << "|-----------------------------------------------------------------------|" << '\n';
    while (init_angle > 35.06)
    {
        shooter shooter(0.470, init_angle, delta, max_delta, mass);
        double v = shooter.initial_v(0.755);
        double wall_h = 0.6 - shooter.getlastheight() + 0.06;
        if(shooter.y_dis(v) > wall_h){
            std::cout << "|  " << init_angle << "  |        " << v << "        |     " << shooter.y_dis(v) << "      |" 
            << "       " << shooter.findK(v) << "       |" << '\n';
        }
        init_angle = init_angle - 2;
    }
    init_angle = 57.89;
    std::cout << "|-----------------------------------------------------------------------|" << '\n';
    std::cout << "Biggest initial velocity" << '\n';
    std::cout << "|-----------------------------------------------------------------------|" << '\n';
    std::cout << "|  angle   |      initial v      |  ydis at wall  |     spring const    |" << '\n';
    std::cout << "|-----------------------------------------------------------------------|" << '\n';

    while (init_angle > 35.06)
    {
        shooter shooter(0.470, init_angle, delta, max_delta, mass);
        double v = shooter.initial_v(0.755+0.48);
        double wall_h = 0.6 - shooter.getlastheight() + 0.06;
        if(shooter.y_dis(v) > wall_h){
            std::cout << "|  " << init_angle << "  |        " << v << "        |     " << shooter.y_dis(v) << "      |" 
            << "      " << shooter.findK(v) << "       |" << '\n';
        }
        init_angle = init_angle - 2;
    }
    std::cout << "|-----------------------------------------------------------------------|" << '\n';
}