%% Script for Monte Carlo simulation:
%{
Uncertain variables:
data.magneticTorque.m
data.drag.cd
data.sc.inertiaMatrix
%}
%% Load Data:
load finalSlew

pointingMonteCarlo

data.ic.dcm = finalSlew.ABN; 
data.ic.w = finalSlew.w;
data.ic.th = finalSlew.theta;
data.gyroscope.b0 = finalSlew.bGyro;
data.reactionWheel.h0 = finalSlew.hR;
data.gyroscope.xObs0 = finalSlew.xObs;

dataNom = data;

startTime = data.slew.stop;
stopTime = startTime + data.orbit.period;

tspan = [startTime:10:stopTime];

set_param('pointingMonteCarlo', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

%% Variables uncertainties:
maxM = 0.1; 
sigmaInertia = 0.02; angleInertia = 10/180*pi;
sigmaAlt = 100; 
sigmaRCOM = 0.02;

%% Simulation:
N = 50; nT = length(tspan);

errZ = nan(nT,N); meanArr = errZ; stdArr = errZ;


for i = 1:N
    
    %%%%%% Change Parameters: %%%%%% 
    % Residual magnetic induction:
    data.magneticTorque.m = (rand(3,1) - 0.5)*2*maxM;
    
    % Inertia matrix:
    angles = randn(3,1)*angleInertia; 
    psi = angles(1); phi = angles(2); theta = angles(3);
    
    R = [ cos(psi)*cos(theta), cos(phi)*sin(psi) + cos(psi)*sin(phi)*sin(theta), sin(phi)*sin(psi) - cos(phi)*cos(psi)*sin(theta)
                -cos(theta)*sin(psi), cos(phi)*cos(psi) - sin(phi)*sin(psi)*sin(theta), cos(psi)*sin(phi) + cos(phi)*sin(psi)*sin(theta)
                sin(theta),                             -cos(theta)*sin(phi),                              cos(phi)*cos(theta)];
    
    data.sc.inertiaMatrix = R*(dataNom.sc.inertiaMatrix + diag(randn(3,1)*sigmaInertia))*R';
    data.sc.invI = inv(data.sc.inertiaMatrix);
    data.sc.Ix = data.sc.inertiaMatrix(1,1); data.sc.Iy = data.sc.inertiaMatrix(2,2); data.sc.Iz = data.sc.inertiaMatrix(3,3); 
    
    % Altitude:
    data.sc.a = dataNom.orbit.a + sigmaAlt*randn;
    
    % COM position:
    data.sc.rCOM = dataNom.sc.rCOM + 0.01*rand(3,1);
    data.SRP.rSurf = dataNom.SRP.rSurf + dataNom.sc.rCOM - data.sc.rCOM;
    data.drag.rSurf = data.SRP.rSurf;
    
    %%%%%% Simulation: %%%%%% 
    outPointing = sim('pointingMonteCarlo',tspan);
    
    %%%%%% Store Results: %%%%%% 
    errZI = outPointing.pointingErr.Data(:);
    
    errZ(:,i) = errZI;
    
    stdArr(:,i) = std(errZ(:,1:i),[],2);
    meanArr(:,i) = mean(errZ(:,1:i),2);
    
    figure(1),
    grid on, box on
    plot(1:N,stdArr(end,:),'-o','linewidth',1.5)
    
    figure(2),
    clf('reset')
    hold on, grid on,box on
    plot(tspan,meanArr(:,i) + stdArr(:,i),'-.k','linewidth',1.5)
    plot(tspan,meanArr(:,i) - stdArr(:,i),'-.k','linewidth',1.5)
    plot(tspan,meanArr(:,i),'r','linewidth',1.5)
    hold off

end



