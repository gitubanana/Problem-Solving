Program Hello
    implicit none
    integer :: pushCnt
    integer :: ans, start, end_

    Read(*, *) pushCnt
    if (mod(pushCnt, 2) .EQ. 1) then
        Print '(a)', 'still running'
        stop
    endif

    ans = 0
    do pushCnt=pushCnt, 2, -2
        Read(*, *) start, end_
        ans = ans + (end_ - start)
    end do

    Print '(i0)', ans
End Program Hello