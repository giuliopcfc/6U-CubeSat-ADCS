%% Design of the linear compensator.
%{
Two decoupled systems:
    - System 1: yaw and roll axis dynamics;
    - System 2: pitch axes dynamics.
%}

%% Load data:
Ix = data.sc.Ix;
Iy = data.sc.Iy;
Iz = data.sc.Iz;

MU = 398600; a = data.orbit.a; n = sqrt(MU/a^3);

Kx = (Iz - Iy)/Ix; Ky = (Iz - Ix)/Iy; Kz = (Iy - Ix)/Iz;

A = [   0           0           0           1           0           0
        0           0           0           0           1           0
        0           0           0           0           0           1
        -Kx*n^2     0           0           0           -(Kx-1)*n   0
        0           -4*Ky*n^2   0           -(1-Ky)*n   0           0
        0           0           -3*n^2*Kz   0           0           0];

B = [   0       0       0
        0       0       0
        0       0       0
        1/Ix    0       0
        0       1/Iy    0
        0       0       1/Iz];

C  =   [1           0           0           0           0           0
        0           1           0           0           0           0
        0           0           1           0           0           0
        0           -n          0           1           0           0
        n           0           0           0           1           0
        0           0           0           0           0           1];
    
D = zeros(size(C,1),size(B,2));

Cz = eye(6); 

% LQR design:

uMax = [1 1 100]*1e-5;
zMax = [5e-3 1e-3 1e-3 1e-4 1e-4 1e-4];

Wzz = diag(1./zMax.^2);
Wuu = diag(1./uMax.^2);

Q = Cz'*Wzz*Cz;
R = Wuu;
S = zeros(size(A,1),size(B,2));

G = lqr(A,B,Q,R,S);

polesC = eig(A - B*G);

% Observer design (pole placement):
polesO = 3*polesC;

LT = place(A',C',polesO);
L = LT';

AObs = A - L*C;

%% Save Data:
data.pointing.B = B;
data.pointing.G = G;
data.pointing.AObs = AObs;
data.pointing.L = L;






