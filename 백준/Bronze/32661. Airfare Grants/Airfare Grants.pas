program Hello;
Uses math;

var
    flightCnt : integer;
    cost, maxCost, minCost : LongInt;
begin
    Readln(flightCnt);

    maxCost := 0;
    minCost := 100000;
    repeat
        Readln(cost);
        maxCost := max(maxCost, cost);
        minCost := min(minCost, cost);
        flightCnt := flightCnt - 1;
    until flightCnt = 0;

    cost := minCost - maxCost div 2;
    if cost <= 0 then
        Writeln(0)
    else
        Writeln(cost);
end.
