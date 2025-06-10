procedure gnat.io.a is
    dayCnt : integer;
    dailyChange : integer;
    price : integer;
begin
    Get(dayCnt);

    price := 0;
    for i in 1 .. dayCnt loop
        Get(dailyChange);
        price := price + dailyChange;
    end loop;

    Put(price);
end;