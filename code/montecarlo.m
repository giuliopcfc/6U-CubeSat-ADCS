config6U

load finalPointing

pointing

data.ic.dcm = finalPointing.ABN; 
data.ic.w = finalPointing.w;
data.ic.th = finalPointing.theta;
data.gyroscope.b0 = finalPointing.bGyro;
data.reactionWheel.h0 = finalPointing.hR;
data.gyroscope.wObs0 = finalPointing.wObs;

startTime = data.pointing.stop;
stopTime = startTime + data.orbit.period;

tspan = [startTime:10:stopTime];

set_param('pointing', 'Solver', 'ode15s',...
    'MaxStep', num2str(data.starSensor.sampleTime), 'AbsTol', '1e-8', 'RelTol', '1e-8',...
    'StartTime',num2str(startTime),'StopTime', num2str(stopTime))

sim('pointing',tspan);

tic
for i = 1:3

    outPointing = sim('pointing',tspan);

end
toc