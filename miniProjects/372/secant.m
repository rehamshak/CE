
f=inline('x.^3-x.^2-400.*x+400','x');


format long;

X0=-5;
X1=9.5;
es=10^-4;
X2=0;

for i=1:10000

 

xtemp=X2;
X2= X1- (f(X1)*(X0-X1))/(f(X0)-f(X1));

e=abs((X2-xtemp)/X2)*100;
sprintf('\niteration number [%d] \n X0=%f , X1=%f , X2=%f approximate error = %f ',i,X0,X1,X2,e)

X0=X1;
X1=X2;


 if(e<es)
      sprintf('\n root %f',X2)
      break;
    end
   
end





