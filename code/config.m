data = struct();

% Inertia properties of the spacecraft:
data.sc.Ix = 0.09;
data.sc.Iy = 0.14;
data.sc.Iz = 0.07;
data.sc.inertiaMatrix = [data.sc.Ix 0 0; 0 data.sc.Iy 0; 0 0 data.sc.Iz];

% Magnetic Torque:
data.magneticTorque.m = [0.1; 0.1; 0.1];

% SRP:
n1 = [1; 0; 0]; n3 = [0; 1; 0]; n5 = [0; 0; 1]; n7 = [1; 0; 0];
data.SRP.NBMat = [n1, -n1, n3, -n3, n5, -n5, n7, -n7, n7, -n7];
            
aPanel = 0.3*0.2;
aB12 = 0.2*0.1; aB34 = 0.3*0.1; aB56 = 0.3*0.2;
data.SRP.aSurf = [aB12;aB12;aB34;aB34;aB56;aB56;aPanel*[1;1;1;1]];

rCOM = [0.02; 0; 0];
r1 = 0.3/2*n1; r3 = 0.2/2*n3; r5 = 0.1/2*n5;
r7 = [-0.3/2; 0.2/2 + 0.3/2; 0]; r9 = r7; r9(2) = -r9(2);
data.SRP.rSurf = [r1, -r1, r3, -r3, r5, -r5, r7, r7, r9, r9]-rCOM;

rhoSB = 0.5; rhoSP = 0.5; rhoDB = 0.1; rhoDP = 0.1;
data.SRP.rhoS = [rhoSB*ones(6,1); rhoSP*ones(4,1)];
data.SRP.rhoD = [rhoDB*ones(6,1); rhoDP*ones(4,1)];


% Orbit:
data.orbit.a = 6971;
data.orbit.e = 0.1;
data.orbit.i = 10*pi/180;
data.orbit.OM = 80*pi/180;
data.orbit.om = 123*pi/180;


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