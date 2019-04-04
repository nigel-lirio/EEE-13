#Initialize Variables
vp = 5
v1 = 0
v2 = 0
v3 = 0
#Construct Matrices per equation
eq1 = [4,-1,-1,-1,5] # 4V1 - V2 - V3 - V4 = 5
eq2 = [-1,3,0,-1,0] # -V1 + 3V2 - V4 = 0
eq3 = [-1,0,3,-1,5] # -V1 + 3V3 - V4 = 5
eq4 = [-1,-1,-1,4,0] # -V1 - V2 - V3 + 4V4 = 0
#Construct augmented matrix
aM = [eq1,eq2,eq3,eq4]

