

f=inline('x.^3-x.^2-400.*x+400','x');


Xl=-5;
Xu=9.5;
es=10^-4;
Xr=0;

for i=1:10000

 

xtemp=Xr;
fl=f(Xl);
fu=f(Xu);
Xr= Xu- (fu*(Xl-Xu))/(fl-fu);
xll=0;
xuu=0;



e=abs((Xr-xtemp)/Xr)*100;
sprintf('\niteration number [%d] \n Xl=%f , Xu=%f , Xr=%f approximate error = %f ',i,Xl,Xu,Xr,e)
if (f(Xl)*f(Xr)<0 )
    
    
    xuu=Xu;
Xu=Xr;
fu=f(Xu);

if (xll==Xl)
   fl=f(Xl)/2; 
end
else if (f(Xl)*f(Xr)>0)
        xll=Xl;
Xl=Xr;

if (xuu==Xu)
   fu=f(Xu)/2; 
end
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



/*

Values ??are the same, because the Xl and Xu changed and did not remain constant for several times


*/