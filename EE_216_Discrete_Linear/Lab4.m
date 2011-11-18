%***********************
%James Anderson
%Lab 3 Section E
%***********************
%---------------------------------------------------------------
%Lab Procedure Part 1
%---------------------------------------------------------------


t=-0.2:0.001:0.2;

x=10*cos(2*pi*15*t+1.5)+...
    4*cos(2*pi*25*t-0.5)+6*cos(2*pi*30*t-1);
plot(t,x);

y = 4*cos(2*pi*15*t+0.8)+...
    6*cos(2*pi*25*t+0.4)+...
    8*cos(2*pi*30*t-1.6);
figure;
plot(t,y);

z = 10*cos(2*pi*15*t+0.8)+...
     4*cos(2*pi*25*t+0.4)-...
     6*cos(2*pi*30*t-1.6);
 figure;
 subplot(2,1,1)
 plot(t,x);
 subplot(2,1,2)
 plot(t,z);
 
%---------------------------------------------------------------
%Lab Procedure Part 2
%---------------------------------------------------------------

t=-0.5:0.001:0.5;

xt = -1.3-8.4*cos(1.5*pi*t-0.45)+...
    4.2*cos(23*pi*t+2.8-(pi/2))-...
    4.8*sin(12*pi*t-1.3-(pi/2));
plot(t,xt);

%single sided
As = [1.3 8.4 4.2 4.8];
Ps = [(pi) -0.45+pi 2.8-(pi/2) -1.3-(pi/2)+pi];
Fs = [0 0.75 11.5 6];
figure;
subplot(2,1,1);
stem(Fs,As);
subplot(2,1,2);
stem(Fs,Ps);

%double sided
Ad = [2.4 2.1 4.2 1.3 4.2 2.1 2.4];
Pd = [1.3+(pi/2)-pi -2.8+(pi/2) 0.45-pi pi...
    -0.45+pi 2.8-(pi/2) -1.3-(pi/2)+pi];
Fd = [-6 -11.5 -0.75 0 0.75 11.5 6];

figure(4);
subplot(2, 1, 1), stem(Fd, Ad);
axis([-12 12 -5 5]);

%---------------------------------------------------------------
%Lab Procedure Part 3
%---------------------------------------------------------------

clear all;
T=.01;
t1 = -22:T:10;
t2 = -44:T:20;
delta = (1/T) * rectpuls(t1/T);
ht=zeros(1,length(delta));
ht(1)=0;
ht(2)=0;

for n=3:length(t1)
    ht(n) = (1/((0.3/T^2)+(0.4/T)+0.8))*...
        (0.9*delta(n)+(0.2/T)*delta(n)-(0.2/T)...
        *delta(n-1)-(0.3/T^2)*ht(n-2)+...
        (0.6/T^2)*ht(n-1)+(0.4/T)*ht(n-1));
end
xt = -3.9*cos(0.2*pi*t1-1.5)+...
    3.75*cos(0.5*pi*t1-0.6)+...
    0.5*cos(1.2*pi*t1-0.2);

ytotal=T*conv(xt,ht);

x1t=-3.9*cos(0.2*pi*t1-1.5);
x2t=3.75*cos(0.5*pi*t1-0.6);
x3t=0.5*cos(1.2*pi*t1-0.2);

%y_superposition = y1t+y2t+y3t
y1t=T*conv(x1t,ht);
y2t=T*conv(x2t,ht);
y3t=T*conv(x3t,ht);

ytotalSuper=y1t+y2t+y3t;

figure 
subplot(2,1,1);
plot(t2,ytotal);

subplot(2,1,2);
plot(t2,ytotalSuper,'r');

%-----------------
%double sided
Ain = [(0.5/2) (3.75/2) (-3.9/2) 0 (-3.9/2) (3.75/2) (0.5/2)];
Aout = [max(y3t)/2 max(y2t)/2 max(y1t)/2 0 ...
    max(y1t)/2 max(y2t)/2 max(y3t)/2];
f = [-0.6 -.25 -0.1 0 0.1 0.25 0.6];

%single sided
Ains=[0 (3.9) (3.75) (0.5)];
Aouts=[0 max(y1t) max(y2t) max(y3t)];
Fs=[0 0.1 0.25 0.6];

figure(10)
stem(f,Ain,'r');
hold on;
stem(f,Aout,'g');
hold off;
title('Part 3 (f)')



%calculating input BW
Min= max(Ain)*0.2;
idx_in =find(abs(Ain)< Min);
inBW = f(idx_in(end)) - f(idx_in(1))


%calculating output BW
Mout= max(Aout)*78650.2;
idx_out =find(abs(Aout)< Mout);
outBW = f(idx_out(end)) - f(idx_out(1))