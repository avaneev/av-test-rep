# av-test-rep

markup test:
$Q = (q_{0}, q_{1}, q_{2}, q_{3})$
$w_{0}(s_{0} \frown s_{1}) \approx w_{1}(s_{2} \frown s_{3})$
$w_{0}(X)$
$w_{1}(X)$

1. LLVM clang-cl 8.0.1 64-bit, Windows 10, Ryzen 3700X (Zen2), 4.2 GHz.
Compiler options: `/Ox /arch:sse2`; overhead: `1.8` cycles/h.
2. LLVM clang-cl 8.0.1 64-bit, Windows 10, Ryzen 3700X (Zen2), 4.2 GHz.
Compiler options: `/Ox -mavx2`; overhead: `1.8` cycles/h.
3. ICC 19.0 64-bit, Windows 10, Ryzen 3700X (Zen2), 4.2 GHz.
Compiler options: `/O3 /QxSSE2`; overhead: `2.0` cycles/h. (this is likely a
worst-case scenario, when a compiler was not cross-tuned to a competing
processor architecture; also, ICC for Windows does not support the
`__builtin_expect` and `__builtin_prefetch` intrinsics)
4. LLVM clang 12.0.1 64-bit, CentOS 8, Xeon E-2176G (CoffeeLake), 4.5 GHz.
Compiler options: `-O3 -mavx2`; overhead: `5.3` cycles/h.
5. GCC 8.5.0 64-bit, CentOS 8, Xeon E-2176G (CoffeeLake), 4.5 GHz.
Compiler options: `-O3 -msse2`; overhead: `5.8` cycles/h.
6. GCC 8.5.0 64-bit, CentOS 8, Xeon E-2176G (CoffeeLake), 4.5 GHz.
Compiler options: `-O3 -mavx2`; overhead: `5.8` cycles/h.

|Platform         |1              |1              |1              |2       |2    |2   |3       |3    |3   |4       |4    |4   |5       |5    |5   |
|-----------------|---------------|---------------|---------------|--------|-----|----|--------|-----|----|--------|-----|----|--------|-----|----|
|Hash function    |0-15b, cycles/h|8-28b, cycles/h|bulk, GB/s     |0-15b   |8-28b|bulk|0-15b   |8-28b|bulk|0-15b   |8-28b|bulk|0-15b   |8-28b|bulk|
|**komihash 5.15**|**10.2**       |12.1           |26.2           |**10.2**|12.0 |26.2|**12.3**|14.6 |23.1|**12.7**|13.8 |23.3|**13.2**|14.6 |25.3|
|komihash 4.5     |**11.0**       |12.7           |26.2           |**11.1**|12.7 |26.3|**18.1**|21.9 |16.4|**12.8**|14.4 |22.4|**13.2**|15.1 |24.7|
|komihash 4.3     |**11.2**       |13.0           |26.0           |**11.2**|13.0 |25.9|**17.9**|21.6 |16.3|**15.3**|16.3 |22.8|**15.4**|16.2 |24.4|
|komihash 3.6     |**11.1**       |16.9           |27.5           |**11.0**|16.3 |27.5|**20.1**|24.0 |16.3|**16.0**|19.0 |22.3|**16.4**|20.3 |24.7|
|komihash 2.8     |**11.3**       |17.4           |27.7           |**11.1**|17.7 |27.8|**21.3**|25.6 |16.2|**18.1**|22.3 |23.5|**18.5**|22.4 |24.7|
|wyhash_final4    |**14.2**       |18.2           |29.7           |**14.2**|18.2 |29.8|**25.9**|32.9 |12.5|**16.2**|19.7 |29.2|**17.6**|20.1 |30.6|
|XXH3_64 0.8.0    |**17.5**       |21.1           |29.0           |**17.7**|21.3 |61.0|**21.8**|27.2 |29.6|**18.0**|29.3 |51.0|**16.9**|22.3 |26.6|
|XXH64 0.8.0      |**12.7**       |17.3           |17.3           |**12.8**|17.4 |17.1|**24.3**|36.6 |8.9 |**12.5**|16.4 |18.2|**13.7**|17.7 |18.0|

