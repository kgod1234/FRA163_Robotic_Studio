import math

# ref_high = float(input("reference high : ")) 
ref_high = 0.31078 # due to our desire 

def init_velocity(sx,sy,angle) :
    sy = sy - ref_high
    init_v = math.sqrt((math.pow(sx,2)*9.81)/
                       (2*math.pow(math.cos(math.radians(angle)),2)
                        *(sx*math.tan(math.radians(angle))-sy)))
    return init_v

def ydis(sx,init_v,angle) :
    wall_h = 0.6 - ref_high
    y_dis = (sx*math.tan(math.radians(angle))) -((9.81*math.pow(sx,2))/
                                                (2*math.pow(init_v,2)*
                                                math.pow(math.cos(math.radians(angle)),2)
                                                )
                                                )
    return y_dis

if __name__ == "__main__":
    target_sy = float(input("Please insert y target : "))
    print(f"initial velocity (ความเร็วต้น) : {init_velocity(2.117523, target_sy, 57.89)}")
    print(f"ydis (ระยะ ณ sx = parameter ตัวที่ 1) : {ydis(1.117523, init_velocity(2.117523, target_sy, 57.89), 57.89)}")