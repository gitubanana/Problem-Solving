WITH WANT_TYPE AS
(
    SELECT FISH_TYPE
        FROM FISH_NAME_INFO
        WHERE FISH_NAME IN ('BASS', 'SNAPPER')
)

SELECT COUNT(*) AS FISH_COUNT
    FROM WANT_TYPE
    INNER JOIN FISH_INFO
        ON WANT_TYPE.FISH_TYPE = FISH_INFO.FISH_TYPE;
