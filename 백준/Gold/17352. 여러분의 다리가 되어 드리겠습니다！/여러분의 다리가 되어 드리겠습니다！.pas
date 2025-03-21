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
    begin
        if x = parents[x] then
            getParent := x
        else
            getParent := getParent(parents[x]);

        parents[x] := getParent;
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
