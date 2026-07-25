# av-test-rep

$$\begin{aligned}
m_{128} &= (s_{1} \oplus x_{1}) \cdot (s_{2} \oplus x_{2}) \\
rh &= \left\lfloor \frac{m_{128}}{2^{64}} \right\rfloor \\
s_{2}' &= (s_{2} + rh) \mod 2^{64} \\
s_{1}' &= m_{128} \mod 2^{64} \oplus s_{2}' \\
\end{aligned}$$
