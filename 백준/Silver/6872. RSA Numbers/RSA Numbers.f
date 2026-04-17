Program Hello
    implicit none
    integer :: rsaNumberCnt
    integer :: start, end_, cur

    Read(*, *) start, end_

    rsaNumberCnt = 0
    do cur=start, end_
        if (isRsaNumber(cur)) then
            rsaNumberCnt = rsaNumberCnt + 1
        endif
    end do

    Print '(a,i0,a,i0,a,i0)', 'The number of RSA numbers between ', start, ' and ', end_, ' is ', rsaNumberCnt
contains
    function isRsaNumber(num) result(itIs)
        integer :: num
        logical :: itIs
        integer :: divisor, divisorCnt

        divisor = 2
        divisorCnt = 0
        do while (divisor .LT. num)
            if (mod(num, divisor) .EQ. 0) then
                divisorCnt = divisorCnt + 1
            endif
            divisor = divisor + 1
        end do

        itIs = (divisorCnt .EQ. 2)
    end function isRsaNumber
End Program Hello