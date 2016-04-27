f=inline('exp(x)','x');


a=0
b=4
n=200
i=0
h=(b-a)/n



for xi=a:h:b-h
    
    
  i=i+h*(f(xi)+f(xi+h))/2  
    
  e=abs((53.59815003-i)/53.59815003)*100;
  sprintf('\nTrue relative error [%f%%] \n  ',e)

    
end



