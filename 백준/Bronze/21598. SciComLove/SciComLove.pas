program Hello;
var repeatCnt : integer;
begin
    Readln(repeatCnt);
    repeat
        Writeln('SciComLove');
        repeatCnt := repeatCnt - 1;
    until repeatCnt = 0;
end.
