clear all;
close all;
clc;
pathname = 'C:\home\Code\matlab\data'; 
finput=fopen([pathname,'\input.txt'],'w');%写入文件路径

p =ginput();
p = p * 100;
[r,c]=size(p);            % 得到矩阵的行数和列数
 for i=1:r
  for j=1:c
  fprintf(finput,'%f ',p(i,j));
  end
  fprintf(finput,'\n');
 end
fclose(finput);
