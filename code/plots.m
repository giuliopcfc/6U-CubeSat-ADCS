% Setup for the plots:
set(0,'defaultTextInterpreter','latex','defaultAxesFontSize',15);
set(0,'defaultAxesTickLabelInterpreter','latex');
set(0, 'defaultLegendInterpreter','latex');

%% Uncontrolled Dynamics:

figure('Name','Uncontrolled Dynamics - Distubing Torques'),
hold on, grid on, box on
plot(outUncontrolled.tout,outUncontrolled.MGG.Data,'linewidth',1)
plot(outUncontrolled.tout,outUncontrolled.MMagn.Data,'linewidth',1)
plot(outUncontrolled.tout,outUncontrolled.MSRP.Data,'linewidth',1)
plot(outUncontrolled.tout,outUncontrolled.MDrag.Data,'linewidth',1)
legend('GG','Magnetic','SRP','Drag')
xlabel('$t [s]$'), ylabel('Torque $[N \, m]$')
% saveFigAsPdf('Uncontrolled Dynamics - Distubing Torques',0.49,1.5)

ind = outUncontrolled.tout <= 1000; 
figure('Name','Uncontrolled Dynamics - Angular Velocity'),
hold on, grid on, box on
plot(outUncontrolled.tout(ind), outUncontrolled.w.Data(ind,:), 'linewidth',1);
xlabel('$t [s]$'), ylabel('$\omega$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')
% saveFigAsPdf('Uncontrolled Dynamics - Angular Velocity',0.49,1.5)

ind = outUncontrolled.tout <= 1000; 
figure('Name','Uncontrolled Dynamics - Pointing Error')
hold on, grid on, box on
plot(outUncontrolled.tout(ind), squeeze(outUncontrolled.pointingErr.Data(ind)),'k', 'linewidth',1);
xlabel('$t [s]$'), ylabel('Error [deg]')
% saveFigAsPdf('Uncontrolled Dynamics - Pointing Error',0.49,1.5)

ind = outUncontrolled.tout <= 100; 
figure('Name','Uncontrolled Dynamics - Direction Cosines')
hold on, grid on, box on
names = cell(9,1); index = 0;
for i = 1:3
    for j = 1:3
        index = index + 1;
        plot(outUncontrolled.tout(ind), squeeze(outUncontrolled.ABN.Data(i,j,ind)), 'linewidth',1);
        names{index} = ['$A_{b/n \,', num2str(i),num2str(j),'}$'];
    end 
end
% legend(names)
xlabel('$t [s]$'), ylabel('Direction Cosines')
% saveFigAsPdf('Uncontrolled Dynamics - Direction Cosines',0.49,1.5)

%% Detumbling:

ind = outDetumbling.tout <= data.detumbling.tDamping; 
figure('Name','Detumbling - Spin Rate Damping - Angular Velocity'),
hold on, grid on, box on
plot(outDetumbling.tout(ind), outDetumbling.w.Data(ind,:), 'linewidth',1.5);
xlabel('$t [s]$'), ylabel('$\omega$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')
% saveFigAsPdf('Detumbling - Spin Rate Damping - Angular Velocity',0.49,2)

ind = outDetumbling.tout >= data.detumbling.tDamping; 
figure('Name','Detumbling - Proportional Control Law - Angular Velocity'),
hold on, grid on, box on
plot(outDetumbling.tout(ind), outDetumbling.w.Data(ind,:), 'linewidth',1.5);
xlabel('$t [s]$'), ylabel('$\omega$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')
% saveFigAsPdf('Detumbling - Proportional Control Law - Angular Velocity',0.49,2)

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
% legend(names)
xlabel('$t [s]$'), ylabel('Direction Cosines')
% saveFigAsPdf('Detumbling - Direction Cosines',0.49,2)

figure('Name','Detumbling - Pointing Error')
hold on, grid on, box on
plot(outDetumbling.tout, outDetumbling.pointingErr.Data(:),'k', 'linewidth',1.5);
xlabel('$t [s]$'), ylabel('Error [deg]')
% saveFigAsPdf('Detumbling - Pointing Error',0.49,2)

figure('Name','Detumbling - Reaction Wheel')
hold on, grid on, box on
yyaxis left
plot(outDetumbling.tout, outDetumbling.hR.Data(:), 'linewidth',3);
xlabel('$t [s]$'), ylabel('$h_r [N  m s]$')
yyaxis right
plot(outDetumbling.tout, outDetumbling.MR.Data(:), 'linewidth',3);
xlabel('$t [s]$'), ylabel('$M_r [N  m]$')
% saveFigAsPdf('Detumbling - Reaction Wheel',0.49,2)

figure('Name','Detumbling - Dipole')
hold on, grid on, box on
plot(outDetumbling.tout,outDetumbling.D.Data, 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('D $ [A m^2]$')
legend('$D_x$','$D_y$','$D_z$')
h = get(gca,'Children');
set(gca,'Children',[h(3) h(2) h(1)])
% saveFigAsPdf('Detumbling - Dipole',0.49,2)

figure('Name','Detumbling - MC')
hold on, grid on, box on
plot(outDetumbling.tout,outDetumbling.MC.Data, 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('$M_c  [N m]$')
legend('$M_{c,x}$','$M_{c,y}$','$M_{c,z}$')
% saveFigAsPdf('Detumbling - MC',0.49,2)

ind = outDetumbling.tout >= data.detumbling.tDamping; 
figure('Name','Detumbling - MC ideal - MC')
hold on, grid on, box on
plot(outDetumbling.tout(ind),outDetumbling.errMC.Data(ind,:), 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('$M_c^{id} - M_c [N m]$')
legend('$\delta M_{c,x}$','$\delta M_{c,y}$','$\delta M_{c,z}$')
% saveFigAsPdf('Detumbling - MC ideal - MC',0.49,2)

%% Slew:

figure('Name','Slew - Angular Velocity'),
hold on, grid on, box on
plot(outSlew.tout, outSlew.w.Data, 'linewidth',1.5);
plot(outSlew.tout, data.orbit.n*outSlew.tout./outSlew.tout,'k--', 'linewidth',1.5);
xlabel('$t [s]$'), ylabel('$\omega$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$','$n$')
% saveFigAsPdf('Slew - Angular Velocity',0.49,1.5)

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
% legend(names)
xlabel('$t [s]$'), ylabel('Direction Cosines')
% saveFigAsPdf('Slew - Direction Cosines',0.49,1.5)

figure('Name','Slew - Pointing Error')
hold on, grid on, box on
plot(outSlew.tout, outSlew.pointingErr.Data(:),'k', 'linewidth',1.5);
xlabel('$t [s]$'), ylabel('Error [deg]')
% saveFigAsPdf('Slew - Pointing Error',0.49,1.5)

figure('Name','Slew - Reaction Wheel')
hold on, grid on, box on
yyaxis left
plot(outSlew.tout, outSlew.hR.Data(:), 'linewidth',3);
xlabel('$t [s]$'), ylabel('$h_r [N  m s]$')
yyaxis right
plot(outSlew.tout, outSlew.MR.Data(:), 'linewidth',3);
xlabel('$t [s]$'), ylabel('$M_r [N  m]$')
% saveFigAsPdf('Slew - Reaction Wheel',0.49,1.5)

figure('Name','Slew - Dipole')
hold on, grid on, box on
plot(outSlew.tout,outSlew.D.Data, 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('D $ [A m^2]$')
legend('$D_x$','$D_y$','$D_z$')
% saveFigAsPdf('Slew - Dipole',0.49,1.5)

figure('Name','Slew - MC')
hold on, grid on, box on
plot(outSlew.tout,outSlew.MC.Data, 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('$M_c  [N m]$')
legend('$M_{c,x}$','$M_{c,y}$','$M_{c,z}$')
% saveFigAsPdf('Slew - MC',0.49,1.5)

figure('Name','Slew - MC ideal - MC')
hold on, grid on, box on
plot(outSlew.tout,outSlew.errMC.Data, 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('$M_c^{id} - M_c [N m]$')
legend('$\delta M_{c,x}$','$\delta M_{c,y}$','$\delta M_{c,z}$')
% saveFigAsPdf('Slew - MC ideal - MC',0.49,1.5)


%% Earth Pointing:

figure('Name','Earth Pointing - Angular Velocity'),
hold on, grid on, box on
plot(outPointing.tout, outPointing.w.Data, 'linewidth',1.5);
xlabel('$t [s]$'), ylabel('$\omega$ [rad/s]')
legend('$\omega_x$','$\omega_y$','$\omega_z$')
% saveFigAsPdf('Earth Pointing - Angular Velocity',0.49,2)

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
% legend(names)
xlabel('$t [s]$'), ylabel('Direction Cosines')
% saveFigAsPdf('Earth Pointing - Direction Cosines',0.49,2)


figure('Name','Earth Pointing - Pointing Error')
hold on, grid on, box on
plot(outPointing.tout, outPointing.pointingErr.Data(:),'k', 'linewidth',1.5);
xlabel('$t [s]$'), ylabel('Error [deg]')
% saveFigAsPdf('Earth Pointing - Pointing Error',0.49,2)

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
xlabel('$t [s]$'), ylabel('$A_{b/n} - \bar{A}_{b/n}$')
% saveFigAsPdf('Earth Pointing - Direction Cosines Estimation Error',0.49,2)

figure('Name','Earth Pointing - Sun in FOV')
hold on, grid on, box on
plot(outPointing.tout, outPointing.isSunInFOV.Data,'k', 'linewidth',1.5);
xlabel('$t [s]$'), ylabel('Sun Inside FOV')
yticks([0 1])
% saveFigAsPdf('Earth Pointing - Sun in FOV',0.49,2)

figure('Name','Earth Pointing - Reaction Wheel')
hold on, grid on, box on
yyaxis left
plot(outPointing.tout, outPointing.hR.Data(:), 'linewidth',3);
xlabel('$t [s]$'), ylabel('$h_r [N  m s]$')
yyaxis right
plot(outPointing.tout, outPointing.MR.Data(:), 'linewidth',3);
xlabel('$t [s]$'), ylabel('$M_r [N  m]$')
% saveFigAsPdf('Earth Pointing - Reaction Wheel',0.49,2)

figure('Name','Earth Pointing - Dipole')
hold on, grid on, box on
plot(outPointing.tout,outPointing.D.Data, 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('D $ [A m^2]$')
legend('$D_x$','$D_y$','$D_z$')
% saveFigAsPdf('Earth Pointing - Dipole',0.49,2)

figure('Name','Earth Pointing - MC')
hold on, grid on, box on
plot(outPointing.tout,outPointing.MC.Data, 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('$M_c  [N m]$')
legend('$M_{c,x}$','$M_{c,y}$','$M_{c,z}$')
h = get(gca,'Children');
set(gca,'Children',[h(3) h(2) h(1)])
% saveFigAsPdf('Earth Pointing - MC',0.49,1.5)

figure('Name','Earth Pointing - MC ideal - MC')
hold on, grid on, box on
plot(outPointing.tout,outPointing.errMC.Data, 'linewidth',1.5); 
xlabel('$t [s]$'), ylabel('$M_c^{id} - M_c [N m]$')
legend('$\delta M_{c,x}$','$\delta M_{c,y}$','$ \delta M_{c,z}$')
% saveFigAsPdf('Earth Pointing - MC ideal - MC',0.49,1.5)



