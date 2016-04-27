% Name : mohamed okasha    021110036

q1

x=[0,0,0];
a=[25 5 1 106.8;64 8 1 177.2;144 12 1 279.2];
b=a;

n=3; 
c=4; 


for j=1:c-2
for i=j+1:n
    xtmp=b(i,j)
for l=1:c
 
  b(i,l)= b(i,l)-((xtmp*b(j,l))/b(j,j));
  
   
end
end
end


x(1,n)=b(n,c)/b(n,n);

x(1,n-1)=(b(n-1,c)-b(n-1,c-1)*x(1,n))/b(n-1,c-2);

x(1,n-2)=(b(n-2,c)-b(n-2,c-2)*x(1,n-1)-x(1,n))/b(n-2,c-3);



