scheme = "Generate position.zcos";

// Simulate
importXcosDiagram(scheme);
typeof(scs_m);
xcos_simulate(scs_m, 4);

// Write data file
// write('data_deriv_input.txt',u_meas.values);

// Read from C program
d_est = read('data_deriv_output.txt',-1,3);


// Draw
subplot(212);
h = plot(d_est(:,1), d_est(:,2), 'g-', d_est(:,1), d_est(:,3), 'r-', d.time, d.values, 'b-', 'LineWidth',3);
legend("Estimated - no filter", "Estimated - tau = 2", "Actual");
ax=gca(),// gat the handle on the current axes
ax.data_bounds=[0 -40;30 40];
set(gca(),"grid",[1 1]);
xlabel('t[s]', 'font_style', 'times bold', 'font_size', 3);
ylabel('du(t)/dt', 'font_style', 'times bold', 'font_size', 3);

subplot(211);
h = plot(u_meas.time, u_meas.values, 'r.', u.time, u.values, 'b-', 'LineWidth',3);
legend("Measured", "Actual");
ax=gca(),// gat the handle on the current axes
ax.data_bounds=[0 0;30 200];
set(gca(),"grid",[1 1]);
xlabel('t[s]', 'font_style', 'times bold', 'font_size', 3);
ylabel('u(t)', 'font_style', 'times bold', 'font_size', 3);
