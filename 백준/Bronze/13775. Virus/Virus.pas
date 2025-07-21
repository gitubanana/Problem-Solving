program Hello;
var
    key : integer;
    cypherText : ansistring;

procedure decrypt;
var
    i, len : integer;
begin
    len := Length(cypherText);
    for i := 1 to len do
    begin
        if not ((Ord('a') <= Ord(cypherText[i])) and (Ord(cypherText[i]) <= Ord('z'))) then
            continue;

        cypherText[i] := Chr(97 + (Ord(cypherText[i]) - 97 + 26 - key) Mod 26);
        key := key + 1;
        if key = 26 then
            key := 1;
    end;
end;

begin
    Readln(key);
    Readln(cypherText);

    decrypt;
    Writeln(cypherText);
end.
