program Hello;
var
    size, shootCount: integer;
    basket: array [1..100] of integer;
procedure shoot;
    var curIdx, endIdx, num: integer;
    begin
        Read(curIdx);
        Read(endIdx);
        Read(num);
        while curIdx <= endIdx do
        begin
            basket[curIdx] := num;
            curIdx := curIdx + 1;
        end;
    end;
procedure printBaskets;
    var i: integer;
    begin
        for i := 1 to size do
        begin
            Write(basket[i], ' ');
        end;
    end;
begin
    Read(size);
    Read(shootCount);
    while shootCount > 0 do
    begin
        shoot();
        shootCount := shootCount - 1;
    end;

    printBaskets();
end.
