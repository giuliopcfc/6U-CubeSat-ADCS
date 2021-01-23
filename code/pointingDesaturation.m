%% Desaturation during pointing phase
% Script to simulate the desaturation of the reaction wheel.

desaturation

%% Initial conditions:
config6U
load finalPointing

data.ic.dcm = finalPointing.ABN; 
data.ic.w = finalPointing.w;
data.ic.th = finalPointing.theta;
data.gyroscope.b0 = finalPointing.bGyro;
data.gyroscope.xObs0 = finalPointing.xObs;

% Assume that the angular momentum is close to the threshold:
data.reactionWheel.h0 = data.desaturation.hUp*0.999;

%% Simulation:
startTime = round(data.pointing.stop);
stopTime = startTime + 3*data.orbit.period;

set_param('desaturation', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outDesaturation = sim('desaturation');

%% Plots:

figure('Name','Desaturation - Angular Momentum')
hold on, grid on, box on
plot(outDesaturation.tout, outDesaturation.hR.Data(:),'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$h_r [N  m s]$')

figure('Name','Desaturation - Pointing Error')
hold on, grid on, box on
plot(outDesaturation.tout, outDesaturation.pointingErr.Data(:),'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Error [deg]')


