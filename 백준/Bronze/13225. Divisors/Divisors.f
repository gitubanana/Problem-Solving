Program Hello
    implicit none
    integer :: t, testCnt
    integer :: num

    Read(*,*) testCnt
    do t = 1, testCnt
        Read(*,*) num
        Print '(i0 a i0)', num, ' ', countDivisors(num)
    end do

contains
    function countDivisors(num) result(cnt)
        integer :: num
        integer :: i, cnt

        i = 1
        cnt = 0
        do while (i**2 <= num)
            if (MOD(num, i) .EQ. 0) then
                cnt = cnt + 2
                if (i**2 .EQ. num) then
                    cnt = cnt - 1
                    return
                endif
            endif

            i = i + 1
        end do
    end function countDivisors
End Program Hello