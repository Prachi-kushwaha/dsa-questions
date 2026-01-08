# Generate All Valid Parentheses

## Approach
- Backtracking with constraints
- Maintain count of left and right brackets
- Build the string incrementally and undo choices after recursion

An alternative approach is to pass the string by value and avoid explicit
backtracking (`pop_back()`), but that creates a new copy at each recursive call.
This increases space usage significantly, so in-place backtracking is preferred.

## Key Constraints
- Number of opening brackets `(` cannot exceed `n`
- Number of closing brackets `)` cannot exceed number of opening brackets
- Conditions:
  - `left < n`
  - `right < left`

## Complexity
- Time: **O(2ⁿ)** (size of recursion tree)
- Space: **O(n)** recursion depth (excluding output)

## Insight
Applying constraints early prunes invalid branches and avoids generating
incorrect parenthesis sequences.
