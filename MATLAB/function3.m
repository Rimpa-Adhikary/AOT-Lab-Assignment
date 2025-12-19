x = 0.01:0.01:1;
[a,b,c] = myvalues(x);

plot(x,a,"r",x,b,"b",x,c,"g",linewidth=2);
xlabel('x');
ylabel('values');
legend('log10(x)','sqrt(x)','x^2');
title('plotting graph of log10(x),sqrt(x),x^2');