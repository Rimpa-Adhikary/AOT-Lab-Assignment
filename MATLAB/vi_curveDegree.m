x = [0 1 2 3 4];
y = [1 1.8 1.3 2.5 6.3];
p = polyfit(x,y,2); 
X1 = 0:.1:4;
Y1 = polyval(p,X1);
plot(x,y,'.',X1,Y1)
xlabel('x');
ylabel('y');
legend('Datapoints','Fitted curve');