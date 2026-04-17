program Hello;
var
    i, ans, length : integer;
    prev, cur : ansistring;
begin
    Readln(length);
    Readln(prev);
    Readln(cur);

    ans := 0;
    for i := 1 to length do
    begin
        if prev[i] <> 'C' then
            continue;

        if prev[i] = cur[i] then
            ans := ans + 1;
    end;
    Writeln(ans);
end.
