const isValid = (s) => {
  if (s.length % 2 != 0) return false;
  var bracketStack = [];
  for (const c of s) {
    switch (c) {
      case "(":
        bracketStack.push(")");
        break;
      case "{":
        bracketStack.push("}");
        break;
      case "[":
        bracketStack.push("]");
        break;
      default:
        if (!bracketStack.length || bracketStack.pop() != c) return false;
        break;
    }
  }
  return !bracketStack.length;
};
let s = "()";
console.log(isValid(s)); // true
s = "({)}";
console.log(isValid(s)); // false
