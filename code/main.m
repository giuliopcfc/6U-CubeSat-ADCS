clear; close all; clc;

%% Load Data:
config

libraryMatlab

model
%% Simulink setup:
sim_time = 2*data.orbit.period;

set_param('model', 'Solver', 'ode15s',...
    'MaxStep', 'auto', 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StopTime', num2str(sim_time))


%% Run Simulation:
out = sim('model');

t = out.tout;
dM = out.dM.Data;
dGG = out.dGG.Data;
dSRP = out.dSRP.Data;

%%
figure,
plot(t,dM,t,dGG,t,dSRP)
legend('Magnetic Torque','Gravity Gradient Torque','SRP Torque')
xlabel('t [s]'), ylabel('Torque [Nm]')
