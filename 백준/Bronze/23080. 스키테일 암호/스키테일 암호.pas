program Hello;
var
    i, len, scytaleSize: integer;
    cypherText: ansistring;
begin
    readln(scytaleSize);
    readln(cypherText);

    i := 1;
    len := length(cypherText);
    repeat
        write(cypherText[i]);
        i := i + scytaleSize;
    until i > len;
end.
