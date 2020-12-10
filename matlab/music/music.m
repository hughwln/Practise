clc;
clear all;
close all;

X = signal(100, 30, 0, 30);
[direction] = cal(X)

%snapshot = 4     5*5 plane array
function X = signal(theta, phi, snr, init_angle)
    dp = 0.06045;
    lambda = 0.1209;%2481MHz
    %lambda = 0.1249;%2401MHz
    antPos = ...
    [...
      -2 * dp, -2 * dp;  %1
      -2 * dp, -1 * dp;  %2
      -2 * dp,  0     ;  %3
      -2 * dp,  1 * dp;  %4
      -2 * dp,  2 * dp;  %5
      -1 * dp, -2 * dp;  %6
      -1 * dp, -1 * dp;  %7
      -1 * dp,  0     ;  %8
      -1 * dp,  1 * dp;  %9
      -1 * dp,  2 * dp;  %10
       0     , -2 * dp;  %11
       0     , -1 * dp;  %12
       0     ,  1 * dp;  %14
       0     ,  2 * dp;  %15
       1 * dp, -2 * dp;  %16
       1 * dp, -1 * dp;  %17
       1 * dp,  0     ;  %18
       1 * dp,  1 * dp;  %19
       1 * dp,  2 * dp;  %20
       2 * dp, -2 * dp;  %21
       2 * dp, -1 * dp;  %22
       2 * dp,  0     ;  %23
       2 * dp,  1 * dp;  %24
       2 * dp,  2 * dp;  %25
    ];
    for m = 1:24
        pos_x = antPos(m,1);
        pos_y = antPos(m,2);

        angle_real=cos(2 * pi / lambda * (pos_x * cos((theta-1) / 180.0 * pi) + pos_y * sin((theta-1) / 180.0 * pi)) * sin((phi-1) / 180.0 * pi));
        angle_imag=sin(2 * pi / lambda * (pos_x * cos((theta-1) / 180.0 * pi) + pos_y * sin((theta-1) / 180.0 * pi)) * sin((phi-1) / 180.0 * pi));

        AQ1(m,1) = angle_real + angle_imag * 1i;
    end
    
    len = 10.^(snr/20);
    angle = init_angle;
    for ind = 1:4
        xt(ind) = len * cos(angle / 180.0 * pi) + len * sin(angle / 180.0 * pi) * 1i;
        angle = angle + 22.5;
    end

    noise = randn(24,4)+1i*randn(24,4);
    X = AQ1 * xt + noise;
end

function [direction] = cal(X)
    dp = 0.06045;
    lambda = 0.1209;%2481MHz
    %lambda = 0.1249;%2401MHz

    antPos = ...
    [...
      -2 * dp, -2 * dp;  %1
      -2 * dp, -1 * dp;  %2
      -2 * dp,  0     ;  %3
      -2 * dp,  1 * dp;  %4
      -2 * dp,  2 * dp;  %5
      -1 * dp, -2 * dp;  %6
      -1 * dp, -1 * dp;  %7
      -1 * dp,  0     ;  %8
      -1 * dp,  1 * dp;  %9
      -1 * dp,  2 * dp;  %10
       0     , -2 * dp;  %11
       0     , -1 * dp;  %12
       0     ,  1 * dp;  %14
       0     ,  2 * dp;  %15
       1 * dp, -2 * dp;  %16
       1 * dp, -1 * dp;  %17
       1 * dp,  0     ;  %18
       1 * dp,  1 * dp;  %19
       1 * dp,  2 * dp;  %20
       2 * dp, -2 * dp;  %21
       2 * dp, -1 * dp;  %22
       2 * dp,  0     ;  %23
       2 * dp,  1 * dp;  %24
       2 * dp,  2 * dp;  %25
    ];
    
    R = X * X' / 4;
    nSource = 1;
    
    [eigVectors, eigValues] = eig(R);
    Nspace = eigVectors(:, 1:24 - nSource);          %ÔëÉù¿Õ¼ä

    for theta = 1:1:360
        for phi = 1:1:90
            for m = 1:24
                pos_x = antPos(m,1);
                pos_y = antPos(m,2);

                angle_real=cos(2 * pi / lambda * (pos_x * cos((theta-1) / 180.0 * pi) + pos_y * sin((theta-1) / 180.0 * pi)) * sin((phi-1) / 180.0 * pi));
                angle_imag=sin(2 * pi / lambda * (pos_x * cos((theta-1) / 180.0 * pi) + pos_y * sin((theta-1) / 180.0 * pi)) * sin((phi-1) / 180.0 * pi));

                AQ1(m,1) = angle_real + angle_imag * 1i;
            end  

            Power = norm(Nspace' * AQ1, 2);
            P(phi,theta) = 1./Power;

        end
    end
    showPeak(P);
    
    p_max = 0;
    for theta = 1:1:360
        for phi = 1:1:90
            if(P(phi,theta) > p_max)
                p_max = P(phi,theta);
                max_direction = [theta, phi];
            end

        end
    end
    direction = max_direction;
end

function showPeak(P)
    figure;
    mesh(P);
    title('p');
    xlabel('theta');ylabel('phi');
    zlabel('P/db');
    grid on;
end

