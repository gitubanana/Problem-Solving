-- reference : https://www.acmicpc.net/source/87084806 (wlaud)

procedure gnat.io.a is
  num, ans : integer;
begin
  Get(num);
 
  ans := 1;
  for divisor in 2 .. num loop
    if num mod divisor = 0 then
      ans := ans + divisor;
    end if;
  end loop;

  Put(ans);
end;
