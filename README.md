# av-test-rep

$$\begin{aligned}
m_{128} &= s_{1} \cdot s_{2} \\
s_{2}' &= (s_{2} + \lfloor m_{128} / 2^{64} \rfloor + C) \mod 2^{64} \\
s_{1}' &= (m_{128} \mod 2^{64}) \oplus s_{2}'
\end{aligned}$$

