program Hello;
var
    testId, testCnt: integer;
    cypherText: ansistring;
procedure decrypt;
var i, len: integer;
begin
    len := length(cypherText);
    for i := 1 to len do
        cypherText[i] := chr(65 + (ord(cypherText[i]) - 64) mod 26);
end;
begin
    Readln(testCnt);
    for testId := 1 to testCnt do
    begin
        Readln(cypherText);

        decrypt();
        Write('String #');
        Writeln(testId);
        Writeln(cypherText);
        Writeln();
    end;
end.
