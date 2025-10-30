clc
clear all

%   1 Naloga
filename = ['C:\Users\nakoderman\Downloads\NRO_DN1\' ...
    'naloga1_1.txt'];
%delimiterIn = ' ';
headerlinesIn=';';
podatki = importdata(filename, headerlinesIn);
t = podatki.data(':');
t

%   2 Naloga
P = [];
fid = fopen('naloga1_2.txt');
fgetl(fid);
for i = 1:1:100;
    line = fgetl(fid);
    p = str2double(line);
    P(i)=p;
end;
fclose(fid);
P'

%Izris grafa
figure(1)
plot(t, P)
title('P[(t)')
xlabel('t[s]')
ylabel('P[W]')

%   3 Naloga
dx = 1/ length(P);
S = 0;                     
n = length(P);           

for i = 1:n
    if i == 1 || i == n  
        S = S + P(i);
    else              
        S = S + 2*P(i);
    end
end
I = (dx*S)/2

%izračun integrala z Matlab funkcijo trapz
It= trapz(t, P)

% Ocena napake
Napaka = I-It