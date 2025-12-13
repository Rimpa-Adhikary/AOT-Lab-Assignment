x = input("Enter the number :");
if x<50 
    fprintf("%d Less than 50",x);
elseif x>=50 && x<=100
    fprintf(" %d In between 50 and 100",x);
elseif (x >100 )
    fprintf("%d Greater than 100",x);
else
    fprintf("Invalid input");
end