t = 0:.01:2;
w = 10;
y = exp(-3*t).*sin(w*t);
plot(t,y,t,exp(-3*t));
legend('Damped sine','exp');