clear; close all; clc;
tic

detumbling
pointing
slew

%% Load Data:
config6U

%% Detumbling:
stopTime = data.detumbling.stop;
startTime = data.detumbling.start;
set_param('detumbling', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.starSensor.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outDetumbling = sim('detumbling');

% Final Conditions:
finalDetumbling = struct();
finalDetumbling.ABN = outDetumbling.ABN.Data(:,:,end); 
finalDetumbling.w = outDetumbling.w.Data(end,:)';
finalDetumbling.theta = outDetumbling.theta.Data(end);
finalDetumbling.hR = outDetumbling.hR.Data(end);
finalDetumbling.bGyro = outDetumbling.bGyro.Data(end,:)';
finalDetumbling.wObs = outDetumbling.wObs.Data(end,:)';

save finalDetumbling finalDetumbling

%% Slew Manoeuver:
data.ic.dcm = finalDetumbling.ABN; 
data.ic.w = finalDetumbling.w;
data.ic.th = finalDetumbling.theta;
data.gyroscope.b0 = finalDetumbling.bGyro;
data.reactionWheel.h0 = finalDetumbling.hR;
data.gyroscope.wObs0 = finalDetumbling.wObs;

stopTime = data.slew.stop;
startTime = data.slew.start;
set_param('slew', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.starSensor.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outSlew = sim('slew');

% Final Conditions:
finalSlew = struct();
finalSlew.ABN = outSlew.ABN.Data(:,:,end); 
finalSlew.w = outSlew.w.Data(end,:)';
finalSlew.theta = outSlew.theta.Data(end);
finalSlew.hR = outSlew.hR.Data(end);
finalSlew.bGyro = outSlew.bGyro.Data(end,:)';
finalSlew.wObs = outSlew.wObs.Data(end,:)';

save finalSlew finalSlew

%% Pointing:
data.ic.dcm = finalSlew.ABN; 
data.ic.w = finalSlew.w;
data.ic.th = finalSlew.theta;
data.gyroscope.b0 = finalSlew.bGyro;
data.reactionWheel.h0 = finalSlew.hR;
data.gyroscope.wObs0 = finalSlew.wObs;

stopTime = data.pointing.stop;
startTime = data.pointing.start;
set_param('pointing', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.starSensor.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outPointing = sim('pointing');

% Final Conditions:
finalPointing = struct();
finalPointing.ABN = outPointing.ABN.Data(:,:,end); 
finalPointing.w = outPointing.w.Data(end,:)';
finalPointing.theta = outPointing.theta.Data(end);
finalPointing.hR = outPointing.hR.Data(end);
finalPointing.bGyro = outPointing.bGyro.Data(end,:)';
finalPointing.wObs = outPointing.wObs.Data(end,:)';

save finalPointing finalPointing


%% Save Results:
save results outDetumbling outSlew outPointing

%% Plots

% Setup for the plots:
set(0,'defaultTextInterpreter','latex','defaultAxesFontSize',13);
set(0,'defaultAxesTickLabelInterpreter','latex');
set(0, 'defaultLegendInterpreter','latex');


% Angular speed:
figure('Name','Angular Speed - Detumbling'),
hold on, grid on, box on
plot(outDetumbling.tout, outDetumbling.w.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$\vec{\omega}$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')

figure('Name','Angular Speed - Slew')
hold on, grid on, box on
plot(outSlew.tout, outSlew.w.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$\vec{\omega}$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')

figure('Name','Angular Speed - Pointing')
hold on, grid on, box on
plot(outPointing.tout, outPointing.w.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$\vec{\omega}$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')

% Pointing Error:
figure('Name','Pointing Error - Slew')
hold on, grid on, box on
plot(outSlew.tout, outSlew.pointingErr.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Error [deg]')
legend('$x$','$y$','$z$')

figure('Name','Pointing Error - Pointing')
hold on, grid on, box on
plot(outPointing.tout, outPointing.pointingErr.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Error [deg]')
legend('$x$','$y$','$z$')

% RW angular momentum:
figure('Name','Reaction Wheel - Angular Momentum')
hold on, grid on, box on
plot(outDetumbling.tout, outDetumbling.hR.Data,'k', 'linewidth',1.5);
plot(outSlew.tout, outSlew.hR.Data,'k', 'linewidth',1.5);
plot(outPointing.tout, outPointing.hR.Data,'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$h_R$ [N/m]')

toc


