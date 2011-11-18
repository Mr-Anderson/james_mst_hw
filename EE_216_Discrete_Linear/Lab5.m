%***********************
%James Anderson
%Lab 5 Section E
%***********************
%---------------------------------------------------------------
%Lab 5 Procedure Part 1
%---------------------------------------------------------------

clear all 
close all
clc

t=-0.75:0.01:0.75;
x=10*cos(24*pi*t-1.2)-8*cos(28*pi*t+1.0)+4*sin(36*pi*t+2.5);
x2=[x x x]
t2=-0.75*3:0.01:3*0.75+0.02;
figure(1);
plot(t2,x2);

%-------------
Ain=[2 4 5 0 5 4 2];
phs=[-(2.5+pi/2) -(1+pi) 1.2 0 -1.2 1+pi 2.5+pi/2 ];
f=[-18 -14 -12 0 12 14 18];
figure;
subplot(2,1,1);
stem(f,Ain);
subplot(2,1,2)
stem(f,phs);

%-------------
t=-0.25:0.0005:0.25;
x=10*cos(24*pi*t-1.2)-8*cos(28*pi*t+1.0)+4*sin(36*pi*t+2.5);

[Xn1,f1,ang1,No1,Fo1]= ctfsc(t,x);

hold on;
figure(101);
subplot(2,1,1)
stem(f1,abs(Xn1))
xlim([-50 50])
subplot(2,1,2)
stem(f1,ang1)
xlim([-50 50])
hold off;

%-----------
%part c

t=0:0.0005:0.49995;
x=10*cos(24*pi*t-1.2)-8*cos(28*pi*t+1.0)+4*sin(36*pi*t+2.5);

[Xn1,f1,ang1,No1,Fo1]= ctfsc(t,x);

hold on;
figure(102);
subplot(2,1,1)
stem(f1,abs(Xn1))
xlim([-50 50])
subplot(2,1,2)
stem(f1,ang1)
xlim([-50 50])
hold off;

%------------

t=-0.2:0.0005:0.19995;
x=10*cos(24*pi*t-1.2)-8*cos(28*pi*t+1.0)+4*sin(36*pi*t+2.5);

[Xn1,f1,ang1,No1,Fo1]= ctfsc(t,x);

hold on;
figure(103);
subplot(2,1,1)
stem(f1,abs(Xn1))
xlim([-50 50])
subplot(2,1,2)
stem(f1,ang1)
xlim([-50 50])
hold off;

%----------
N=10;

[xfs, xnn]=ctfs(t,Xn1,No1,Fo1,N);

hold on;
figure(104);
plot(t, xfs)
hold off;

%---------------------------------------------------------------
%Part 2
%---------------------------------------------------------------

t=-0.2:0.0005:0.19995;
x=10*cos(24*pi*t-1.2)-8*cos(28*pi*t+1.0)+4*sin(36*pi*t+2.5);

[Xn1,f1,ang1,No1,Fo1]= ctfsc(t,x);
Xnmax=0.2*max(abs(Xn1));
idx=find(abs(Xn1) > Xnmax);
N_idx=idx(end)-((length(Xn1)-1)/2);

[xfs]=ctfs(t,Xn1,No1,Fo1,N_idx);

hold on;
figure(105)
plot(t, x)
hold off;


%---------------------------------------------------------------
%Part 3
%---------------------------------------------------------------
t1=-2:0.002:1.998;
x1= (0.1+2*cos(2*pi*t1)).*(((t1+1.2)>=0)-((t1-1.2)>=0));

figure(106)
plot(t1,x1);

%-----------
t2=-6:0.002:5.998;
x_t=zeros(1,length(t2));
x_t=[x1 x1 x1]

figure(107)
plot(t2,x_t);

%----------
f=0.25;
[Xn,f,ang,No,Fo]= ctfsc(t2,x_t);

hold on;
figure(108);
subplot(2,1,1)
stem(f,abs(Xn))
xlim([-32*Fo 32*Fo]);
subplot(2,1,2)
stem(f,ang)
xlim([-32*Fo 32*Fo]);
hold off;

%-----------
Xnmax=0.2*max(abs(Xn));
idx=find(abs(Xn) > Xnmax);
N_idx=idx(end)-((length(Xn)-1)/2);

[xfs, xnn]=ctfs(t2,Xn,No,Fo,N_idx);

power1=(sum(abs(xnn).^2))/(sum(abs(x1).^2));
hold on;
figure(109);
plot(t2,xfs)
hold off;

%-----------
Xnmax=0.02*max(abs(Xn));
idx=find(abs(Xn) > Xnmax);
N_idx=idx(end)-((length(Xn)-1)/2);

[xfs, xnn]=ctfs(t2,Xn,No,Fo,N_idx);

power2=(sum(abs(xnn).^2))/(sum(abs(x1).^2));
hold on;
figure(110);
plot(t2,xfs)
hold off;
