
k=[1 9;1.5 7;5 5;8 4;10 4.2;11 4.5;13 5.5;16 7;19 9];
m=2
n1=6
sumx=0;
sumy=0;
sumsq=0;
sumqd=0;
sumfd=0;
sumxy=0;
sumxxy=0;
st=0;
for i=1:n1
 sumx=sumx+k(i,1);
 sumsq=sumsq+k(i,1)^2;
 sumqd=sumqd+k(i,1)^3;
 sumfd=sumfd+k(i,1)^4;
 sumxy=sumxy+k(i,1)*k(i,2);
 sumxxy=sumxxy+k(i,1)^2*k(i,2);
  sumy=sumy+k(i,2);
  
end
xdash=sumx/n1
ydash=sumy/n1
st=0;
for i=1:n1
  st=st+ (k(i,2)- ydash)^2;
end

x1=[0,0,0]; % coefficient a0 a1 a2

% solve equations by Gauss elimination method
a=[n1 sumx sumsq sumy;sumx sumsq sumqd sumxy;sumsq sumqd sumfd sumxxy];
b=a;
n=3; 
c=4; 
for j=1:c-2
for i=j+1:n
    xtmp=b(i,j);
for l=1:c
  b(i,l)= b(i,l)-((xtmp*b(j,l))/b(j,j));  
end
end
end

x1(1,n)=b(n,c)/b(n,n);
a0=x1(1,n);
x1(1,n-1)=(b(n-1,c)-b(n-1,c-1)*x1(1,n))/b(n-1,c-2);
a1=x1(1,n-1);
x1(1,n-2)=(b(n-2,c)-b(n-2,c-2)*x1(1,n-1)-x1(1,n))/b(n-2,c-3);
a2=x1(1,n-2);    
sr=0;

for i=1:n
  sr=sr+(k(i,2)-a0-a1*k(i,1)-a2*k(i,1)^2); 
end


syx=(sr/(n1-(m+1)));

r2=(st-sr)/st;
 sprintf('\nst=%f , sr=%f , syx=%f , r2=%f\n',st ,sr,syx,r2)   
sprintf('\n y= %f + %fx + $fx^2',a0,a1,a2)

f=inline('a0+a1*x+a2*x.^2','a0','a1','a2','x');
l = -2:0.01:2; 
% not worked !
plot (l,f(l))
