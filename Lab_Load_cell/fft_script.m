script Furier transfrom
y = fft(x);
fs = 1/Ts;
f = (0:length(y)-1)*fs/length(y);
plot(f,abs(y))
xlabel('Frequency (Hz)')
ylabel('Magnitude')
title('Magnitude')