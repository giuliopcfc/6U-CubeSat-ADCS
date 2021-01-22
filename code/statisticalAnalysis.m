%% Statistical Analysis
% Script to perform a brief statistical analysis that includes three
% off-nominal cases. In each case the initial conditions are different and
% some parameters of the system are modified with respect to the nominal
% case.

%% Case 1:

% Load Data:
config6U

% Change Parameters:
data.ic.w = [7;10;-8]*pi/180;
data.ic.dcm = angle2dcm(45*pi/180,20*pi/180,75*pi/180);

data.magneticTorque.dipole = [0.1; 0.1; -0.1];

data.sc.rCOM = [-160e-3; -20e-3; 40e-3];

data.drag.cd = 2.5;

rotInertia = angle2dcm(10*pi/180,-7*pi/180,5*pi/180);
data.sc.Ix = 6.2754346e-2*(1 + 0.06);
data.sc.Iy = 1.1345441e-1*(1 - 0.1);
data.sc.Iz = 1.6171740e-1*(1 + 0.05);

data.sc.inertiaMatrix = rotInertia'*[data.sc.Ix 0 0; 0 data.sc.Iy 0; 0 0 data.sc.Iz]*rotInertia;
data.sc.invI = inv(data.sc.inertiaMatrix);

% Detumbling:
stopTime = data.detumbling.stop;
startTime = data.detumbling.start;
set_param('detumbling', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outDetumbling1 = sim('detumbling');

% Final Conditions:
finalDetumbling = struct();
finalDetumbling.ABN = outDetumbling1.ABN.Data(:,:,end); 
finalDetumbling.w = outDetumbling1.w.Data(end,:)';
finalDetumbling.theta = outDetumbling1.theta.Data(end);
finalDetumbling.hR = outDetumbling1.hR.Data(end);
finalDetumbling.bGyro = outDetumbling1.bGyro.Data(end,:)';
finalDetumbling.xObs = outDetumbling1.xObs.Data(end,:)';

% Slew Manoeuver:
data.ic.dcm = finalDetumbling.ABN; 
data.ic.w = finalDetumbling.w;
data.ic.th = finalDetumbling.theta;
data.gyroscope.b0 = finalDetumbling.bGyro;
data.reactionWheel.h0 = finalDetumbling.hR;
data.gyroscope.xObs0 = finalDetumbling.xObs;

stopTime = data.slew.stop;
startTime = data.slew.start;
set_param('slew', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outSlew1 = sim('slew');

% Final Conditions:
finalSlew = struct();
finalSlew.ABN = outSlew1.ABN.Data(:,:,end); 
finalSlew.w = outSlew1.w.Data(end,:)';
finalSlew.theta = outSlew1.theta.Data(end);
finalSlew.hR = outSlew1.hR.Data(end);
finalSlew.bGyro = outSlew1.bGyro.Data(end,:)';
finalSlew.xObs = outSlew1.xObs.Data(end,:)';

% Pointing:
data.ic.dcm = finalSlew.ABN; 
data.ic.w = finalSlew.w;
data.ic.th = finalSlew.theta;
data.gyroscope.b0 = finalSlew.bGyro;
data.reactionWheel.h0 = finalSlew.hR;
data.gyroscope.xObs0 = finalSlew.xObs;

stopTime = data.pointing.stop;
startTime = data.pointing.start;
set_param('pointing', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outPointing1 = sim('pointing');

%% Case 2:

% Load Data:
config6U

% Change Parameters:
data.ic.w = [3;13;-9]*pi/180;
data.ic.dcm = angle2dcm(135*pi/180,6*pi/180,25*pi/180);

data.magneticTorque.dipole = [0.1; 0.1; 0.1];

data.sc.rCOM = [-135e-3; +20e-3; -40e-3];

data.drag.cd = 1.5;

rotInertia = angle2dcm(5*pi/180,-10*pi/180,2*pi/180);
data.sc.Ix = 6.2754346e-2*(1 - 0.1);
data.sc.Iy = 1.1345441e-1*(1 - 0.05);
data.sc.Iz = 1.6171740e-1*(1 + 0.2);

data.sc.inertiaMatrix = rotInertia'*[data.sc.Ix 0 0; 0 data.sc.Iy 0; 0 0 data.sc.Iz]*rotInertia;
data.sc.invI = inv(data.sc.inertiaMatrix);

% Detumbling:
stopTime = data.detumbling.stop;
startTime = data.detumbling.start;
set_param('detumbling', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outDetumbling2 = sim('detumbling');

% Final Conditions:
finalDetumbling = struct();
finalDetumbling.ABN = outDetumbling2.ABN.Data(:,:,end); 
finalDetumbling.w = outDetumbling2.w.Data(end,:)';
finalDetumbling.theta = outDetumbling2.theta.Data(end);
finalDetumbling.hR = outDetumbling2.hR.Data(end);
finalDetumbling.bGyro = outDetumbling2.bGyro.Data(end,:)';
finalDetumbling.xObs = outDetumbling2.xObs.Data(end,:)';

% Slew Manoeuver:
data.ic.dcm = finalDetumbling.ABN; 
data.ic.w = finalDetumbling.w;
data.ic.th = finalDetumbling.theta;
data.gyroscope.b0 = finalDetumbling.bGyro;
data.reactionWheel.h0 = finalDetumbling.hR;
data.gyroscope.xObs0 = finalDetumbling.xObs;

stopTime = data.slew.stop;
startTime = data.slew.start;
set_param('slew', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outSlew2 = sim('slew');

% Final Conditions:
finalSlew = struct();
finalSlew.ABN = outSlew2.ABN.Data(:,:,end); 
finalSlew.w = outSlew2.w.Data(end,:)';
finalSlew.theta = outSlew2.theta.Data(end);
finalSlew.hR = outSlew2.hR.Data(end);
finalSlew.bGyro = outSlew2.bGyro.Data(end,:)';
finalSlew.xObs = outSlew2.xObs.Data(end,:)';

% Pointing:
data.ic.dcm = finalSlew.ABN; 
data.ic.w = finalSlew.w;
data.ic.th = finalSlew.theta;
data.gyroscope.b0 = finalSlew.bGyro;
data.reactionWheel.h0 = finalSlew.hR;
data.gyroscope.xObs0 = finalSlew.xObs;

stopTime = data.pointing.stop;
startTime = data.pointing.start;
set_param('pointing', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outPointing2 = sim('pointing');

%% Case 3:

% Load Data:
config6U

% Change Parameters:
data.ic.w = [8;6;-11]*pi/180;
data.ic.dcm = angle2dcm(56*pi/180,273*pi/180,98*pi/180);

data.magneticTorque.dipole = [0.1; 0.05; 0.1];

data.sc.rCOM = [-137e-3; -30e-3; 10e-3];

data.drag.cd = 2;

rotInertia = angle2dcm(280*pi/180,43*pi/180,320*pi/180);
data.sc.Ix = 6.2754346e-2*(1 - 0.1);
data.sc.Iy = 1.1345441e-1*(1 - 0.1);
data.sc.Iz = 1.6171740e-1*(1 + 0.2);

data.sc.inertiaMatrix = rotInertia'*[data.sc.Ix 0 0; 0 data.sc.Iy 0; 0 0 data.sc.Iz]*rotInertia;
data.sc.invI = inv(data.sc.inertiaMatrix);

% Detumbling:
stopTime = data.detumbling.stop;
startTime = data.detumbling.start;
set_param('detumbling', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outDetumbling3 = sim('detumbling');

% Final Conditions:
finalDetumbling = struct();
finalDetumbling.ABN = outDetumbling3.ABN.Data(:,:,end); 
finalDetumbling.w = outDetumbling3.w.Data(end,:)';
finalDetumbling.theta = outDetumbling3.theta.Data(end);
finalDetumbling.hR = outDetumbling3.hR.Data(end);
finalDetumbling.bGyro = outDetumbling3.bGyro.Data(end,:)';
finalDetumbling.xObs = outDetumbling3.xObs.Data(end,:)';

% Slew Manoeuver:
data.ic.dcm = finalDetumbling.ABN; 
data.ic.w = finalDetumbling.w;
data.ic.th = finalDetumbling.theta;
data.gyroscope.b0 = finalDetumbling.bGyro;
data.reactionWheel.h0 = finalDetumbling.hR;
data.gyroscope.xObs0 = finalDetumbling.xObs;

stopTime = data.slew.stop;
startTime = data.slew.start;
set_param('slew', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outSlew3 = sim('slew');

% Final Conditions:
finalSlew = struct();
finalSlew.ABN = outSlew3.ABN.Data(:,:,end); 
finalSlew.w = outSlew3.w.Data(end,:)';
finalSlew.theta = outSlew3.theta.Data(end);
finalSlew.hR = outSlew3.hR.Data(end);
finalSlew.bGyro = outSlew3.bGyro.Data(end,:)';
finalSlew.xObs = outSlew3.xObs.Data(end,:)';

% Pointing:
data.ic.dcm = finalSlew.ABN; 
data.ic.w = finalSlew.w;
data.ic.th = finalSlew.theta;
data.gyroscope.b0 = finalSlew.bGyro;
data.reactionWheel.h0 = finalSlew.hR;
data.gyroscope.xObs0 = finalSlew.xObs;

stopTime = data.pointing.stop;
startTime = data.pointing.start;
set_param('pointing', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outPointing3 = sim('pointing');

%% Plots:

% Setup for the plots:
set(0,'defaultTextInterpreter','latex','defaultAxesFontSize',15);
set(0,'defaultAxesTickLabelInterpreter','latex');
set(0, 'defaultLegendInterpreter','latex');

% Detumbling:
figure('Name','Detumbling - Norm Of Angular Velocity'),
hold on, grid on, box on
plot(outDetumbling1.tout,vecnorm(outDetumbling1.w.Data')', 'linewidth',1.5)
plot(outDetumbling2.tout,vecnorm(outDetumbling2.w.Data')', 'linewidth',1.5)
plot(outDetumbling3.tout,vecnorm(outDetumbling3.w.Data')', 'linewidth',1.5)
legend('Case 1','Case 2','Case 3')
xlabel('$t $[s]'), ylabel('$||\omega||$ [rad/s]')

% Slew:
figure('Name','Slew - Pointing Error')
hold on, grid on, box on
plot(outSlew1.tout,outSlew1.pointingErr.Data(:), 'linewidth',1.5)
plot(outSlew2.tout,outSlew2.pointingErr.Data(:), 'linewidth',1.5)
plot(outSlew3.tout,outSlew3.pointingErr.Data(:), 'linewidth',1.5)
legend('Case 1','Case 2','Case 3')
xlabel('$t $[s]'), ylabel('Error [deg]')

% Pointing:
figure('Name','Pointing - Pointing Error')
hold on, grid on, box on
plot(outPointing1.tout,outPointing1.pointingErr.Data(:), 'linewidth',1.5)
plot(outPointing2.tout,outPointing2.pointingErr.Data(:), 'linewidth',1.5)
plot(outPointing3.tout,outPointing3.pointingErr.Data(:), 'linewidth',1.5)
legend('Case 1','Case 2','Case 3')
xlabel('$t $[s]'), ylabel('Error [deg]')
