f = @(x) x.^2 + 3*x +1;
x = -2:0.1:2;
y=f(x);
plot(x,y,'r',linewidth=2);
xlabel('x');
ylabel('f(x)');
title('x vs f(x) graph');