program Hello;
type
    vector = array [1..10000] of Longint;
var
    arr : vector;
    i, size, swapCnt : Longint;

procedure swap(i, j : Longint);
var tmp: Longint;
begin
    tmp := arr[i];
    arr[i] := arr[j];
    arr[j] := tmp;
end;

procedure bubbleSort;
var last: Longint;
begin
    last := size - 1;
    while last >= 1 do
    begin
        for i := 0 to last do
        begin
            if arr[i] > arr[i + 1] then
            begin
                swap(i, i + 1);
                swapCnt := swapCnt - 1;
                if swapCnt = 0 then
                    exit();
            end;
        end;

        last := last - 1;
    end;
end;

procedure printVector;
begin
    for i := 1 to size do
        Write(arr[i], ' ');
end;

begin
    Read(size, swapCnt);
    for i := 1 to size do
        Read(arr[i]);

    bubbleSort;
    if swapCnt = 0 then
        printVector
    else
        Writeln('-1');
end.
