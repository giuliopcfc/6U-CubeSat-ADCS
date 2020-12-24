clear; close all; clc;

%% Load Data:
config

% libraryMatlab
% 
% model
%% Simulink setup:
sim_time = 2*data.orbit.period;

set_param('model', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.starSensor.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StopTime', num2str(sim_time))


%% Run Simulation:
tic
out = sim('model');
toc

t = out.tout;
dM = out.dM.Data;
dGG = out.dGG.Data;
dSRP = out.dSRP.Data;
errStarSensor = out.errStarSensor.Data;

%%
figure,
plot(t,dM,t,dGG,t,dSRP)
legend('Magnetic Torque','Gravity Gradient Torque','SRP Torque')
xlabel('t [s]'), ylabel('Torque [Nm]')

figure,
plot(t,errStarSensor)


