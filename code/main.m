clear; close all; clc;

%% Load Data:
config

%% Detumbling:
stopTime = data.detumbling.stop;
startTime = data.detumbling.start;
set_param('detumbling', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.starSensor.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

detumbling = sim('detumbling');

% Final Conditions:
finalDetumbling = struct();
finalDetumbling.ABN = detumbling.ABN.Data(:,:,end); 
finalDetumbling.w = detumbling.w.Data(end,:)';
finalDetumbling.theta = detumbling.theta.Data(end);
finalDetumbling.hR = detumbling.hR.Data(end);
finalDetumbling.bGyro = detumbling.bGyro.Data(end,:)';

save finalDetumbling finalDetumbling

% %% Slew Manoeuver:
% data.ic.ABN = finalDetumbling.ABN; 
% data.ic.w = finalDetumbling.w;
% data.ic.theta = finalDetumbling.theta;
% data.reactionWheels.h0 = finalDetumbling.hR;
% data.gyroscope.b0 = finalDetumbling.bGyro;
% 
% stopTime = data.slew.stop;
% startTime = data.slew.start;
% set_param('detumbling', 'Solver', 'ode15s',...
%     'MaxStep', num2str(data.starSensor.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
%     'StartTime',num2str(startTime),'StopTime', num2str(stopTime))
% 
% slew = sim('slew');
% 
% % Final Conditions:
% finalSlew = struct();
% finalSlew.ABN = slew.ABN.Data(:,:,end); 
% finalSlew.w = slew.w.Data(end,:)';
% finalSlew.theta = slew.theta.Data(end);
% finalSlew.bGyro = slew.bGyro.Data(end,:)';
% 
% save finalSlew finalSlew
