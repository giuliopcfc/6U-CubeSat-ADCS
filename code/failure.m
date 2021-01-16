
load finalSlew

pointing

data.ic.dcm = finalSlew.ABN; 
data.ic.w = finalSlew.w;
data.ic.th = finalSlew.theta;
data.gyroscope.b0 = finalSlew.bGyro;
data.reactionWheel.h0 = finalSlew.hR;
data.gyroscope.xObs0 = finalSlew.xObs;

data.reactionWheel.MMax = 0;

stopTime = data.pointing.stop;
startTime = data.pointing.start;
set_param('pointing', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.gyroscope.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

outPointing = sim('pointing');