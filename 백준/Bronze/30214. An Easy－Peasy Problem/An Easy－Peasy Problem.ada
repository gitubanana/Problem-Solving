procedure gnat.io.a is
    firstHalf, lastHalf : integer;
begin
    Get(firstHalf);
    Get(lastHalf);

    if (firstHalf * 2 >= lastHalf) then
        Put('E');
    else
        Put('H');
    end if;
end;