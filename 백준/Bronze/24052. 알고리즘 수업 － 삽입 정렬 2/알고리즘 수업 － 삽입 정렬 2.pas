program Hello;
type
    vector = array [1..10000] of Longint;
var
    arr : vector;
    i, size, swapCnt: Longint;

procedure insertionSort;
var start, cmp : Longint;
begin
    start := 2;
    while start <= size do
    begin
        cmp := arr[start];
        i := start - 1;

        while (i >= 1) and (arr[i] > cmp) do
        begin
            arr[i + 1] := arr[i];
            swapCnt := swapCnt - 1;
            if swapCnt = 0 then
                exit();

            i := i - 1;
        end;

        if i + 1 <> start then
        begin
            arr[i + 1] := cmp;
            swapCnt := swapCnt - 1;
            if swapCnt = 0 then
                exit();
        end;

        start := start + 1;
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

    insertionSort;
    if swapCnt = 0 then
        printVector
    else
        Writeln('-1');
end.
