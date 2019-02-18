clc; close all; clear all;

im= dlmread('cameraman.txt');
subplot(1,3,1); imagesc(im(2:end,:)); colormap('gray');
title('Original image');

im= dlmread('cameraman_with_10_percent_pepper.txt');
subplot(1,3,2); imagesc(im(2:end,:)); colormap('gray');
title({'Image with 10 percent','pepper noise'});

im= dlmread('cameraman_with_10_percent_pepper_after_median_filtering.txt');
subplot(1,3,3); imagesc(im(2:end,:)); colormap('gray');
title({'Image with 10 percent','pepper noise','after median filtering'});
