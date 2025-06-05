Program Hello
    implicit none
    integer :: i, diceCnt
    integer, dimension(:), allocatable :: dices, cnt

    Read(*,*) diceCnt
    allocate(dices(diceCnt))
    Read(*, *) dices

    allocate(cnt(64))
    do i = 1, 64
        cnt(i) = 0
    end do

    call countAllNumbers(dices, cnt, 0, 1)
    Print '(f9.6)', 1.0 * sumOfWeightedDice(cnt) / countPossibleThrows(dices)

    deallocate(dices)
    deallocate(cnt)

contains
    recursive subroutine countAllNumbers(dices, cnt, cur, depth)
        integer :: cur, depth, i
        integer, dimension(:), allocatable :: dices, cnt

        if (depth .GT. size(dices)) then
            cnt(cur) = cnt(cur) + 1
            return
        endif

        do i = 1, dices(depth)
            call countAllNumbers(dices, cnt, cur + i, depth + 1)
        end do
    end subroutine countAllNumbers

    function sumOfWeightedDice(cnt) result(ret)
        integer :: i, ret
        integer, dimension(:), allocatable :: cnt

        ret = 0
        do i = 1, size(cnt)
            ret = ret + i * cnt(i)
        end do
    end function sumOfWeightedDice

    function countPossibleThrows(dices) result(ret)
        integer :: i, ret
        integer, dimension(:), allocatable :: dices

        ret = 1
        do i = 1, size(dices)
            ret = ret * dices(i)
        end do
    end function countPossibleThrows

End Program Hello