with Ada.Long_Long_Integer_Text_IO;

procedure gnat.io.a is
    use Ada.Long_Long_Integer_Text_IO;
    number: Long_Long_Integer;
begin
    Get(number);

    case number is
		when -2**15..2**15-1 => Put("short");
		when -2**31..-2**15-1 => Put("int");
		when 2**15..2**31-1 => Put("int");
		when others => Put("long long");
	end case;
end;
