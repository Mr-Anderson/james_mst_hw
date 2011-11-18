%James
%Lab 1 Section E
%1.3.1 Complex Numbers
%***********************
a=3-4j
b=real(a)
c=imag(a)
d=abs(a)
e=angle(a)
f=4; g=9; h=sqrt(f)+j*sqrt(g)

%1.3.2 Matrices and Vectors
%----------------------
a=[3 4 ;2 1]
b=[1.5 -2.4 3.5 0.7; -6.2 3.1 -5.5 4.1; 1.1 2.2 -0.1 0];
b(1)
e=b(2,3)
f=b([2 3],[1 3])
g=b(2,[3 4])

h=[1 2 3];
k=[4;7]
m=[5 6;7 8];
n=[h;k m]

%1.3.3 Vectors
%--------------------------
a=[3 5 9], b=[3; 5; 9]
c=2:5, d=3:2:9
x=0.5:0.25:2.0;
y=sqrt(x);
x, y

f=[10 5 4 7 9 0]
g=[2 5 6]; 
h=f(g)

m=[1.5 -2.4 3.5 0.7; -6.2 3.1 -5.5 4.1;
1.1 2.2 -0.1 0]
n=m(1:2,2:4), o=m(:, 1:2), p=m(2, :)

%1.4 Character Strings
%--------------------------
'Signal and System Analysis'
M='MATLAB Character String'
C=M(8:16)

s='We learn to use MATLAB in EE 266 Laboratory'
k=s(10:15)

%1.5 Arithmetic Operations
%--------------------------
a=[1 2; 3 4]; b=[3 1; 7 8]; c=[2 4];
d=a+b, e=c*a, f=a^2, g=c'
h=a\b, k=b/a
m=a.*b, n=b./a, o=b.^a

a=[1.5 3.3; 6.0 -4.5; -2.5 0.7]; b=[0.5 0.3; -0.1 0.2; 0.4 -0.3]; 
c=[1 2; 1 2]; d=[3.1 1.4 -0.3; -0.5 1.6 0.1]
%a-b*c^2+2*d

%1.6 Function M-Files
%--------------------------
w=[1 2 3 4 5]
[x,y,z]=example(w);
x,y,z

t = 1
f1 =3
f2 = 7
[s1 s2 s3] = sumsin(t,f1,f2)

%1.7 Logical Operations
%--------------------------
a=[1 3 2; 4 6 5], b=a>2&a<=5
c=[1 5 3 4 7 8], d=c>4

a=[1.2 -3.2 24; 0.6 -0.3 -0.5; -2.3 1.6 20]
b1=(a(1,:)==1.2).*a(1,:);
b2=(a(2,:)<0)*2.*a(2,:);
b3=(a(3,:)==1.6).*a(3,:);
b=[1.2 0 0; 0 -0.6 -1.0; 0 1.6 0]


%1.8 Mathematical Functions
%--------------------------
t=0.1;
x=2^t*sqrt(t) -sin(2*t)/3
y=2^(t*sqrt(t)) - sin(2*t)/3
f=0:2:4; w=2*pi*f;
X=(3 -j*0.1*w)./(1.5+j*0.2*w)
t= 0:0.5:2;
x=(t+1).*(t>=0&t<1)+2*(t>=1&t<=2)

x = [-3.6, -2.5, -1.4, -1, 0, 1.4, 2.5, 3.6]
round(x)
floor(x)
ceil(x)

x = (log(2 + sin(3)^2)+exp(-0.2))/sqrt(2^1.6 +3^-.5)

t=-1.2:0.4:1.2;
x = 3*(t.^3) + 2*(t.^2) - t + sin(t)
x=0*(t<0)+2*(t>=0)


%1.9 Flow Control
%--------------------------
t=0:0.2:0.8; x=zeros(size(t));
for k=1:3;
x=x+sqrt(k)*t.^sqrt(1.2*k);
end;
x

for m=1:3;
 for n=1:4; 
  y(m,n)=m+n;
 end;
end;
y

t=0:0.5:10; y=zeros(size(t));
for q = 1:length(t);
    y = t+q;
end;

if n==2;
    y=10*d(n);
else;
    y=0;
end;

n=1;
while 2*n<5000; 
    n=2*n; 
end;
n

for k=1:4;
    if k==1; x(k)=3*k;
      else if k==2|k==4; x(k)=k/2; 
              else; x(k)=2*k;
          end;
     end;
end;
x

c='t'; n=2;
if c=='f'; 
    c='false'; 
    y=Nan; 
end;
d=0.1:0.1:0.4;
if c=='t';
    if n==2;
        y=10*d(n);
    else
       y=0;
    end;
end;
c,y

x=[];
for t=0:.1:.4;
    for f=10:5:20;
        x((t/0.1)+1,(f/5)-1)=  3*cos(2*pi *f *t +0.1);
    end;
end;
x

x=[];
for w=35:5:45;
    t=0;
    while (t.^3<10 & exp(1.2)*cos(w*t))
        x((w/5)-6) = t;
        t= t+0.01;
    end;
end;
x

x=[];cnt=1;
for t=-1:0.2:1;
    x(cnt)=exp(-abs(t));
    if(x(cnt) < 0.5) x(cnt)= 0
    cnt = cnt+1;
    end;
end;

%1.10 Numeric Functions
%--------------------------
a=[1 0 2 3 0 4];b=find(a)
n=find(a>2)

d= - 0.1:0.1:0.2; dm=meshgrid(d,1:3)

sum(dm)

t=0:0.1:1;
x=4*cos(2*pi.*t +0.2)+3 *sin(t.^3);

A=[1 4 3 2; 4 1 2 5; 3 3 5 1]
size(A)
max(A)
min(A)
mean(A)
mean(mean(A))

%1.11 Ploting Functions & Commands
%-------------------------

t=0.1:0.1:2;
x=sin(2*pi.*t);
plot(t,x)
xlabel('time domain')
ylabel('amplitude')
title('sinosodal function')

hold on;
y=cos(2*pi.*t);
plot(t,y,'-r');

hold off;
legend('sin(t)','cos(t)')

t=0:0.1:10; f1 =0.2; f2 = 0.425;
[s1 s2 s3] =sumsin(t,f1,f2);
figure(1);
hold on;
plot(t,s1,'-b');
plot(t,s2,'--r');
plot(t,s3,'-^g');
hold off;

figure(2);
subplot(3,1,1);
plot(t,s1);
subplot(3,1,2);
plot(t,s2);
subplot(3,1,3);
plot(t,s3);
