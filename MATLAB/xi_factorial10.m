n=1
while true
    f = factorial(n)
    if f>= 1e9
        break
    end
    n=n+1;
end
fprintf("1st int %d\n",n);
fprintf("Factorial is %d\n",factorial(n));



