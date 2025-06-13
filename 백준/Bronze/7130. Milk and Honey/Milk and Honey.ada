procedure gnat.io.a is
    milkHappiness, honeyHappiness: integer;
    fieldCnt, cow, bee : integer;
    maxHappiness : integer := 0;
begin
    Get(milkHappiness);
    Get(honeyHappiness);
    Get(fieldCnt);

    for i in 1..fieldCnt loop
        Get(cow);
        Get(bee);

        cow := cow * milkHappiness;
        bee := bee * honeyHappiness;
        maxHappiness := maxHappiness + (if cow > bee then cow else bee);
    end loop;

    Put(maxHappiness);
end;
