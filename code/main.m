clear; close all; clc;

uncontrolled
detumbling
pointing
slew

%% Load Data:
config6U

%% Uncontrolled Dynamics:
startTime = 0;
stopTime = data.orbit.period;
set_param('uncontrolled', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outUncontrolled = sim('uncontrolled');

%% Detumbling:
stopTime = data.detumbling.stop;
startTime = data.detumbling.start;
set_param('detumbling', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outDetumbling = sim('detumbling');

% Final Conditions:
finalDetumbling = struct();
finalDetumbling.ABN = outDetumbling.ABN.Data(:,:,end); 
finalDetumbling.w = outDetumbling.w.Data(end,:)';
finalDetumbling.theta = outDetumbling.theta.Data(end);
finalDetumbling.hR = outDetumbling.hR.Data(end);
finalDetumbling.bGyro = outDetumbling.bGyro.Data(end,:)';
finalDetumbling.xObs = outDetumbling.xObs.Data(end,:)';

save finalDetumbling finalDetumbling

%% Slew Manoeuver:
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

outSlew = sim('slew');

% Final Conditions:
finalSlew = struct();
finalSlew.ABN = outSlew.ABN.Data(:,:,end); 
finalSlew.w = outSlew.w.Data(end,:)';
finalSlew.theta = outSlew.theta.Data(end);
finalSlew.hR = outSlew.hR.Data(end);
finalSlew.bGyro = outSlew.bGyro.Data(end,:)';
finalSlew.xObs = outSlew.xObs.Data(end,:)';

save finalSlew finalSlew

%% Pointing:
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

outPointing = sim('pointing');

% Final Conditions:
finalPointing = struct();
finalPointing.ABN = outPointing.ABN.Data(:,:,end); 
finalPointing.w = outPointing.w.Data(end,:)';
finalPointing.theta = outPointing.theta.Data(end);
finalPointing.hR = outPointing.hR.Data(end);
finalPointing.bGyro = outPointing.bGyro.Data(end,:)';
finalPointing.xObs = outPointing.xObs.Data(end,:)';

save finalPointing finalPointing

%% Save Results:
save results outDetumbling outSlew outPointing

%% Plots

plots




