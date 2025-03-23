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
7. LLVM clang-cl 8.0.1 64-bit, Windows 10, Core i7-7700K (KabyLake), 4.5 GHz.
Compiler options: `/Ox -mavx2`; overhead: `5.5` cycles/h.
8. ICC 19.0 64-bit, Windows 10, Core i7-7700K (KabyLake), 4.5 GHz.
Compiler options: `/O3 /QxSSE2`; overhead: `5.9` cycles/h.
9. Apple clang 12.0.0 64-bit, macOS 12.0.1, Apple M1, 3.5 GHz.
Compiler options: `-O3`; overhead: `0` (unestimatable).

|Platform         |1                |1              |1              |2      |2    |2   |3      |3    |3   |4      |4    |4   |5      |5    |5   |6      |6    |6   |7      |7    |7   |8      |8    |8   |9      |9    |9   |
|-----------------|-----------------|---------------|---------------|-------|-----|----|-------|-----|----|-------|-----|----|-------|-----|----|-------|-----|----|-------|-----|----|-------|-----|----|-------|-----|----|
|Hash function    |*0-15b, cycles/h*|8-28b, cycles/h|bulk, GB/s     |*0-15b*|8-28b|bulk|*0-15b*|8-28b|bulk|*0-15b*|8-28b|bulk|*0-15b*|8-28b|bulk|*0-15b*|8-28b|bulk|*0-15b*|8-28b|bulk|*0-15b*|8-28b|bulk|*0-15b*|8-28b|bulk|
|**komihash 5.15**|*10.2*           |12.1           |26.2           |*10.2* |12.0 |26.2|*12.3* |14.6 |23.1|*12.7* |13.8 |23.3|*13.2* |14.6 |25.3|*13.2* |14.6 |25.4|*11.9* |13.6 |21.3|*15.5* |18.6 |19.3|*8.2*  |8.4  |23.6|
|komihash 4.5     |*11.0*           |12.7           |26.2           |*11.1* |12.7 |26.3|*18.1* |21.9 |16.4|*12.8* |14.4 |22.4|*13.2* |15.1 |24.7|*13.8* |15.2 |24.7|*12.6* |14.5 |22.2|*18.1* |21.1 |17.2|*8.3*  |8.7  |23.6|
|komihash 4.3     |*11.2*           |13.0           |26.0           |*11.2* |13.0 |25.9|*17.9* |21.6 |16.3|*15.3* |16.3 |22.8|*15.4* |16.2 |24.4|*15.3* |16.4 |24.4|*14.1* |16.0 |22.0|*18.7* |21.5 |18.5|*8.6*  |9.0  |23.6|
|komihash 3.6     |*11.1*           |16.9           |27.5           |*11.0* |16.3 |27.5|*20.1* |24.0 |16.3|*16.0* |19.0 |22.3|*16.4* |20.3 |24.7|*15.8* |20.1 |24.7|*14.0* |22.0 |22.9|*19.5* |23.1 |18.1|*8.5*  |10.7 |23.6|
|komihash 2.8     |*11.3*           |17.4           |27.7           |*11.1* |17.7 |27.8|*21.3* |25.6 |16.2|*18.1* |22.3 |23.5|*18.5* |22.4 |24.7|*16.6* |21.2 |24.7|*13.4* |22.7 |23.7|*20.1* |23.6 |18.4|*10.1* |11.4 |23.5|
|wyhash_final4    |*14.2*           |18.2           |29.7           |*14.2* |18.2 |29.8|*25.9* |32.9 |12.5|*16.2* |19.7 |29.2|*17.6* |20.1 |30.6|*16.8* |19.7 |29.9|*15.5* |20.4 |29.8|*21.1* |26.1 |19.4|*7.9*  |8.1  |26.1|
|XXH3_64 0.8.0    |*17.5*           |21.1           |29.0           |*17.7* |21.3 |61.0|*21.8* |27.2 |29.6|*18.0* |29.3 |51.0|*16.9* |22.3 |26.6|*18.8* |23.4 |38.0|*18.4* |23.0 |48.3|*19.9* |25.8 |28.0|*8.2*  |8.2  |30.5|
|XXH64 0.8.0      |*12.7*           |17.3           |17.3           |*12.8* |17.4 |17.1|*24.3* |36.6 |8.9 |*12.5* |16.4 |18.2|*13.7* |17.7 |18.0|*15.3* |17.9 |18.1|*13.2* |17.3 |17.7|*18.8* |24.7 |16.0|*8.8*  |10.4 |14.5|

