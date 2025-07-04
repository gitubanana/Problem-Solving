program Hello;
var
    size, max, cur, i : Longint;
    arr : array[1..100000] of Longint;

procedure slidingWindow;
var windowSize : Longint;
begin
    windowSize := 4;
    while (i <= size) do
    begin
        cur := cur - arr[i - windowSize] + arr[i];
        if (cur > max) then
            exit();

        i := i + 1;
    end;
end;

begin
    Readln(max);
    Readln(size);
    for i := 1 to size do
        Readln(arr[i]);

    i := 1;
    cur := 0;
    repeat
        cur := cur + arr[i];
        if cur > max then
        begin
            cur := cur - arr[i];
            break;
        end;
        i := i + 1;
    until i > 4;

    if i = 5 then
        slidingWindow;

    Writeln(i - 1);
end.
