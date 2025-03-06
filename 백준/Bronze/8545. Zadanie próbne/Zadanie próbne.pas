program FirstPascal;
    var str: string;
    function reverse(const str: string): string;
        var i, len: Integer;
        begin
          len := length(str);
          setlength(reverse, len);
          for i := 1 to len do
            reverse[i] := str[len - i + 1];
        end;
    begin
        Read(str);
        Write(reverse(str));
    end.
