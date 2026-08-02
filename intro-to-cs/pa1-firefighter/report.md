# Drone Mission Simulation - Algorithm Report

## 1. Introduction

This report documents the design and implementation of the `firefighter` algorithm for simulating a drone mission to investigate and extinguish wildfires. The algorithm processes a sequence of movement instructions while enforcing constraints related to battery life, radar coverage, and safe return to base.

## 2. Algorithm Specification

### 2.1 Require
- The drone starts at base coordinates `(x₀, y₀)` pointing north.
- Target coordinates `(x₁, y₁)` represent the fire location.
- Battery level must be non-negative interger.
- Radar distance must be non-negative interger.
- Plan string must contain only characters 'L', 'R', and 'S'.
- All input parameters must be valid and properly initialized.

### 2.2 Ensure
- Returns a string in format `"0.plan.return"` if mission is successful.
- Returns a string in format `"1.prefix.return"` if mission fails.
- The return path is always the exact reverse of the forward path taken ,with left/right turns logically inverted.
- Memory allocated during execution is properly managed and freed.

### 2.3 Invariants
- Drone direction is always one of: 0 (North), 1 (East), 2 (South), 3 (West).
- Battery consumption equals the number of executed instructions.
- Drone position is always within radar coverage during safe operation.
- The prefix represents the longest safe subsequence of the original plan that respects battery and radar constranints.

## 3. Implementation Details

### 3.1 Core Functions

#### `execute( char command , int direction , int position[2] )`
**Purpose:** Processes individual movement commands and updates drone state.
- **Variables:**
    - `command`: Single character instruction (`'L'`, `'R'`, `'S'`). 
    - `direction`: Pointer to current facing direction.
    - `position`: Pointer to current coordinates.
- **Implementation:** Uses modular arithmetic for direction changes and coordinate updates based on current orientation. Movement vectors are defineed as arrays `row[]` and `col[]` for efiiciency.

#### `is_in_radius( int dis , int x , int y )`
**Purpose:** Verifies if current position is within radar coverage
- **Variables:**
    - `dis`: Radar coverage radius.
    - `x`: Horizontal coordinates of the current position.
    - `y`: Vertical coordinates of the current position.
- **Implementation:** Uses squared distance comparison to avoid floating-point operations: `dis² ≥ x² + y²`.

#### `reverse( arr( char ) path )`
**Purpose:** Generates return path by reversing forward instructions.
- **Variables:**
    - `path`: The path from base to the current position.
- **Implementation:** Let `'L'` becomes `'R'`, `'R'` becomes `'L'` and `'S'` remains unchanged.

#### `firefighter( int base[2] , int tar[2] , int bat , int dis , arr( char ) plan )`
**Purpose:** Main algorithm implementing the drone mission logic.
- **Variables:**
    - `base`: `base[0]` and `base[1]` repersent the horizontal and vertical coordinates of base respectively.
    - `tar`: `tar[0]` and `tar[1]` repersent the horizontal and vertical coordinates of target respectively.
    - `bat`: Battery life in units.
    - `dis`: Radar converage radius.
    - `plan`: Planned route as a string of 'L', 'R' and 'S'.
- **Implementation:** Iterates through each plan instructions, maintaining state and checking constraints after each step. Returns formatted result string.

### 3.2 Key Design Decisions

#### 3.2.1 Direction Representation
```c
//For the convinient of processing, we define :
//0 -> N ; 1 -> E ; 2 -> S ; 3 -> W
```
This representation allows simple modulo arithmetic for direction changes:
- Left turn: `direction = ( direction + 3 ) % 4`
- Right turn: `direction = ( direction + 1 ) % 4`

#### 3.2.2 State Preservation
The algorithm maintains previous state before each move:
```c
int pre_dir = dir , pre_pos[2] = { pos[0] , pos[1] } ;
```
This enables immediate rollback when constraints are violated.

#### 3.2.3 Battery Management
Battery constraint is checked using:
```c
if ( bat_used * 2 + 2 > bat )
```
This ensures the drone always retains enough power to return to base.

## 4. Execution Trace Example

### Input Scenario:
Consider the scenario:
```bash
./firefighter 0 0 2 2 10 6 SSRSSSLSS
```
- Base: (0, 0)
- Target: (2, 2) 
- Battery: 10
- Radar: 5
- Plan: SSRSSSLSS

### Execution Steps:

1. **Initial State**
   - Position: (0, 0), Direction: North, Battery used: 0

2. **Step 1: 'S'** → Move North
   - Position: (0, 1), Battery used: 1
   - Within radar: ✓ (√(0²+1²)=1 ≤ 6)
   - Battery check: 1×2+2=4 ≤ 10 ✓

3. **Step 2: 'S'** → Move North  
   - Position: (0, 2), Battery used: 2
   - Within radar: ✓ (√(0²+2²)=2 ≤ 6)
   - Battery check: 2×2+2=6 ≤ 10 ✓

4. **Step 3: 'R'** → Turn Right (now facing East)
   - Position: (0, 2), Battery used: 3
   - Direction: East
   - Battery check: 3×2+2=8 ≤ 10 ✓

5. **Step 4: 'S'** → Move East
   - Position: (1, 2), Battery used: 4
   - Within radar: ✓ (√(1²+2²)=√5≈2.24 ≤ 6)
   - Battery check: 4×2+2=10 ≤ 10 ✓

6. **Step 5: 'S'** → Move East
   - Position: (2, 2), Battery used: 5
   - **Target reached!** Continue mission...
   - Within radar: ✓ (√(2²+2²)=√8≈2.83 ≤ 6)
   - Battery check: 5×2+2=12 > 10 ✗ → **Mission fails**
   - Rollback to position (1, 2), battery used: 4


### Output: 
```bash
1.SSRS.RRSLSS
```

## 5. Constraint Enforcement

### 5.1 Battery Constraints
- **Forward Planning:** Each instruction consumes 1 battery unit.
- **Return Assurance:** Ensures `battery_used × 2 + 2 ≤ total_battery`.
- **Early Termination:** Stops execution when return becomes impossible.
- **State Rollback:** On battery violation, returns to last safe state.

### 5.2 Radar Coverage
- **Continuous Monitoring:** Position checked after every move using `distance² ≥ x² + y²`..
- **Immediate Rollback:** Violation triggers instant mission abort.
- **Efficient Calculation:** Avoids square root operations by comparing squared distances.

### 5.3 Direction Management
- **Consistent Representation:** Numerical encoding for computational efficiency.
- **Deterministic Changes:** Modular arithmetic ensures predictable behavior.
- **State Synchronization:** Direction changes affect subsequent movements.

### 5.4 Return Path Generation
- **Exact Reversal:** Return path mirrors forward path exactly.
- **Direction Inversion:** Left/right turns are logically reversed.
- **Path Integrity:** Forward movements remain unchanged in return.

## 6. Conclusion

The implemented algorithm successfully addresses all requirements of the drone mission simulation. Key strengths include:

1. **Robust Constraint Enforcement:** Battery and radar limits are strictly maintained with safety margins.
2. **Efficient State Management:** Minimal computational overhead through integer arithmetic and precomputed vectors.
3. **Memory Safety:** Proper allocation and deallocation practices prevent leaks.
4. **Deterministic Behavior:** Consistent outputs for given inputs with clear failure modes.
5. **Modular Design:** Separated functions for movement, validation, and path reversal enhance readability.

The design prioritizes safety and reliability, ensuring the drone never enters an unrecoverable state while maximizing data collection within operational constraints. The algorithm correctly handles edge cases including immediate failure, exact battery limits, and boundary positions.