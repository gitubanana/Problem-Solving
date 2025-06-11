with Ada.Strings.Unbounded;
with Ada.Text_IO.Unbounded_IO; use Ada.Text_IO.Unbounded_IO;

procedure gnat.io.a is
    use Ada.Strings.Unbounded;
    limit, speed, diff: integer;
    message : Unbounded_String;
begin
    Get(limit);
    Get(speed);

    diff := speed - limit;
    case diff is
		when -2147483648..0 => message := To_Unbounded_String("Congratulations, you are within the speed limit!");
		when 1..20 => message := To_Unbounded_String("You are speeding and your fine is $100.");
		when 21..30 => message := To_Unbounded_String("You are speeding and your fine is $270.");
		when others => message := To_Unbounded_String("You are speeding and your fine is $500.");
	end case;

    Put(message);
end;
