
## Benefit

| STEP-1 | STEP-2 | STEP-3 | STEP-4 | STEP-5 | STEP-6 | STEP-7 | STEP-8 | STEP-9 |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| Fetch1 | Dcode1 | Exec1  | Fetch2 | Dcode2 | Exec2  | Fetch3 | Dcode3 | Exec3  |

Total cycle = K * N = 3 * 3 -> 9
K = Number of stages
N = Number of instructions

| STEP-1 | STEP-2 | STEP-3 | STEP-4 | STEP-5 | STEP-6 | STEP-7 | STEP-8 | STEP-9 |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| Fetch1 | Dcode1 | Exec1  | Exec2  | Exec3  |        |        |        |        |
|        | Fetch2 | Dcode2 | Dcode3 |        |        |        |        |        |
|        |        | Fetch3 |        |        |        |        |        |        |

Total cycle = K + (N - 1) = 3 + (3 - 1) -> 5
K = Number of stages
N = Number of instructions

## Hazards

1. [Control Hazard](#control-hazard)
2. [Data Dependency](#data-dependency)
3. [Structural Hazard](#structural-hazard)

### Control Hazard

Normally programs runs in sequential manner. So we assume that after executing instruction-1, we will execute instruction-2, and with pipeline, we fetch instruction-2 while executing instruction-1.

The hazard arises when instruction-1 says to make a jump and and execute instruction-8 afterwards. It could be done with if condition, loop, function calls. Basically, a **branch** in the program flow creates a pipeline bubble (empty space).

| STEP-1 | STEP-2     | STEP-3     | STEP-4  | STEP-5      | STEP-6     | STEP-7 | STEP-8 | STEP-9 |
| ------ | ---------- | ---------- | ------- | ----------- | ---------- | ------ | ------ | ------ |
| Fetch1 | Dcode1     | Fetch8     | Decode8 | Exec8       | Exec9      | Fetch3 | Dcode3 | Exec3  |
|        | ~~Fetch2~~ | ==BUBBLE== | Fetch9  | Dcode9      | ==BUBBLE== |        | Fetch4 | Dcode4 |
|        |            |            |         | ~~Fetch10~~ |            |        |        | Fetch5 |

Pipe-lining assumes that program will go in sequential manner. But, if there is a branch all the instructions that have been fetched or decoded in the sequential manner have to be discarded.

#### Solution
Branch prediction.


### Data Dependency

The destination of the first instruction can't be the source of the second instruction. If it happens, fucked up.

#### Solution
No Operation -> NOP instruction.

### Structural Hazard

Instruction and data on the same memory and reaches to processor through the same data buss.

#### Solution
RISC architecture that has so many registers. 
Harvard architecture.