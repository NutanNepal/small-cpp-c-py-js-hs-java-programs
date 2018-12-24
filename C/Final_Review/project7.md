1.
hit rate = 0.75, miss rate = 0.25, TLB access time = 40ns;
main memory access time = 180;
effective memory access time 
= 0.75(40 + 180) + 0.25(40 + 180 + 180 + 180) = 165 + 145 = 310;

2.
virtual address 20 is physical address: 8k + 20=> 8192+20 = 8212;
virtual address 4100-> Physical address: 4k + (4100-4k) = 4100;
virtual address 8300-> Physical address: 24k +(8300-8k)
    = 24576 + (8300 - 8192) = 24684;

3.
page size = 8KB = 2^13 bytes, offset = 13 bits;
number of entries = 2^(31-13) = 2^19;
page table Load time  = 2^19 * 100 ns = 0.052.4288 s = 52.42 ms
.5242 is used for loading the page table.

Q.4.
a. Frame 14 on memory, Offset: 3;
b-> Segmentation fault since seg 0 can Read/Execute not store; 
c-> Page fault since the Page frame no. is on disk;
d-> Frame 6 on memory, Offset: 32;