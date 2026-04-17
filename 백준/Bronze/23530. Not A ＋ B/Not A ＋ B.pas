program Hello;
var
    testCnt : integer;
    a, b : integer;
begin
    Readln(testCnt);
    repeat
        Readln(a, b);
        Writeln((a + b) mod 50 + 1);
        testCnt := testCnt - 1;
    until testCnt = 0;
end.
