data = struct();

% Inertia properties of the spacecraft:
data.sc.mass = 1225;
data.sc.Ix = 700;
data.sc.Iy = 1100;
data.sc.Iz = 1300;
data.sc.inertiaMatrix = [data.sc.Ix 0 0; 0 data.sc.Iy 0; 0 0 data.sc.Iz];

% Magnetic Torque:
data.magneticTorque.m = [0.1; 0.1; 0.1];

% SRP:
alpha = 67.5*pi/180;
n1 = [1; 0; 0]; n2 = [0; 1; 0]; n3 = [0; 0; 1];
n7 = [0; -cos(alpha); -sin(alpha)];
data.SRP.NBMat = [n1, n2, n3, -n1, -n2, -n3, n7, -n7];

lxB = 3.4; lyB = 1.8; lzB = 2.35; 
wP = 3.9; hP = 2.2; aPanel = wP*hP;
aB14 = lyB*lzB; aB25 = lxB*lzB; aB36 = lxB*lyB;
data.SRP.aSurf = [aB14;aB25;aB36;aB14;aB25;aB36;aPanel*[1;1]];

rCOM = [1.331; -0.066; 0.035];
r1 = [lxB;0;0]; r4 = [0;0;0];
r2 = [0; lyB/2; 0]; r5 = -r2;
r3 = [0; 0; lzB/2]; r6 = -r3;
r7 = [hP/2;
      -lyB/2 - wP/2*sin(alpha);
      -lzB/2 + wP/2*cos(alpha)];
r8 = r7;
      
data.SRP.rSurf = [r1, r2, r3, r4, r5, r6, r7, r7, r8]-rCOM;

rhoSB = 0.5; rhoSP = 0.5; rhoDB = 0.1; rhoDP = 0.1;
data.SRP.rhoS = [rhoSB*ones(6,1); rhoSP*ones(2,1)];
data.SRP.rhoD = [rhoDB*ones(6,1); rhoDP*ones(4,1)];


% Orbit:
data.orbit.a = 7160;
data.orbit.e = 1.4e-4;
data.orbit.i = 98.56*pi/180;
data.orbit.OM = 0*pi/180;
data.orbit.om = 0*pi/180;

% Initial conditions:
data.ic.w = [5;10;-7]*pi/180;
data.ic.dcm = eye(3);
data.ic.quaternions = [0;0;0;1];
data.ic.th = 0;

% Constants:
data.const.MU = 398600;

% Additional Parameters:

% Rotation matrix perifocal to ECI:
OM = data.orbit.OM; i = data.orbit.i; om = data.orbit.om;
ROM = [ cos(OM) sin(OM) 0; -sin(OM) cos(OM) 0; 0 0 1];
Ri = [ 1 0 0; 0 cos(i) sin(i); 0 -sin(i) cos(i)];
Rom = [ cos(om) sin(om) 0; -sin(om) cos(om) 0; 0 0 1];
data.orbit.per2ECI = (Rom*Ri*ROM)';

data.orbit.period = 2*pi*sqrt(data.orbit.a^3/data.const.MU);