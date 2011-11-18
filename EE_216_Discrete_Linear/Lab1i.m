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
s='we learn matlab in ee216 lab'
k=s(10:15)

%1.5 Arithmetic Operations
%--------------------------
a=[1 2; 3 4]; b=[3 1; 7 8]; c=[2 4];
d=a+b, e=c*a, f=a^2, g=c'
h=a\b, k=b/a
m=a.*b, n=b./a, o=b.^a

%1.5 Arithmetic Operations
%--------------------------
