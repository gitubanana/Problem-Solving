Program Hello
    integer :: n, fixedRaise, doubleRaise
    ! zero -> 0, negative -> 1, positive -> 2
    integer :: ans = 0

    Read(*, *) n, fixedRaise
    do n=n, 1, -1
        Read(*, *) doubleRaise
        if (fixedRaise .GT. doubleRaise) then
            ans = ans - 1
        elseif (fixedRaise .LT. doubleRaise) then
            ans = ans + 1
        endif
    end do

    if (ans .LT. 0) then
        ans = 1
    elseif (ans .GT. 0) then
        ans = 2
    endif

    Print '(i0)', ans
End Program Hello