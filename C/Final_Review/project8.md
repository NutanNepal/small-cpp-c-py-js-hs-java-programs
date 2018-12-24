1.
1024 bytes block. 8 bytes each entry. SO, 1024/8 = 128 entries.
    So, largest possible file is (10 + 128)*1 KB = 138 KB.

2.
4 KB blocks. 4 byte per entry. So (4*2^10)/4 = 2^10 entries.
Then max file size is 4*(10+2^10+2^20+2^30) = 1074791434*4 bytes = 4 GB

3.
transfer time for 8 MB = 2^13 KB is 1s.
So for 8KB transfer time is 2^(-10)s = 0.977ms.
Total time = (4+5+0.977)*2 = about 20 ms.

So for 1 GB = 2^10 MB, transfer time is 2^7s.
Then total time to read and write os: 2(4+5+2^7*10^3) = 256,018ms = 256s.
So it takes a little more than 4 minutes.