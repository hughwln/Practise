clear all;
close all;
clc;
pathname = 'C:\home\Code\matlab\data'; 
finput=fopen([pathname,'\input.txt'],'w');%д���ļ�·��

p =ginput();
p = p * 100;
[r,c]=size(p);            % �õ����������������
 for i=1:r
  for j=1:c
  fprintf(finput,'%f ',p(i,j));
  end
  fprintf(finput,'\n');
 end
fclose(finput);
