data = struct();

%% Inertia properties of the spacecraft:
data.sc.Ix = 6.2754346e-2;
data.sc.Iy = 1.1345441e-1;
data.sc.Iz = 1.6171740e-1;

data.sc.inertiaMatrix = [data.sc.Ix 0 0; 0 data.sc.Iy 0; 0 0 data.sc.Iz];
data.sc.invI = inv(data.sc.inertiaMatrix);

%% Orbit:
data.orbit.a = 6971;
data.orbit.e = 0.02;
data.orbit.i = 70*pi/180;
data.orbit.OM = 0*pi/180;
data.orbit.om = 0*pi/180;
data.orbit.period = 2*pi*sqrt(data.orbit.a^3/398600);
data.orbit.n = sqrt(398600/data.orbit.a^3);

%% Magnetic Torque:
data.magneticTorque.m = [0.05; 0.05; 0.05];

%% SRP:

% Normal versors:
n1 = [0; 1; 0]; n2 = [0; 0; -1]; n3 = [-1; 0; 0];
NBMat = nan(3,14);
NBMat(:,1) = n1; NBMat(:,2) = -n1;
NBMat(:,3) = n2; NBMat(:,4) = -n2;
NBMat(:,[5 7 9 11 13]) = n3.*ones(3,5); NBMat(:,[6 8 10 12 14]) = -n3.*ones(3,5);
data.SRP.NBMat = NBMat;

% Areas:
U = 100e-3;
a1 = 3*U^2; a2 = 6*U^2; a3 = 2*U^2;
data.SRP.aSurf = [a2*ones(4,1); a1*[1;1]; a2*ones(8,1)];
data.SRP.aSurf = [a1; a1; a2; a2; a3; a3; a1; a1; a1; a1; a2; a2; a2; a2];

% Positions:
data.sc.rCOM = [-130e-3; -25e-3; -10e-3];

rSurf1 = nan(3,14);
rSurf1(:,1) = [-1.5*U; 1*U; 0]; rSurf1(:,2) = [-1.5*U; -1*U; 0];
rSurf1(:,3) = [-1.5*U; 0; -0.5*U]; rSurf1(:,4) = [-1.5*U; 0; 0.5*U];
rSurf1(:,5) = [-3*U; 0; 0]; rSurf1(:,6) = [0; 0; 0];
rSurf1(:,[7 8]) = [0; 2.5*U; 0].*ones(3,2); rSurf1(:,[9 10]) = [0; -2.5*U; 0].*ones(3,2);
rSurf1(:,[11 12]) = [0; 0; -2*U].*ones(3,2); rSurf1(:,[13 14]) = [0; 0; 2*U].*ones(3,2);

data.SRP.rSurf = rSurf1-data.sc.rCOM;

rhoSB = 0.5; rhoSP = 0.8; rhoDB = 0.1; rhoDP = 0.1;
data.SRP.rhoS = [rhoSB*ones(6,1); rhoSP*ones(8,1)];
data.SRP.rhoD = [rhoDB*ones(6,1); rhoDP*ones(8,1)];

%% Drag:
data.drag.rSurf = data.SRP.rSurf;
data.drag.aSurf = data.SRP.aSurf;
data.drag.NBMat = data.SRP.NBMat;
data.drag.cd = 2.2;
data.drag.rho = 1.454*1e-13; % From CIRA-72 Model

%% Star Sensor:
data.starSensor.FOV = 20*pi/180;
data.starSensor.ABS = [0 1 0; 0 0 1; 1 0 0]';
data.starSensor.sampleTime = 1;
data.starSensor.NStars = 4;
data.starSensor.sigmaCross = 1.5/3600*pi/180;
data.starSensor.sigmaRoll = 9/3600*pi/180;

%% Gyroscope:
sampleTime = 0.1;
data.gyroscope.sampleTime = sampleTime;
data.gyroscope.sigmaN = 0.15*pi/180/sqrt(3600)/sqrt(sampleTime);
data.gyroscope.sigmaB = 3e-4*pi/180/sqrt(3600)/sqrt(sampleTime);
data.gyroscope.kObsW = 0.05;
data.gyroscope.xObs0 = zeros(6,1);
data.gyroscope.kObsD = 5.8e-4;
data.gyroscope.b0 = [1;1;1]*0.3*pi/180/3600;

%% Magnetometer:
data.magnetometer.sigma = 16e-9;
data.magnetometer.sampleTime = 1;
rho = 1*pi/180; phi = -rho; lambda = rho;
data.magnetometer.nonOrthogonality = [  1               0               0;
                                        sin(rho)        cos(rho)        0;
                                        sin(phi)*cos(lambda) sin(lambda) cos(phi)*cos(lambda)];

%% Reaction Wheels:
data.reactionWheel.axis = [0;0;1];
data.reactionWheel.hMax = 10e-3;
data.reactionWheel.MMax = 1e-3;
data.reactionWheel.h0 = 0;

%% Magnetorquer:
data.magnetorquer.DMax = [0.3; 0.3; 0.34];

%% Detumbling:
data.detumbling.tDamping = 3500;
data.detumbling.kDamping = 1e7;
data.detumbling.tProp = 500 + data.detumbling.tDamping;
data.detumbling.kProp = 1e-1;

%% Slew Motion:
data.slew.kWE = 1;
data.slew.kAE = 2e-3;

%% Pointing:
linearControlDesign

%% Control Times:
startDetumbling = 0;
stopDetumbling = data.detumbling.tProp;
startSlew = stopDetumbling;
stopSlew = startSlew + 3500;
startPointing = stopSlew;
stopPointing = startPointing + 2*data.orbit.period;

data.detumbling.start = startDetumbling;
data.detumbling.stop = stopDetumbling;
data.slew.start = startSlew;
data.slew.stop = stopSlew;
data.pointing.start = startPointing;
data.pointing.stop = stopPointing;


%% Initial conditions:
data.ic.w = [9;-7;10]*pi/180;
data.ic.dcm = eye(3);
data.ic.th = 0;

%% Clear Vars:
clearvars -except data 