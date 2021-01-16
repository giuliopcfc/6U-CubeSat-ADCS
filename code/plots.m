%% Setup for the plots:

set(0,'defaultTextInterpreter','latex','defaultAxesFontSize',13);
set(0,'defaultAxesTickLabelInterpreter','latex');
set(0, 'defaultLegendInterpreter','latex');

%% Uncontrolled Dynamics:

figure('Name','Uncontrolled Dynamics - Distubing Torques'),
hold on, grid on, box on
plot(outUncontrolled.tout,outUncontrolled.MGG.Data,'linewidth',1.5)
plot(outUncontrolled.tout,outUncontrolled.MMagn.Data,'linewidth',1.5)
plot(outUncontrolled.tout,outUncontrolled.MSRP.Data,'linewidth',1.5)
plot(outUncontrolled.tout,outUncontrolled.MDrag.Data,'linewidth',1.5)
legend('Gravity Gradient','Magnetic','SRP','Drag')
xlabel('$t $[s]'), ylabel('Torque $[N \, m]$')

figure('Name','Uncontrolled Dynamics - Angular Speed'),
hold on, grid on, box on
plot(outUncontrolled.tout, outUncontrolled.w.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$\vec{\omega}$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')

figure('Name','Uncontrolled Dynamics - Pointing Error')
hold on, grid on, box on
plot(outUncontrolled.tout, outUncontrolled.pointingErr.Data(:),'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Error [deg]')

figure('Name','Uncontrolled Dynamics - Direction Cosines')
hold on, grid on, box on
names = cell(9,1); index = 0;
for i = 1:3
    for j = 1:3
        index = index + 1;
        plot(outUncontrolled.tout, squeeze(outUncontrolled.ABN.Data(i,j,:)), 'linewidth',1.5);
        names{index} = ['$A_{b/n \,', num2str(i),num2str(j),'}$'];
    end 
end
legend(names)
xlabel('$t $[s]'), ylabel('Direction Cosines')

%% Detumbling:

figure('Name','Detumbling - Angular Velocity'),
hold on, grid on, box on
plot(outDetumbling.tout, outDetumbling.w.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$\vec{\omega}$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')

figure('Name','Detumbling - Direction Cosines')
hold on, grid on, box on
names = cell(9,1); index = 0;
for i = 1:3
    for j = 1:3
        index = index + 1;
        plot(outDetumbling.tout, squeeze(outDetumbling.ABN.Data(i,j,:)), 'linewidth',1.5);
        names{index} = ['$A_{b/n \,', num2str(i),num2str(j),'}$'];
    end 
end
legend(names)
xlabel('$t $[s]'), ylabel('Direction Cosines')

figure('Name','Detumbling - Pointing Error')
hold on, grid on, box on
plot(outDetumbling.tout, outDetumbling.pointingErr.Data(:),'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Error [deg]')

%% Slew:

figure('Name','Slew - Angular Velocity'),
hold on, grid on, box on
plot(outSlew.tout, outSlew.w.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$\vec{\omega}$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')

figure('Name','Slew - Direction Cosines')
hold on, grid on, box on
names = cell(9,1); index = 0;
for i = 1:3
    for j = 1:3
        index = index + 1;
        plot(outSlew.tout, squeeze(outSlew.ABN.Data(i,j,:)), 'linewidth',1.5);
        names{index} = ['$A_{b/n \,', num2str(i),num2str(j),'}$'];
    end 
end
legend(names)
xlabel('$t $[s]'), ylabel('Direction Cosines')

figure('Name','Slew - Pointing Error')
hold on, grid on, box on
plot(outSlew.tout, outSlew.pointingErr.Data(:),'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Error [deg]')

%% Earth Pointing:

figure('Name','Earth Pointing - Angular Velocity'),
hold on, grid on, box on
plot(outPointing.tout, outPointing.w.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$\vec{\omega}$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')

figure('Name','Earth Pointing - Direction Cosines')
hold on, grid on, box on
names = cell(9,1); index = 0;
for i = 1:3
    for j = 1:3
        index = index + 1;
        plot(outPointing.tout, squeeze(outPointing.ABN.Data(i,j,:)), 'linewidth',1.5);
        names{index} = ['$A_{b/n \,', num2str(i),num2str(j),'}$'];
    end 
end
legend(names)
xlabel('$t $[s]'), ylabel('Direction Cosines')

figure('Name','Earth Pointing - Pointing Error')
hold on, grid on, box on
plot(outPointing.tout, outPointing.pointingErr.Data(:),'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Error [deg]')

figure('Name','Earth Pointing - Angular Velocity Estimation Error')
hold on, grid on, box on
plot(outPointing.tout, outPointing.w.Data - outPointing.estW.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$\omega - \bar{\omega} [rad/s]$')

figure('Name','Earth Pointing - Direction Cosines Estimation Error')
hold on, grid on, box on
names = cell(9,1); index = 0;
for i = 1:3
    for j = 1:3
        index = index + 1;
        plot(outPointing.tout, squeeze(outPointing.ABN.Data(i,j,:)) - ...
            squeeze(outPointing.estABN.Data(i,j,:)), 'linewidth',1.5);
    end 
end

xlabel('$t $[s]'), ylabel('$A_{b/n} - \bar{A}_{b/n}$')

figure('Name','Earth Pointing - Disturbing Torque Estimation Error')
hold on, grid on, box on
plot(outPointing.tout, outPointing.MD.Data - outPointing.estMD.Data, 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$M_d - \bar{M}_d [N m]$')

figure('Name','Earth Pointing - Sun in FOV')
hold on, grid on, box on
plot(outPointing.tout, outPointing.isSunInFOV.Data,'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('Sun Inside FOV')
yticks([0 1])

%% Control Actions:

% RW angular momentum:
figure('Name','Reaction Wheel - Angular Momentum')
hold on, grid on, box on
plot(outDetumbling.tout, outDetumbling.hR.Data,'k', 'linewidth',1.5);
plot(outSlew.tout, outSlew.hR.Data,'k', 'linewidth',1.5);
plot(outPointing.tout, outPointing.hR.Data,'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$h_r [N  m s]$')

% RW Torque:
figure('Name','Reaction Wheel - Torque')
hold on, grid on, box on
plot(outDetumbling.tout, outDetumbling.MR.Data,'k', 'linewidth',1.5);
plot(outSlew.tout, outSlew.MR.Data,'k', 'linewidth',1.5);
plot(outPointing.tout, outPointing.MR.Data,'k', 'linewidth',1.5);
xlabel('$t $[s]'), ylabel('$M_r [N  m]$')

% Magnetic Coils:
figure('Name','Magnetic Coils - Dipole')
hold on, grid on, box on
Dx = [outDetumbling.D.Data(:,1); outSlew.D.Data(:,1); outPointing.D.Data(:,1)];
Dy = [outDetumbling.D.Data(:,2); outSlew.D.Data(:,2); outPointing.D.Data(:,2)];
Dz = [outDetumbling.D.Data(:,3); outSlew.D.Data(:,3); outPointing.D.Data(:,3)];
plot([outDetumbling.tout; outSlew.tout; outPointing.tout],Dx, 'linewidth',1.5); 
plot([outDetumbling.tout; outSlew.tout; outPointing.tout],Dy, 'linewidth',1.5); 
plot([outDetumbling.tout; outSlew.tout; outPointing.tout],Dz, 'linewidth',1.5); 
xlabel('$t $[s]'), ylabel('Dipole $ [A m^2]$')
legend('$D_x$','$D_y$','$D_z$')
