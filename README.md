# av-test-rep

markup test:
| Compressor       | Compression | Decompression | Ratio % |
|------------------|------------:|--------------:|:-------:|
| **LZAV 5.12**    | 630 MB/s    | 3,820 MB/s    | 39.94   |
| LZ4 1.9.4        | 700 MB/s    | 4,570 MB/s    | 47.60   |
| Snappy 1.1.10    | 495 MB/s    | 3,230 MB/s    | 48.22   |
| LZF 3.6          | 395 MB/s    | 800 MB/s      | 48.15   |
| **LZAV 5.12 HI** | 139 MB/s    | 3,730 MB/s    | 34.98   |
| LZ4HC 1.9.4 -9   | 40 MB/s     | 4,360 MB/s    | 36.75   |
