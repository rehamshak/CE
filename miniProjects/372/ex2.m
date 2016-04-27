
f=inline('x.^3-x.^2-400.*x+400','x');


Xl=-5;
Xu=9.5;
es=10^-4;
Xr=0;

for i=1:10000

 

xtemp=Xr;
Xr= Xu- (f(Xu)*(Xl-Xu))/(f(Xl)-f(Xu));

e=abs((Xr-xtemp)/Xr)*100;
sprintf('\niteration number [%d] \n Xl=%f , Xu=%f , Xr=%f approximate error = %f ',i,Xl,Xu,Xr,e)
if (f(Xl)*f(Xr)<0 )
Xu=Xr;
else if (f(Xl)*f(Xr)>0)
Xl=Xr;
    end
end

if (f(Xl) * f(Xr) ==0)
sprintf('\n root %f',Xr)
break;

else if(e<es)
      sprintf('\n root %f',Xr)
      break;
    end
   
end

end



