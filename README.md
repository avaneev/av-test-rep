# av-test-rep

markup test:
$Q = (q_{0}, q_{1}, q_{2}, q_{3})$
$w_{0}(s_{0} \frown s_{1}) \approx w_{1}(s_{2} \frown s_{3})$
$w_{0}(X)$
$w_{1}(X)$

|Platform         |A              |A              |A              |B       |B    |B   |C       |C    |C   |D       |D    |D   |
|-----------------|---------------|---------------|---------------|--------|-----|----|--------|-----|----|--------|-----|----|
|Hash function    |0-15b, cycles/h|8-28b, cycles/h|bulk, GB/s     |0-15b   |8-28b|bulk|0-15b   |8-28b|bulk|0-15b   |8-28b|bulk|
|**komihash 5.15**|**10.2**       |12.1           |26.2           |**10.2**|12.0 |26.2|**12.3**|14.6 |23.1|**12.7**|13.8 |23.3|
|komihash 4.5     |**11.0**       |12.7           |26.2           |**11.1**|12.7 |26.3|**18.1**|21.9 |16.4|**12.8**|14.4 |22.4|
|komihash 4.3     |**11.2**       |13.0           |26.0           |**11.2**|13.0 |25.9|**17.9**|21.6 |16.3|**15.3**|16.3 |22.8|
|komihash 3.6     |**11.1**       |16.9           |27.5           |**11.0**|16.3 |27.5|**20.1**|24.0 |16.3|**16.0**|19.0 |22.3|
|komihash 2.8     |**11.3**       |17.4           |27.7           |**11.1**|17.7 |27.8|**21.3**|25.6 |16.2|**18.1**|22.3 |23.5|
|wyhash_final4    |**14.2**       |18.2           |29.7           |**14.2**|18.2 |29.8|**25.9**|32.9 |12.5|**16.2**|19.7 |29.2|
|XXH3_64 0.8.0    |**17.5**       |21.1           |29.0           |**17.7**|21.3 |61.0|**21.8**|27.2 |29.6|**18.0**|29.3 |51.0|
|XXH64 0.8.0      |**12.7**       |17.3           |17.3           |**12.8**|17.4 |17.1|**24.3**|36.6 |8.9 |**12.5**|16.4 |18.2|

