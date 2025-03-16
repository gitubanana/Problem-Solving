program Hello;
var
    pointerCnt, i: integer;
    type_, star: string;
begin
    Read(pointerCnt);
    Writeln('int a;');
    Writeln('int *ptr = &a;');

    star := '**';
    for i := 2 to pointerCnt do
    begin
        Write('int ', star, 'ptr', i, ' = &ptr');
        if i <> 2 then
        begin
            Write(i - 1);
        end;
        Writeln(';');
        star := star + '*';
    end;
end.
