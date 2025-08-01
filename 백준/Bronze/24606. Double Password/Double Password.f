Program Hello
    implicit none
    integer :: i, diff
    character(len=5) a, b

    Read(*, *) a
    Read(*, *) b

    diff = 0
    do i=1,4
        if (a(i:i) .NE. b(i:i)) then
            diff = diff + 1
        endif
    end do

    Print '(i0)', 2**diff
End Program Hello