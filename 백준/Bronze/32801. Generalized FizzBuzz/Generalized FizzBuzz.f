Program Hello
    implicit none
    integer :: n, fizz, buzz
    integer :: i, fCnt, bCnt, fbCnt

    Read(*, *) n, fizz, buzz

    fCnt = n / fizz
    bCnt = n / buzz 

    fbCnt = 0
    do i=1,n
        if ((MOD(i, fizz) .EQ. 0) .and. (MOD(i, buzz) .EQ. 0)) then
            fbCnt = fbCnt + 1
        endif
    end do

    Print '(i0 a i0 a i0)', fCnt - fbCnt, ' ', bCnt - fbCnt, ' ', fbCnt
End Program Hello