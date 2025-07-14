func isValid(_ s: String) -> Bool {
    guard s.count % 2 == 0 else { return false }

    var bracketStack: [Character] = []
    for c in s {
        switch c {
        case "(":
            bracketStack.append(")")
        case "{":
            bracketStack.append("}")
        case "[":
            bracketStack.append("]")
        default:
            if bracketStack.isEmpty || bracketStack.removeLast() != c {
                return false
            }
        }
    }
    return bracketStack.isEmpty
}
var s = "()" 
print(isValid(s)) // true 
s = "({)}" 
print(isValid(s)) // false 
