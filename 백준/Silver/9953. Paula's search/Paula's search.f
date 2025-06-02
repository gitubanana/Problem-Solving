Program Hello
    implicit none
    integer :: dest, searchCnt

    do
        Read(*,*) dest
        if (dest .EQ. 0) then
            exit
        endif

        call binarySearch(dest, searchCnt)
        Print '(i0)', searchCnt
    end do

contains
    subroutine binarySearch(dest, searchCnt)
        integer, intent(in) :: dest
        integer, intent(out) :: searchCnt
        integer :: left, right, mid, cmp, isOdd

        if (AND(dest, 1) .EQ. 1) then
            isOdd = 1
            searchCnt = 2
        else
            isOdd = 0
            searchCnt = 1
        endif

        left = 1
        right = 50
        do while (left .LE. right)
            mid = (left + right) / 2
            cmp = mid * 2 - isOdd

            if (cmp .EQ. dest) then
                return
            elseif (cmp .LT. dest) then
                left = mid + 1
            else
                right = mid - 1
            endif

            searchCnt = searchCnt + 1
        end do
    end subroutine binarySearch
End Program Hello