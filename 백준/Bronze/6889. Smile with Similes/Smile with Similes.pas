program Hello;
type
    t_arr = array[1..5] of ansistring;
var
    y, x, ySize, xSize: integer;
    adjectives, nouns : t_arr;
begin
    Readln(ySize);
    Readln(xSize);
    for y := 1 to ySize do
        Readln(adjectives[y]);

    for x := 1 to xSize do
        Readln(nouns[x]);

    for y := 1 to ySize do
        for x := 1 to xSize do
            Writeln(adjectives[y], ' as ', nouns[x]);
end.
