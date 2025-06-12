procedure gnat.io.a is
    average, hospitalization : Integer;
begin
    Get(average);
    Get(hospitalization);

    if hospitalization > 30 then
        Put("Red");
    elsif average <= 50 and hospitalization <= 10 then
        Put("White");
    else
        Put("Yellow");
    end if;
end;
