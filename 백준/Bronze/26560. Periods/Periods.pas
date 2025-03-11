program Hello;
var
    lineCount: integer;
    str: string;
procedure putPeriod();
begin
    if str[length(str)] <> '.' then
    begin
        str := str + '.';
    end;
end;

begin
    Readln(lineCount);
    while lineCount > 0 do
    begin
        Readln(str);
        putPeriod();
        Writeln(str);
        lineCount := lineCount - 1;
    end;
end.
