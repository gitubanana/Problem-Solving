procedure gnat.io.a is
    a, b, c : integer;
begin
    Get(a);
    Get(b);
    Get(c);

    Put(b / a * 3 * c);
end;