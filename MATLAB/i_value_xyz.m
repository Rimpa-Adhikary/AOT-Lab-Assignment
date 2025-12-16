syms x y z
eqn1 = x+2*y+z == 3;
eqn2 = x+2*y+2*z == 4;
eqn3 = x+4*y+9*z == 6;
res = solve([eqn1,eqn2,eqn3],[x,y,z]);
disp(res.x)
disp(res.y)
disp(res.z)
