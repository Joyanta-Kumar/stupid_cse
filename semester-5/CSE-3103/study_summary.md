maximum accessable memory pointer depend on size of address bus.
3-bit address buss wil give me only 8 memory location. 
I can't access the 9th one with 3-bit address bus

**8086**  
20-bit address bus will allow up to  
2^20 = 1024 * 1024 = 1K * 1K = 1M
memory places.  
So, maximum memory of 8086 is only 1MB.

each location stores 1 byte (8bits) data.

if word size is `8-bit`,

| Address Bus | Memory |
| ----------- | ------ |
| 2 bit       | 4B     | 
| 6 bit       | 64B    | 
| 12 bit      | 4KB    | 
| 16 bit      | 64KB   | 
| 20 bit      | 1MB    | 
| 30 bit      | 1GB    | 
| 32 bit      | 4GB    | 

8086's memory addresses
```sh
0000 0000 0000 0000 0000 = 00000H,
0000 0000 0000 0000 0001 = 00001H,
0000 0000 0000 0000 0010 = 00002H,
..
.
..
1111 1111 1111 1111 1101 = FFFFDH,
1111 1111 1111 1111 1110 = FFFFEH,
1111 1111 1111 1111 1111 = FFFFFH
```

each location holds 1 byte of data  
```sh
0000 0000 = 00H
.
1111 1111 = FFH
```

Let's say data = `34EF`  
now each memory location can only hold 2 hexadecimal digits (8 bit total)  

We need to split the data into parts, each of 2 digits: 
```sh
34EF -> 34, EF
```

rule (little endian) is to put the lower bytes to lower address.  

| Memory Address | Data |
| -------------- | ---- |
| 00000H         | EF   |
| 00001H         | 34   |


Question: How do I know exacly which two or more cells make up my full data? I have to keep record, don't I?
