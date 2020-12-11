clear; close all; clc;

%% Load Data:
config

mySADCLibraryMatlab

model
%% Simulink setup:
sim_time = 2*data.orbit.period;

set_param('model', 'Solver', 'ode113',...
    'MaxStep', 'auto', 'AbsTol', 'auto', 'RelTol', 'auto',...
    'StopTime', num2str(sim_time))


%% Run Simulation:
out = sim('model');

t = out.tout;
dM = out.dM.Data;
dGG = out.dGG.Data;
dSRP = out.dSRP.Data;

figure,
plot(t,dM,t,dGG,t,dSRP)
legend('Magnetic Torque','Gravity Gradient Torque','SRP Torque')
xlabel('t [s]'), ylabel('Torque [Nm]')
