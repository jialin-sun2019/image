%% clear
clear;
close all;
clc;
%% read image
% image=imread('E:\ProgramData\image\0334.jpg');
image=imread('kodim19.png');
[x,y,c]=size(image);
fprintf("%d\n", x)
fprintf("%d\n", y)
fprintf("%d\n", c)

%% greyworld
R=image(:,:,1);
G=image(:,:,2);
B=image(:,:,3);
R_avg=mean(mean(R));
G_avg=mean(mean(G));
B_avg=mean(mean(B));
Grey_avg=mean([R_avg, G_avg, B_avg]);
R_k=Grey_avg/R_avg;
G_k=Grey_avg/G_avg;
B_k=Grey_avg/B_avg;
fprintf("R_k = %f\n", R_k);
fprintf("G_k = %f\n", G_k);
fprintf("B_k = %f\n", B_k);
result(:,:,1) = R_k*image(:,:,1);
result(:,:,2) = G_k*image(:,:,2);
result(:,:,3) = B_k*image(:,:,3);
figure();
imshow(uint8(image));title("original")
% subplot(122);imshow(uint8(result));title("greyworld")

%% 
ratio=10;
hist=zeros(765);
result2=zeros(x,y,c);
for i=1:1:x
    for j=1:1:y
        index=uint16(sum(image(i,j,:)))+1;
        hist(index)=hist(index)+1;
    end
end
sum_t=0;key=0;
for i=765:-1:1
    sum_t=sum_t+hist(i);
    if sum_t>x*y*ratio/100
        key=i;break;
    end
end
counter=0;
image=double(image);
avg_r=0;avg_g=0;avg_b=0;
for i=1:1:x
    for j=1:1:y
        if sum(image(i,j,:))>key
            avg_r=(avg_r*counter+image(i,j,1))/(counter+1);
            avg_g=(avg_g*counter+image(i,j,2))/(counter+1);
            avg_b=(avg_b*counter+image(i,j,3))/(counter+1);
            counter=counter+1;
        end
    end
end
fprintf("avg_r = %f\n", avg_r);
fprintf("avg_g = %f\n", avg_g);
fprintf("avg_b = %f\n", avg_b);
for i=1:x
    for j=1:y
        result2(i,j,1)=image(i,j,1)*255/avg_r;
        if result2(i,j,1)>255
            result2(i,j,1)=255;
        end
        result2(i,j,2)=image(i,j,2)*255/avg_g;
        if result2(i,j,2)>255
            result2(i,j,2)=255;
        end
        result2(i,j,3)=image(i,j,3)*255/avg_b;
        if result2(i,j,3)>255
            result2(i,j,3)=255;
        end
    end
end
figure();
subplot(121);imshow(uint8(result));title("result1");
subplot(122);imshow(uint8(result2));title("result2");
