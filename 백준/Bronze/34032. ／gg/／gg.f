Program Hello
    implicit none
    character (len=500001) :: ggList
    integer :: length, half, i, ggCnt = 0

    Read *, length
    Read *, ggList
    do i=1, length
        if (ggList(i:i) .EQ. 'O') then
            ggCnt = ggCnt + 1
        endif
    end do

    half = length / 2;
    if (mod(length, 2) .EQ. 1) then
        half = half + 1
    endif

    if (ggCnt .GE. half) then
        Print '(a)', 'Yes'
    else
        Print '(a)', 'No'
    endif

End Program Hello