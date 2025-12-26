%plot surface
x = linspace(0,1,100);
y = linspace(0,1,100);

[X,Y] = meshgrid(x,y);
F = (1 - (sin(pi*X))).*exp(Y);

surf(X,Y,F);
xlabel('x');
ylabel('y');
zlabel('f(x,y)');

shading interp;
colorbar;