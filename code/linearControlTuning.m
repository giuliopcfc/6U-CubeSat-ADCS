Ix = 110500e-6;
Iy = 182500e-6;
Iz = 187200e-6;

MU = 398600; a = 7271; n = sqrt(MU/a^3);

Kx = (Iz - Iy)/Ix; Ky = (Iz - Ix)/Iy; Kz = (Iy - Ix)/Iz;

A = [   0           0           0           1           0           0
        0           0           0           0           1           0
        0           0           0           0           0           1
        -Kx*n^2     0           0           0           (1-Kx)*n    0
        0           -4*Ky*n^2   0           (Ky-1)*n    0           0
        0           0           -3*n^2*Kz   0           0           0
    ];

B = [ zeros(3);
      1/Ix 0 0;
      0 1/Iy 0;
      0 0 1/Iz];
  
C = [eye(3), zeros(3)];

D = zeros(3);

eigA = eig(A);

save linearSys A B C D eigA

csi = 0.5;

p =  -csi*abs(eigA) + sqrt(1 - csi^2)*eigA;

G = place(A,B,p);

pe = 6*p;

LT = place(A',C',pe);
L = LT';

Ac = A - L*C - B*G;



 

