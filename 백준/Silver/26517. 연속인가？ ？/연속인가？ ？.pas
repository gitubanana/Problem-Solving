program Hello;
var k, a, b, c, d, left, right : Int64;
begin
    Readln(k);
    Readln(a, b, c, d);

    left := a * k + b;
    right := c * k + d;
    if (left = right) then
        Writeln('Yes ', left)
    else
        Writeln('No');
end.
