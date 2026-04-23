<link rel="stylesheet" href="./style.css">

# Addressing modes  

1. [Immediate](#immediate)
2. [Registered](#registered)
3. [Direct](#direct)
4. [Indirect](#indirect)
    - [Reg Indirect](#reg-indirect)
    - [Reg Relative](#reg-relative)
    - [Base Indexed](#base-indexed)
    - [Base Relative Plus Indexed](#base-relative-plus-indexed)
5. [Implied](#implied)

## Immediate

Operand given in the instruction.

**Example**

```js
MOV BL, 25H;
MOV CL, 12H;
// BL <- 25H
// CL <- 12H
```

## Registered  

Operand is in a register.  
The register's name is given.

**Example**

```js
MOV BL, CL;
// BL <- data on register CL
```
## Direct

Operand is in memory.  
The address of the operand in the memory is given.

**Example**

```js
MOV BL, [2000];
MOV [3000], CL;
// BL <- data on memory address 0x2000
// memory address 0x2000 <- data in on register BL 
```
## Indirect

Operand is on memory.  
The address of the memory location is given, but not directly.  
The address is stored in a register and the register's name is given.  

### Reg indirect

Register works as a pointer and the pointer is given.

**Example**

```js
MOV BX, 5000H;
MOV CX, [BX];
```
### Reg Relative  

Pointer register and (const) data offset is given.  
Use the pointer as reference and use the offset to get related data.  

**Example**

```js
MOV BX, 5000H;      // base
MOV CX, [BX+03H];   // base + offset
```

### Base Indexed  

There is a base register and an index register.  
Together they form a new dynamic pointer.  

**Example**

```js
MOV BX, 3000H;      // base
MOV SI, 20H;        // index
MOV CX, [BX+SI];
// now we can loop incrementing SI each time.
```

### Base Relative Plus Indexed  

The total address is, base reg + offset + index

**Example**

```js
MOV BX, 3000H;          // base
MOV SI, 20H;            // index
MOV CX, [BX+SI+04H];    // base + offset + index
```

## Implied  

The instruction is defined for specific register.

**Example**

```js
STC;
// Set carry flag will only work on the carry flag register.
// Not need to explicitly address.
CLC;
// Clear the carry flag.
```
