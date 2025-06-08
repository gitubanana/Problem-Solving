program Hello;
var
    canCnt, chipInCan : integer;
begin
    Read(canCnt, chipInCan);
    Write(chipInCan + 1, ' ', chipInCan * canCnt + 1);
end.
