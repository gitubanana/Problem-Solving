program Hello;
var
    vCnt, e, a, b : longInt;
    parents : array [1..300000] of longInt;
procedure initParents();
    var i : longInt;
    begin
        for i := 1 to vCnt do
            parents[i] := i;
    end;
function getParent(x : longInt) : longInt;
    var p, save : longInt;
    begin
        p := x;
        while p <> parents[p] do
        begin
            p := parents[p];
        end;

        while x <> parents[x] do
        begin
            save := parents[x];
            parents[x] := p;
            x := save;
        end;

        getParent := p;
    end;
procedure group(a, b : longInt);
    begin
        parents[getParent(a)] := parents[getParent(b)];
    end;
function getOther() : longInt;
    var v : longInt;
    begin
        for v := 2 to vCnt do
            if getParent(1) <> getParent(v) then
                break;
        getOther := v;
    end;
begin
    Read(vCnt);
    initParents();
    for e := 3 to vCnt do
    begin
        Read(a, b);
        group(a, b);
    end;

    Writeln(1, ' ', getOther());
end.
