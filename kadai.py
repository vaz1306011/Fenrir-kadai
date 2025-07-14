def isValid(s: str) -> bool:
    if len(s) % 2 != 0:
        return False

    bracket_map = {")": "(", "}": "{", "]": "["}
    bracket_stack = []
    for c in s:
        if c not in bracket_map:
            bracket_stack.append(c)
        else:
            if not bracket_stack or bracket_stack.pop() != bracket_map.get(c):
                return False
    return not bracket_stack


s = "()"
print(isValid(s))  # True
s = "({)}"
print(isValid(s))  # False
