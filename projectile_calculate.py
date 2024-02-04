import math

# ref_high = float(input("reference high : ")) 
ref_high = 0.42608 # due to our desire 
wall_sx = 1.09553
target_sx = wall_sx + 1
max_angle = 57.89
MinTarget_sy = 0.755
MaxTarget_sy = MinTarget_sy + 0.48

def init_velocity(sx,sy,angle) :
    sy = sy - ref_high
    angle = math.radians(angle)
    upper = sx*sx*9.81
    lower = 2*math.cos(angle)**2
    lower2 = (sx*math.tan(angle)-sy)
    init_v = (upper / (lower * lower2))**0.5
    if lower2 < 0:
        return 0
    return init_v

def ydis(sx, init_v, angle):
    angle_rad = math.radians(angle)
    if init_v == 0:
        return 0
    y_dis = sx * math.tan(angle_rad) - ((9.81 * sx ** 2) / (2 * init_v ** 2 * math.cos(angle_rad) ** 2))
    return y_dis

def minimum_angle(sx,sy,max_angle):
    wall_sy = 0.6 - ref_high + 0.1
    init_angle = max_angle
    print("__________________________________________________________")
    print("|   At angle   |    Initial Speed     |    Ball height   |")
    print("|--------------------------------------------------------|")
    while(1) :
        init_v = init_velocity(sx,sy,init_angle)
        ball_sy = ydis(wall_sx, init_v, init_angle)
        if ball_sy < wall_sy :
            print("__________________________________________________________")
            return 0
        else :
            print(f"|     {init_angle}    |         {init_v:.2f}         |       {ball_sy:.2f}       |")
        init_angle -= 1
    return 0
        


if __name__ == "__main__":
    # target_sy = float(input("Please insert y target : "))
    Max_init_v = init_velocity(target_sx, MaxTarget_sy, 57.89)
    Min_init_v = init_velocity(target_sx, MinTarget_sy, 57.89)
    print(f"Max initial velocity (ความเร็วต้น) : {Max_init_v} \n")
    print(f"at wall ydis (ระยะ sy ณ ระยะเครื่องยิงถึงกำแพง) : {ydis(wall_sx, Max_init_v, 57.89)}\n")
    
    print(f"Max initial velocity (ความเร็วต้น) : {Min_init_v}\n")
    print(f"at wall ydis (ระยะ sy ณ ระยะเครื่องยิงถึงกำแพง : {ydis(wall_sx, Min_init_v, 57.89)}\n")
    minimum_angle(target_sx, MinTarget_sy, 57.89)
    minimum_angle(target_sx, MaxTarget_sy, 57.89)
    