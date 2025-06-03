Program Hello
    implicit none
    integer :: y, x, winCnt, sameCnt
    integer, dimension(:), allocatable :: mine, opponent

    allocate(mine(6))
    allocate(opponent(6))
    Read(*,*) mine
    Read(*,*) opponent

    winCnt = 0
    sameCnt = 0
    do y = 1, 6
        do x = 1, 6
            if (mine(y) .GT. opponent(x)) then
                winCnt = winCnt + 1
            elseif (mine(y) .EQ. opponent(x)) then
                sameCnt = sameCnt + 1
            endif
        end do
    end do

    Print '(f7.5)', winCnt / (36.0 - sameCnt)
End Program Hello