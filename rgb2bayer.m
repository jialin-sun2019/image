%% clear
clear;
close all;
clc;
%% read image
image=imread('E:\ProgramData\image\0934.jpg');
[x,y,c]=size(image);
fprintf("%d\n", x)
fprintf("%d\n", y)
fprintf("%d\n", c)

%% bayer_rggb
bayer_rggb=zeros(x,y);
for i=1:1:x/2
    for j=1:1:y/2
        bayer_rggb(i*2-1,j*2-1) = image(i*2-1, j*2-1, 1); % r
        bayer_rggb(i*2-0,j*2-1) = image(i*2-0, j*2-1, 2); % g
        bayer_rggb(i*2-1,j*2-0) = image(i*2-1, j*2-0, 2); % g
        bayer_rggb(i*2-0,j*2-0) = image(i*2-0, j*2-0, 3); % b
    end
end

%% bayer_bggr
bayer_bggr=zeros(x,y);
for i=1:1:x/2
    for j=1:1:y/2
        bayer_bggr(i*2-1,j*2-1) = image(i*2-1, j*2-1, 3); % b
        bayer_bggr(i*2-0,j*2-1) = image(i*2-0, j*2-1, 2); % g
        bayer_bggr(i*2-1,j*2-0) = image(i*2-1, j*2-0, 2); % g
        bayer_bggr(i*2-0,j*2-0) = image(i*2-0, j*2-0, 1); % r
    end
end
%% bayer_gbrg
bayer_gbrg=zeros(x,y);
for i=1:1:x/2
    for j=1:1:y/2
        bayer_gbrg(i*2-1,j*2-1) = image(i*2-1, j*2-1, 2); % g
        bayer_gbrg(i*2-0,j*2-1) = image(i*2-0, j*2-1, 3); % b
        bayer_gbrg(i*2-1,j*2-0) = image(i*2-1, j*2-0, 1); % r
        bayer_gbrg(i*2-0,j*2-0) = image(i*2-0, j*2-0, 2); % g
    end
end
%% bayer_grbg
bayer_grbg=zeros(x,y);
for i=1:1:x/2
    for j=1:1:y/2
        bayer_grbg(i*2-1,j*2-1) = image(i*2-1, j*2-1, 2); % g
        bayer_grbg(i*2-0,j*2-1) = image(i*2-0, j*2-1, 1); % r
        bayer_grbg(i*2-1,j*2-0) = image(i*2-1, j*2-0, 3); % b
        bayer_grbg(i*2-0,j*2-0) = image(i*2-0, j*2-0, 2); % g
    end
end
figure;imshow(image);title("origi");
figure;
subplot(2,2,1);imshow(uint8(bayer_rggb));title("bayer_rggb");
subplot(2,2,2);imshow(uint8(bayer_bggr));title("bayer_bggr");
subplot(2,2,3);imshow(uint8(bayer_gbrg));title("bayer_gbrg");
subplot(2,2,4);imshow(uint8(bayer_grbg));title("bayer_grbg");
