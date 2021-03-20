data = struct();

%% Initial conditions:
% Angular Velocity:
data.ic.w = [10;-11;8]*pi/180;
% Direction Cosines Matrix:
data.ic.dcm = eye(3);
% True Anomaly:
data.ic.th = 0;

%% Inertia properties of the spacecraft:

% Moments of inertia:
data.sc.Ix = 6.2754346e-2;
data.sc.Iy = 1.1345441e-1;
data.sc.Iz = 1.6171740e-1;

% Inertia Matrix:
data.sc.inertiaMatrix = [data.sc.Ix 0 0; 0 data.sc.Iy 0; 0 0 data.sc.Iz];
data.sc.invI = inv(data.sc.inertiaMatrix);

% Nominal values for observer and control:
data.sc.nomInertiaMatrix = data.sc.inertiaMatrix ;
data.sc.nomInvI = data.sc.invI;

%% Orbit:
% Keplerian Elements:
data.orbit.a = 6971;
data.orbit.e = 0.01;
data.orbit.i = 40*pi/180;
data.orbit.OM = 0*pi/180;
data.orbit.om = 0*pi/180;

data.orbit.period = 2*pi*sqrt(data.orbit.a^3/398600);
data.orbit.n = sqrt(398600/data.orbit.a^3); % Mean Motion

%% Magnetic Torque:
% Residual Magnetic Dipole:
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

% Positions of the centroids:
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
data.drag.rho = 1.454e-13; % Air density from CIRA-72 Model

%% Star Sensor:
data.starSensor.FOV = 20*pi/180;
data.starSensor.ABS = [0 1 0; 0 0 1; 1 0 0]';
data.starSensor.sampleTime = 0.1;
data.starSensor.NStars = 4;
data.starSensor.maxSlewRate = 0.5*pi/180;

% Noise:
data.starSensor.sigmaCross = 1.5/3600*pi/180;
data.starSensor.sigmaRoll = 9/3600*pi/180;

%% Gyroscope:
sampleTime = 0.01;
% Noise:
data.gyroscope.sampleTime = sampleTime;
data.gyroscope.sigmaN = 0.15*pi/180/sqrt(3600)/sqrt(sampleTime);
data.gyroscope.sigmaB = 3e-4*pi/180/sqrt(3600)/sqrt(sampleTime);
data.gyroscope.b0 = [1;1;1]*0.3*pi/180/3600;

% Extended state observer:
data.gyroscope.kObsW = 0.05;
data.gyroscope.kObsD = 5.8e-4;
data.gyroscope.xObs0 = zeros(6,1);

%% Magnetometer:
data.magnetometer.sigma = 16e-9;
data.magnetometer.sigmaAngle = 1*pi/180;
data.magnetometer.sampleTime = 1/18;

%% Reaction Wheels:
data.reactionWheel.axis = [0;0;1];
data.reactionWheel.hMax = 10e-3;
data.reactionWheel.MMax = 1e-3;
data.reactionWheel.h0 = 0; % Initial Angular Momentum

%% Magnetorquer:
data.magnetorquer.DMax =[0.3; 0.3; 0.34]; % Maximum Dipole

%% Detumbling:
data.detumbling.kDamping = 1e7;
data.detumbling.kProp = 1e-2;

% Time Scheduling:
data.detumbling.tDamping = 4000; % Spin Damping - Final Time
data.detumbling.tProp = 1000 + data.detumbling.tDamping; % Proportional - Final Time

%% Slew Motion:
data.slew.kWE = 1e-1;
data.slew.kAE = 1e-4;

slewDuration = 4000;

%% Pointing:
% Design of the liner controller:
linearControlDesign

pointingDuration = 2*data.orbit.period;

%% Time Scheduling for control:
startDetumbling = 0;
stopDetumbling = data.detumbling.tProp;
startSlew = stopDetumbling;
stopSlew = startSlew + slewDuration;
startPointing = stopSlew;
stopPointing = startPointing + pointingDuration;

data.detumbling.start = startDetumbling;
data.detumbling.stop = stopDetumbling;
data.slew.start = startSlew;
data.slew.stop = stopSlew;
data.pointing.start = startPointing;
data.pointing.stop = stopPointing;

%% Clear Vars:
% clearvars -except data