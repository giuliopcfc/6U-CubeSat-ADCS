%% Desaturation during pointing phase
% Script to simulate the desaturation of the reaction wheel.

pointing

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

%% Simulation hLow = 0.5 * hMax:
dt = 0.1;
startTime = round(data.pointing.stop);
stopTime = startTime + 3*data.orbit.period;
tspan = linspace(startTime,stopTime,round((-startTime+stopTime)/dt));

set_param('pointing', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outDesaturation1 = sim('pointing',tspan);

%% Simulation hLow = 1e-5:
data.desaturation.hLow = 1e-5; % Desaturation OFF

outDesaturation2 = sim('pointing',tspan);

%% Plots:

figure('Name','Desaturation - Angular Momentum')
hold on, grid on, box on
plot(outDesaturation1.tout, outDesaturation1.hR.Data(:),...
    outDesaturation2.tout, outDesaturation2.hR.Data(:), 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$h_r [N  m s]$')
legend('$h_{OFF} = 5\cdot 10^{-3} \, Nms$','$h_{OFF} = 1\cdot 10^{-4} \, Nms$')
saveFigAsPdf('Desaturation - Angular Momentum',0.49,2)

figure('Name','Desaturation - Pointing Error')
hold on, grid on, box on
plot(outDesaturation1.tout, outDesaturation1.pointingErr.Data(:),...
    outDesaturation2.tout, outDesaturation2.pointingErr.Data(:), 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Error [deg]')
legend('$h_{OFF} = 5\cdot 10^{-3} \, Nms$','$h_{OFF} = 1\cdot 10^{-4} \, Nms$')
saveFigAsPdf('Desaturation - Pointing Error',0.49,2)


