Program Hello
    implicit none
    integer :: t, testCnt
    integer :: length

    Read(*,*) testCnt
    do t = 1, testCnt
        Read(*, *) length
        Print '(i0)', countSquares(length)
    end do

contains
    function countSquares(length) result(cnt)
        integer :: length
        integer :: l, cnt

        cnt = 1
        do l = 2, length
            cnt = cnt + l**2
        end do
    end function countSquares
End Program Hello