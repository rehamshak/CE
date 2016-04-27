f=inline('-2*x^3+12*x^2-20*x+8.5','x')

h=1;
yi=1

for xi=0:h:5
k1=f(xi);
k2=f(xi+h);

yi=yi+(0.5*k1+0.5*k2)*h
xi=xi+h;
end

