program Hello;
var
    line : ansistring;
    lineCnt : integer;
    sCnt, tCnt : integer;

procedure countSandT;
var i : integer;
begin
    for i := 1 to length(line) do
    begin
        if (line[i] in ['s', 'S']) then
            sCnt := sCnt + 1
        else if (line[i] in ['t', 'T']) then
            tCnt := tCnt + 1;
    end;
end;

begin
    Readln(lineCnt);

    sCnt := 0;
    tCnt := 0;
    repeat
        Readln(line);
        countSandT();
        lineCnt := lineCnt - 1;
    until lineCnt <> 0;

    if (sCnt >= tCnt) then
        Writeln('French')
    else
        Writeln('English');
end.
