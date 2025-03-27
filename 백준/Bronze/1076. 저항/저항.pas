program Hello;
type
    resisters = array [char, char] of integer;
var
    i, num : integer;
    color : string;
    table : resisters;
procedure initResisters;
begin
    table['b', 'k'] := 0; { black }
    table['b', 'n'] := 1; { brown }
    table['r', 'd'] := 2; { red }
    table['o', 'e'] := 3; { orange }
    table['y', 'w'] := 4; { yellow }
    table['g', 'n'] := 5; { green }
    table['b', 'e'] := 6; { blue }
    table['v', 't'] := 7; { violet }
    table['g', 'y'] := 8; { grey }
    table['w', 'e'] := 9; { white }
end;
function getOhmValue(color: string) : integer;
begin
    getOhmValue := table[color[1], color[length(color)]];
end;
begin
    initResisters;

    Readln(color);
    num := getOhmValue(color);

    Readln(color);
    num := num * 10 + getOhmValue(color);

    Write(num);
    if num <> 0 then
    begin
        Readln(color);
        for i := 1 to getOhmValue(color) do
            Write('0');
    end;
end.
