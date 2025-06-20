program Hello;
var
    i, recipient, peopleCnt : integer;
    senders : array [1..20000] of integer;
begin
    Read(peopleCnt);
    for i := 1 to peopleCnt do
    begin
        Read(recipient);
        senders[recipient] := i;
    end;

    for i := 1 to peopleCnt do
    begin
        Writeln(senders[i]);
    end;
end.
