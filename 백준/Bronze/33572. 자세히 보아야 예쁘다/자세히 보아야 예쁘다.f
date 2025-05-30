Program Hello
    implicit none
    integer :: i, friendCnt
    integer(kind = 8) :: maxTime, sumTime = 0
    integer(kind = 8), dimension(:), allocatable :: arr

    Read(*,*) friendCnt, maxTime
    allocate(arr(friendCnt))
    Read(*,*) arr

    do i = 1, friendCnt
        sumTime = sumTime + arr(i) - 1
        if (sumTime .GE. maxTime) then
            Print '(a4)', 'DIMI'
            stop
        end if
    end do
    Print '(a3)', 'OUT'
End Program Hello
