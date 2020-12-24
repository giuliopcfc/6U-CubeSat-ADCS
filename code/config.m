data = struct();

%% Inertia properties of the spacecraft:
data.sc.mass = 12;
data.sc.Ix = 182500e-6;
data.sc.Iy = 187200e-6;
data.sc.Iz = 110500e-6;
data.sc.inertiaMatrix = [data.sc.Ix 0 0; 0 data.sc.Iy 0; 0 0 data.sc.Iz];

%% Magnetic Torque:
data.magneticTorque.m = [0.1; 0.1; 0.1];

%% SRP:

% Normal versors:
n1 = [1; 0; 0]; n2 = [0; 1; 0]; n3 = [0; 0; 1];
NBMat = nan(3,14);
NBMat(:,1) = n1; NBMat(:,2) = -n1;
NBMat(:,3) = n2; NBMat(:,4) = -n2;
NBMat(:,[5 7 9 11 13]) = n3.*ones(3,5); NBMat(:,[6 8 10 12 14]) = -n3.*ones(3,5);
data.SRP.NBMat = NBMat;

% Areas:
U = 100e-3;
a1 = 4*U^2; a2 = 2*3*U^2; 
data.SRP.aSurf = [a2*ones(4,1); a1*[1;1]; a2*ones(8,1)];

% Positions:
rCOM = [-25e-3; 37e-3; 130e-3];

rSurf1 = nan(3,14);
rSurf1(:,1) = [1*U; 0; 1.5*U]; rSurf1(:,2) = [-1*U; 0; 1.5*U];
rSurf1(:,3) = [0; 1*U; 1.5*U]; rSurf1(:,4) = [0; -1*U; 1.5*U];
rSurf1(:,5) = [0; 0; 3*U]; rSurf1(:,6) = [0; 0; 0];
rSurf1(:,[7 8]) = [2.5*U; 0; 0].*ones(3,2); rSurf1(:,[9 10]) = [-2.5*U; 0; 0].*ones(3,2);
rSurf1(:,[11 12]) = [0; 2.5*U; 0].*ones(3,2); rSurf1(:,[13 14]) = [0; -2.5*U; 0].*ones(3,2);

data.SRP.rSurf = rSurf1-rCOM;

rhoSB = 0.5; rhoSP = 0.5; rhoDB = 0.1; rhoDP = 0.1;
data.SRP.rhoS = [rhoSB*ones(6,1); rhoSP*ones(8,1)];
data.SRP.rhoD = [rhoDB*ones(6,1); rhoDP*ones(8,1)];

%% Star Sensor:
% load HYG
% data.starSensor.versStars = HYG.VERS(1:100:end,:);
% data.starSensor.FOV = 14*pi/180;
% data.starSensor.variance = (1/3600*pi/180)^2;
% data.starSensor.sampleTime = 1/5;

%% Gyroscope:
% data.gyroscope.sampleTime = 1/262;
% data.gyroscope.sigmaN = 2.6957e-06;
% data.gyroscope.sigmaB = 1.4976e-12;

%% Reaction Wheels:
data.reactionWheel.axis = eye(3);
data.reactionWheel.hMax = 30e-3;
data.reactionWheel.MMax = 2.3e-3;
data.reactionWheel.h0 = [0; 0; 0];

%% Magnetorquer:
data.magnetorquer.m0 = 1.19; 

%% Detumbling:
data.detumbling.times = [0 800 5000];
data.detumbling.kProp = -1e-1;
%% Orbit:
data.orbit.a = 7271;
data.orbit.e = 0.02;
data.orbit.i = 70*pi/180;
data.orbit.OM = 0*pi/180;
data.orbit.om = 0*pi/180;

%% Initial conditions:
data.ic.w = [8;10;-7]*pi/180*1e-4;
data.ic.dcm = eye(3);
data.ic.quaternions = [0;0;0;1];
data.ic.th = 0;

%% Constants:
data.const.MU = 398600;

%% Additional Parameters:

% Rotation matrix perifocal to ECI:
OM = data.orbit.OM; i = data.orbit.i; om = data.orbit.om;
ROM = [ cos(OM) sin(OM) 0; -sin(OM) cos(OM) 0; 0 0 1];
Ri = [ 1 0 0; 0 cos(i) sin(i); 0 -sin(i) cos(i)];
Rom = [ cos(om) sin(om) 0; -sin(om) cos(om) 0; 0 0 1];
data.orbit.per2ECI = (Rom*Ri*ROM)';

data.orbit.period = 2*pi*sqrt(data.orbit.a^3/data.const.MU);

%% Clear Vars:
clearvars -except data