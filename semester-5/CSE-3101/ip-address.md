
# Internet Protocol Address

## IP address classes
IPv4 is `32-bit` number divided in 4 `8-bit` group of binary.


| Class | Start IP  | End IP          | Start Octate | End Octate   | Networks   | Net Bits | Host Bits |
| ----- | --------- | --------------- | ------------ | ----------   | ---------- | -------- | --------: |
| A     | 0.0.0.0   | 127.255.255.255 | 00000000 0   | 01111111 127 | 128-2      | 8        | 8+8+8     |
| B     | 128.0.0.0 | 191.255.255.255 | 10000000 128 | 10111111 191 | 64+255     | 8+8      | 8+8       |
| C     | 192.0.0.0 | 223.255.255.255 | 11000000 192 | 11011111 223 | 32+255+255 | 8+8+8    | 8         |
| D     | 224.0.0.0 | 239.255.255.255 | 11100000 224 | 11101111 239 | 16         | _        | _         |
| E     | 240.0.0.0 | 255.255.255.255 | 11110000 240 | 11110111 247 | 8          | _        | _         |


In each class, some specific bits are constant in the first octate.

| Class | Const | Variable |
| ----- | ----- | -------: |
| A     | 0     | xxxxxxx  |
| B     | 10    | xxxxxx   |
| C     | 110   | xxxxx    |
| D     | 1110  | xxxx     |
| E     | 11110 | xxx      |


This was the perfect sequence in my mind.  
But, no. Class `[E]` has the rest of the range (240 to 255)


| Class | Starting IP | Ending IP       | Start Octate | End Octate   | Hosts |
| ----- | ----------- | ---------       | ------------ | ----------   | ----- |
| E     | 240.0.0.0   | 255.255.255.255 | 11110000 240 | 11111111 255 | 16     |


Ignore `[E]`. We don't use that.

## Fucking truth
None of the set of octate either for network address or host address,  
can be all `0`s or `1`s.  

What I mean is, 
For a class `A` IPv4 address, these are invalid:

| Net Bits | Host Bits                  |
| -------- | -------------------------- |
| 00000000 | 00000000 00000000 00000000 |
| 11111111 | 11111111 11111111 11111111 |


and, these are invalid:

| Net Bits | Host Bits                  |
| -------- | -------------------------- |
| 00000001 | 00000001 00000000 00000000 |
| 01111111 | 01111111 11111111 11111111 |


## Reservations
`0.0.0.0` ->  For I don't know what
`255.255.255.255` ->  Broadcast

## Actual available IP ranges

| Class | Start IP  | End IP          | Networks   | Hosts    |
| ----- | --------- | --------------- | ---------- | -------- |
| A     | 1.0.0.1   | 126.255.255.254 | 126        | 2^24 - 2 |
| B     | 128.0.0.1 | 191.255.255.254 | 64x256     | 2^16 - 2 |
| C     | 192.0.0.1 | 223.255.255.254 | 32x256x256 | 2^8 - 2  |
| D     | 224.0.0.0 | 239.255.255.255 | _          | _        |
| E     | 240.0.0.0 | 255.255.255.255 | _          | _        |



