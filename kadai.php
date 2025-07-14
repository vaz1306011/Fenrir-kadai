<?php
function isValid($s)
{
    $length = strlen($s);
    if ($length % 2 != 0) return false;
    $bracketStack = [];
    for ($i = 0; $i < $length; $i++) {
        switch ($s[$i]) {
            case '(':
                array_push($bracketStack, ')');
                break;
            case '{':
                array_push($bracketStack, '}');
                break;
            case '[':
                array_push($bracketStack, ']');
                break;
            default:
                if (array_pop($bracketStack) != $s[$i]) {
                    return false;
                }
                break;
        }
    }
    return empty($bracketStack);
}
$s = '()';
var_dump(isValid($s)); // true
$s = '({)}';
var_dump(isValid($s)); // false
