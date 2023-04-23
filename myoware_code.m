% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%   MYOWARE MATLAB CODE                                                   %
%                                                                         %
%   This script reads EMG data and plots the signal in real-time.         %
%                                                                         %
%   Eduardo Saman                                                         %
%   Last Updated: 2023-04-23                                              %
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

clc; clear all; close all;
%% LINK ARDUINO

% Define the serial port
serialPort = 'COM3';

% Create a serial object
arduino = serialport(serialPort, 9600);

% Variables 
Fs = 1000;                     % Sampling frequency (Hz)
numSamples = 1000;             % Number of samples (N)
signal = zeros(1, numSamples); % Signal Array

%% PLOT

% Create a new figure
fig = figure('Name', 'EMG Signal Plot');

% Create the plot
plt_emg = plot(signal);
xlabel('Samples (N)');
ylabel('Signal (mV)');
grid on;
yline(500)
title('EMG Signal Plot');

% Set the axis limits
xlim([0, numSamples]);
ylim([0, 1000]);

while ishandle(fig)

    % Read the EMG signal from the Arduino
    signalValue = str2double(readline(arduino));
    
    % Update the signal buffer
    signal(1:end-1) = signal(2:end);
    signal(end) = signalValue;
    
    % Update the plot
    set(plt_emg, 'YData', signal);
    drawnow;

end


