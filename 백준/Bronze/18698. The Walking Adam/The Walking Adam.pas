program HelloNakoo;
var
    testCount: integer;
    str: string;

function countWalk(): integer;
var i: integer;
begin
    countWalk := 0;
    for i := 1 to length(str) do
    begin
        if str[i] = 'D' then
        begin
            break;
        end;
        countWalk := countWalk + 1;
    end;
end;

begin
    Readln(testCount);
    while testCount > 0 do
    begin
        Readln(str);
        Writeln(countWalk());
        testCount := testCount - 1;
    end;
end.
