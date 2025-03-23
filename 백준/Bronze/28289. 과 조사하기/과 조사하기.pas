program Hello;
var
    s, e, a, o: integer;
    studentCnt, grade, class_, num : integer;
begin
    Readln(studentCnt);

    s := 0;
    e := 0;
    a := 0;
    o := 0;
    while studentCnt > 0 do
    begin
        Readln(grade, class_, num);
        if grade = 1 then
        begin
            o := o + 1;
        end
        else
        begin
            if (class_ = 1) or (class_ = 2) then
                s := s + 1
            else if class_ = 3 then
                e := e + 1
            else
                a := a + 1;
        end;

        studentCnt := studentCnt - 1;
    end;

    Writeln(s);
    Writeln(e);
    Writeln(a);
    Writeln(o);
end.
