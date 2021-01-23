%% Design of the linear controller for Earth Pointing.

%% Load data:
Ix = data.sc.nomInertiaMatrix(1,1);
Iy = data.sc.nomInertiaMatrix(2,2);
Iz = data.sc.nomInertiaMatrix(3,3);

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

Cz = eye(6); 

% LQR design:

uMax = [1 1 10]*1e-5;
zMax = [1e-2 1e-2 1e-2 1e-4 1e-4 1e-4];

Wzz = diag(1./zMax.^2);
Wuu = diag(1./uMax.^2);

Q = Cz'*Wzz*Cz;
R = Wuu;
S = zeros(size(A,1),size(B,2));

data.pointing.G = lqr(A,B,Q,R,S);








